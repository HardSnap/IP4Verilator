#include "external_interface.h"

#include "simulator_driver.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

extern u_char *sync_mem_ptr;

ExternalInterface::ExternalInterface(SimulatorDriver *_sim) {
  sim = _sim;
  running = true;
  init_done = false;

  sync_mem_ptr[0] = 0;
  sync_mem_ptr[1] = 0;
  sync_mem_ptr[2] = 0;

  memset(buffer, 0, 12);
}

ExternalInterface::~ExternalInterface() {}

void ExternalInterface::init() {

  const char *cmd_fifo_path = "/tmp/cmd_fifo";

  const char *data_fifo_path = "/tmp/data_fifo";

  if (mkfifo(cmd_fifo_path, 0666) != 0) {
    spdlog::warn("External_interface.cpp ", 12);
    std::cout << "[Simulator::net] Failed to create cmd_fifo" << std::endl;
    // exit(-1);
  }

  if (mkfifo(data_fifo_path, 0666) != 0) {
    std::cout << "[Simulator::net] Failed to create data_fifo" << std::endl;
    // exit(-1);
  }

  cmd_fifo = open(cmd_fifo_path, O_RDONLY);
  if (fcntl(cmd_fifo, F_SETFL, O_NONBLOCK) < 0) {
    std::cout << "[Simulator::net] Failed make it non blocking" << std::endl;
    exit(2);
  }

  data_fifo = open(data_fifo_path, O_WRONLY);
  if (fcntl(data_fifo, F_SETFL, O_NONBLOCK) < 0) {
    std::cout << "[Simulator::net] Failed make it non blocking" << std::endl;
    exit(2);
  }

  std::cout << "[Simulator::net] Ready" << std::endl;

  init_done = true;
}

void ExternalInterface::run() {
  if (init_done == false) {
    init();
    init_done = true;
  }

  while (running) {

    if (has_message()) {
      process();
    }
  }
}

void ExternalInterface::input(uint32_t data, uint32_t address) {
  sim->input(data, address);
}

uint32_t ExternalInterface::output(uint32_t address) {
  return sim->output(address);
}

bool ExternalInterface::has_message() {

  if (read(cmd_fifo, buffer, sizeof(buffer)) >= 9) {
    sync_mem_ptr[0] = 0;

    // std::cout << "DATA !!!" << std::endl;

    address = *((uint32_t *)&buffer[4]);
    data_in = *((uint32_t *)&buffer[8]);
    action = buffer[0];
    return true;
  }
  return false;
}

void ExternalInterface::process() {

  switch (action) {
  case 'W': {
    input(data_in, address);
  } break;
  case 'R': {
    data_out = output(address);

    char *res = new char[5];
    res[0] = data_out >> 24;
    res[1] = data_out >> 16;
    res[2] = data_out >> 8;
    res[3] = data_out & 0xFF;
    res[4] = 0;

    while (sync_mem_ptr[1] == 1)
      ;
    sync_mem_ptr[1] = 1;

    while (write(data_fifo, res, 5) == 0)
      ;
  } break;
  default:
    break;
  }
}

void ExternalInterface::shutdown() {
  running = false;
  close(data_fifo);
  close(cmd_fifo);
}
