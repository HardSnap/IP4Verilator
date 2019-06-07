/*
 * Author : Corteggiani Nassim
 * Company: EURECOM
 * Brief  : This class define the requirements for a Simulator
 */

#ifndef ABSTRACT_SIMULATOR_H
#define ABSTRACT_SIMULATOR_H

#include <stdint.h>

class AbstractSimulator {

public:
  /*
   * Brief: generate one cycle in the simulator by driving the main clock
   */
  virtual void clock(uint32_t cycles) = 0;

  /*
   * Brief: thread-safe function running the simulator until shutdonw gets
   * called
   */
  virtual void run() = 0;

  /*
   * Brief: thread-safe function driving top signal to send inputs to the design
   */
  virtual void input(uint32_t data, uint32_t address) = 0;

  /*
   * Brief: thread-safe function driving top signal to read outputs from the
   * design
   */
  virtual uint32_t output(uint32_t address) = 0;

  /*
   * Brief: this function shutdown the simulator thread safely
   * If trace mode is activated, it flush the file on the disk and closes
   * descriptor
   */
  virtual void shutdown() = 0;

  /*
   * Brief: Initialize top signals before running simulation
   * This methods is called by run when using multi-threaded mode
   */
  virtual void init() = 0;
};

#endif
