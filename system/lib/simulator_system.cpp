#include "simulator_system.h"

#include "abstract_net.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

SimulatorSystem::SimulatorSystem() {
  running = false;
  net = NULL;
}

SimulatorSystem::~SimulatorSystem() {}

bool SimulatorSystem::set_network(AbstractNet *_net) {

  if (net == NULL) {
    net = _net;

    if (!net->init()) {
      return false;
    }

    return true;
  } else {
    spdlog::error("Network inteface has already been set, cannot overwrite.");
    return false;
  }
}

bool SimulatorSystem::append_target(AbstractSimulator *_sim, uint32_t _select_id,
                                    uint32_t _base_address, uint32_t _size) {
  if (_sim == NULL) {
    spdlog::error("Append target failed, null argument");
    return false;
  }

  bool already_started = false;
  for (auto it = targets.begin(); it != targets.end(); it++) {
    Target *target = *it;
    if (target->sim == _sim)
      already_started = true;
  }

  std::thread *task = NULL;

  if(!already_started)
    _sim->init();

  /*
  if(!already_started) {
    std::thread *task = _sim->start();
    spdlog::info("New target detected, starting detached thread...");
  }
  */

  Target *target = new Target(_select_id, _sim, _base_address, _size, task);

  targets.push_back(target);

  return true;
}

Target *SimulatorSystem::resolve_target(uint32_t address) {

  for (auto it = targets.begin(); it != targets.end(); it++) {
    Target *target = *it;

    if (address >= target->base_address &&
        (address < (target->base_address + target->size - 1))) {
      return target;
    }
  }

  return NULL;
}

void SimulatorSystem::run() {

  if (targets.empty() || net == NULL) {
    spdlog::error("SimulatorSystem cannot run because no target are present or "
                  "net interface "
                  "not specified");
  }

  running = true;
  while (running) {

    bool net->is_irq_ack();

    // look for interrupt
    std::vector<Target*>::iterator it;
    for (it = targets.begin() ; it != targets.end(); ++it) {
      Target *target = *it;

      if(is_irq_ack)
       target->ack_active_irq();

      target->sim->clock(1);

      if( target->sim->has_pending_irq() )
        process(new Message(0,0,'I'));
    }

    Message *message = net->receive();

    if (message != NULL)
      process(message);
  }
}

void SimulatorSystem::process(Message *msg) {

  if (msg == NULL)
    return;

  if(msg->type == 'I') {
    net->irq();
  }

  Target *target = resolve_target(msg->address);
  if(target == NULL) {
    spdlog::error("system failed to resolve target for message: type={} address={} data={}", msg->type, msg->address, msg->data);
    return;
  }

  target->sim->select(target->select_id);

  if (msg->type == 'W')
    target->sim->input(msg->data, (uint32_t)(msg->address - target->base_address));
  else if (msg->type == 'R') {
    uint32_t res = target->sim->output((uint32_t)(msg->address - target->base_address));

    net->send(res);
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
