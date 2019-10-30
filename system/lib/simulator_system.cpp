#include "simulator_system.h"

#include "abstract_net.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

SimulatorSystem::SimulatorSystem() {
  running = false;
  net = NULL;
  sim = NULL;
  is_interrupt_active = false;
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

bool SimulatorSystem::set_simulator(AbstractSimulator *_sim) {

  if (sim == NULL) {
    sim = _sim;

    if (!sim->init()) {
      return false;
    }

    return true;
  } else {
    spdlog::error("Simulator has already been set, cannot overwrite.");
    return false;
  }
}

bool SimulatorSystem::append_target(uint32_t _select_id, uint32_t _base_address, uint32_t _size) {

  Target *target = new Target(_select_id, _base_address, _size);

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

/*
* Brief: This is the main execution loop.
* It creates a bridge between the remote app and the simulator.
*/
void SimulatorSystem::run() {

  if (targets.empty() || net == NULL) {
    spdlog::error("SimulatorSystem cannot run because no target are present or "
                  "net interface "
                  "not specified");
  }

  running = true;
  while (running) {

    // Drive the simulator clock
    sim->clock(1);

    // is there an ongoing interrupt
    if( is_interrupt_active ) {
      // Process acknowledgement
      if(net->has_irq_ack()) {
       sim->ack_irq();
       is_interrupt_active = false;
      }
    } else {
      if( sim->has_pending_irq() ) {
        process(new Message(0,0,'I'));
        is_interrupt_active = true;
      }
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

  sim->select(target->select_id);

  if (msg->type == 'W')
    sim->input(msg->data, (uint32_t)(msg->address - target->base_address));
  else if (msg->type == 'R') {
    uint32_t res = sim->output((uint32_t)(msg->address - target->base_address));

    net->send(res);
  } else
    spdlog::error("Ignored message: unknown field type");
}

void SimulatorSystem::shutdown() {

  // Wait for targets to complete all commands before shutdown
  sim->shutdown();
  running = false;
}
