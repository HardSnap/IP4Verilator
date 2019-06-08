#include "simulator_system.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

std::mutex mtx;

SimulatorSystem::SimulatorSystem() { running = false; }

SimulatorSystem::~SimulatorSystem() {}

bool SimulatorSystem::set_network(AbstractNet *_net) {

  if (net == NULL) {
    net = _net;
    return true;
  } else {
    spdlog::info("Network inteface has already been set, cannot overwrite.");
    return false;
  }
}

bool SimulatorSystem::append_target(AbstractSimulator *_sim, uint32_t _base_address,
                           uint32_t _size) {

  std::thread task(&AbstractSimulator::run, _sim);

  Target *target = new Target(_sim, _base_address, _size, &task);

  targets.push_back(target);
}

Target *SimulatorSystem::resolve_target(uint32_t address) {

  for (auto it = targets.begin(); it != targets.end(); it++) {
    Target *target = *it;

    if (target->base_address >= address &&
        (address < (target->base_address + target->size - 1))) {
      return target;
    }
  }

  return NULL;
}

void SimulatorSystem::run() {

  if (targets.empty() || net == NULL) {
    spdlog::error(
        "SimulatorSystem cannot run because no target are present or net interface "
        "not specified");
  }

  while (running) {
    Message *message = net->read();

    process(message);
  }
}

void SimulatorSystem::process(Message *msg) {

  if (msg == NULL)
    return;

  Target *target = resolve_target(msg->address);

  if (msg->type == 'W')
    target->sim->input(msg->address, msg->data);
  else if (msg->type == 'R') {
    uint32_t res = target->sim->output(msg->address);

    net->write(res);
  } else
    spdlog::error("Ignored message: unknown field type");
}

void SimulatorSystem::shutdown() {

  // Wait for targets to complete all commands before shutdown
  for (auto it = targets.begin(); it != targets.end(); it++) {

    Target *target = (*it);

    target->sim->shutdown();

    // target->task->join();
  }
  running = false;
}
