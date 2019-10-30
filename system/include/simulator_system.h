#ifndef EXTERNAL_INTERFACE_H
#define EXTERNAL_INTERFACE_H

#include "message.h"

class AbstractNet;

// #include "abstract_net.h"
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
  uint32_t select_id;
  uint32_t base_address;
  uint32_t size;

  Target(uint32_t _select_id, uint32_t _base_address,
         uint32_t _size)
      : select_id(_select_id), base_address(_base_address),
        size(_size){};
};

class SimulatorSystem {
private:
  bool is_interrupt_active;

  bool running;

  void init();

  std::vector<Target *> targets;

  AbstractNet *net;

  AbstractSimulator *sim;

public:
  SimulatorSystem();

  ~SimulatorSystem();

  void run();

  void process(Message *msg);

  void shutdown();

  bool append_target(uint32_t _select_id, uint32_t _base_address, uint32_t _size);

  bool set_network(AbstractNet *_net);

  bool set_simulator(AbstractSimulator *_sim);

  Target *resolve_target(uint32_t address);
};

#endif
