#ifndef EXTERNAL_INTERFACE_H
#define EXTERNAL_INTERFACE_H

#include "message.h"

#include "abstract_net.h"
#include "abstract_simulator.h"

#include <mutex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <vector>

class Target {
public:
  AbstractSimulator *sim;
  uint32_t base_address;
  uint32_t size;
  std::thread *task;

  Target(AbstractSimulator *_sim, uint32_t _base_address, uint32_t _size,
         std::thread *_task)
      : sim(_sim), base_address(_base_address), size(_size), task(_task){};
};

class System {
private:
  bool running;

  void init();

  std::vector<Target *> targets;

  AbstractNet *net;

public:
  System();

  ~System();

  void run();

  void process(Message *msg);

  void shutdown();

  bool append_target(AbstractSimulator *_sim, uint32_t _base_address,
                     uint32_t _size);

  bool set_network(AbstractNet *_net);

  Target *resolve_target(uint32_t address);
};

#endif
