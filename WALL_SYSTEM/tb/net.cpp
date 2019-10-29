#include "net.h"

#include "message.h"
#include <iostream>
#include <string>

typedef struct {
  uint8_t irq_in;
  uint8_t irq_ack;

  uint32_t address;
  uint8_t  type;
  uint32_t value;
  uint8_t  status;
}IPC_MESSAGE;

bool MKFifo::init() {
  int res;

  std::cout << "MKFIFO init" << std::endl;

  const char *sync_path = "/sync_fifo";

  // Create a shared memory object
  int sync_mem = shm_open(sync_path, O_CREAT | O_RDWR, 0644);
  if (sync_mem == -1) {
    spdlog::error("Unable to create shared memory object");
    return false;
  }

  // Set the size
  ftruncate(sync_mem, 512);

  // Map the shared memory in this process
  sync_mem_ptr =
      (u_char *)mmap(NULL, 14, PROT_READ | PROT_WRITE, MAP_SHARED, sync_mem, 0);
  if (sync_mem_ptr == MAP_FAILED) {
    spdlog::error("Unable to map shared memory to current program");
    return false;
  }

  return true;
}

bool MKFifo::shutdown() {
}

void MKFifo::send(uint32_t data) {

  IPC_MESSAGE* ipc = (IPC_MESSAGE*) sync_mem_ptr;

  ipc->value  = data;
  ipc->status = 'K';
}

Message *MKFifo::receive() {

  IPC_MESSAGE* ipc = (IPC_MESSAGE*) sync_mem_ptr;

  if(ipc->status == 'P') {

    spdlog::info("receive type={} status={} address={} value={}", ipc->type, ipc->status, ipc->address, ipc->value);

    uint32_t data_in = ipc->value;
    uint32_t address = ipc->address;
    uint8_t type = ipc->type;

    ipc->status = 'D';

    return new Message(address, data_in, type);
  } else {

    return NULL;
  }
  //spdlog::info("One packet received on cmd_fifo: address:%08x data:%08x\n", address, data_in);
  //printf("One packet received on cmd_fifo: address:%08x data:%08x\n", address, data_in);
}

void MKFifo::irq() {

  IPC_MESSAGE* ipc = (IPC_MESSAGE*) sync_mem_ptr;

  ipc->irq_in = 1;
  while(ipc->irq_in != 0);
}
