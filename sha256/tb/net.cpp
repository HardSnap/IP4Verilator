#include "net.h"

#include "message.h"
#include <iostream>
#include <string>

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
  ftruncate(sync_mem, 8);

  // Map the shared memory in this process
  sync_mem_ptr =
      (u_char *)mmap(NULL, 8, PROT_READ | PROT_WRITE, MAP_SHARED, sync_mem, 0);
  if (sync_mem_ptr == MAP_FAILED) {
    spdlog::error("Unable to map shared memory to current program");
    return false;
  }

  const char *cmd_fifo_path = "/tmp/cmd_fifo";
  const char *data_fifo_path = "/tmp/data_fifo";

  res = mkfifo(cmd_fifo_path, 0666);
  if (res != EEXIST && res != 0) {
    spdlog::error("Unable to create cmd_fifo in /tmp");
    return false;
  }

  res = mkfifo(data_fifo_path, 0666);
  if (res != EEXIST && res != 0) {
    spdlog::error("Unable to create data_fifo in /tmp");
    return false;
  }

  cmd_fifo = open(cmd_fifo_path, O_RDONLY);
  data_fifo = open(data_fifo_path, O_WRONLY);

  sync_mem_ptr[0] = 0;
  sync_mem_ptr[1] = 0;
  sync_mem_ptr[2] = 0;

  return true;
}

bool MKFifo::shutdown() {
  spdlog::info("Closing CMD and DATA FIFO");
  close(cmd_fifo);
  close(data_fifo);
  spdlog::info("Done");
}

void MKFifo::send(uint32_t data) {

  char *res = new char[5];
  res[3] = data >> 24;
  res[2] = data >> 16;
  res[1] = data >> 8;
  res[0] = data & 0xFF;
  res[4] = 0;

  while (sync_mem_ptr[1] == 1)
    ;
  sync_mem_ptr[1] = 1;

  while (write(data_fifo, res, 5) == 0)
    ;
}

Message *MKFifo::receive() {

  // PACKETS : R/W[0], ADDRESS[1:4], DATA[5:8]
  unsigned char buffer[12] = {0};

  while (read(cmd_fifo, buffer, sizeof(buffer)) <= 0)
    ;

  sync_mem_ptr[0] = 0;

  uint32_t data_in = *((uint32_t *)&buffer[4]);
  uint32_t address = *((uint32_t *)&buffer[8]);

  // spdlog::info("One packet received on cmd_fifo : %c address:%08x
  // data:%08x\n",
  //              buffer[0], address, data_in);
  // printf("One packet received on cmd_fifo : %c address:%08x data:%08x\n",
  //        buffer[0], address, data_in);

  return new Message(address, data_in, buffer[0]);
}
