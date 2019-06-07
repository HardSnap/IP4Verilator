#ifndef EXTERNAL_INTERFACE_H
#define EXTERNAL_INTERFACE_H

#include "simulator_driver.h"

#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>

class ExternalInterface {
private:
  uint32_t address;
  uint32_t data_in;
  uint32_t data_out;
  char action;
  unsigned char buffer[12];
  bool init_done;
  bool running;
  SimulatorDriver *sim;
  int cmd_fifo;
  int data_fifo;

  void init();

public:
  ExternalInterface(SimulatorDriver *_sim);

  ~ExternalInterface();

  void run();

  void input(uint32_t data, uint32_t address);

  uint32_t output(uint32_t address);

  bool has_message();

  void process();

  void shutdown();
};

#endif
