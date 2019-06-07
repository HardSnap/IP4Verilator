#include "net.h"
#include "sim.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

#include <signal.h>
#include <string.h>

#include "system.h"

System *system;

/*
 * Catch process signal to close the simulator using the right way
 */
void sig_handler(int sig);

/*
 * Execute self test before running core functions
 * If test fails the program returns
 */
bool execute_self_test();

int main(int argc, char **argv) {

  // Catch SIGTERM signal
  signal(SIGINT, sig_handler);
  signal(SIGTERM, sig_handler);
  signal(SIGKILL, sig_handler);

  /*
   * Initialize Verilator
   */
  Verilated::commandArgs(argc, argv);
  Verilated::debug(0);
#if TRACE
  Verilated::traceEverOn(true);
#endif

  /*
   * Initialize logger
   */
  auto file_logger = spdlog::basic_logger_mt("basic_logger", "logs/run.log");
  spdlog::set_default_logger(file_logger);
  spdlog::info("Starting self test...");
  spdlog::info("Author : Corteggiani Nassim");
  spdlog::info("Contact: corteggi@eurecom.fr");
  spdlog::info("Company: EURECOM");

  // test the hardware model
  spdlog::info("Starting self test...");
  if (!execute_self_test())
    spdlog::error("Self test failed...");
  else
    spdlog::info("Self test ok!");

  /*
   * TODO: To handle burst accesses, the simulator has a FIFO where commands are
   * stored So that, the external interface can always accept commands while the
   * FIFO is no full.
   */

  // Instantiate System
  system = new System();

  // Here you can relplace MKFifoNet by any class that inherits from AbstractNet
  // For instance you could use UDP or TCP socket instead depending on what you
  // matter of. It seems that mkfifo have less latency and highest throughput
  // than socket. But please check CRIU limitation first!
  AbstractNet *net = new MKFifoNet();

  AbstractSimulator *simulator = new AXISimulatorDriver();

  // System is compiled statically and linked with this program It avoids
  // recompiling all the stuff and having many times the same files in each
  // project. To connect components together we use the system class This class
  // will also manage the execution and turn components off when closing the
  // program
  if (!system->set_network(net))
    spdlog::error("Unable to init network interface");

  if (!system->append_target(simulator, 0x0, 0x200))
    spdlog::error("Unable to init simulator");

  // Blocking function
  system->run();

  spdlog::info("All components are down! Good Bye!");
}

bool execute_self_test() {

  // SimulatorDriver *sim = new SimulatorDriver();
  //
  // sim->init();
  //
  // // std::cout << "[TEST] Computing hash for string 'abc'" << std::endl;
  // sim->input(0x61626380, 20);
  // sim->input(0x00000000, 24);
  // sim->input(0x00000000, 28);
  // sim->input(0x00000000, 32);
  // sim->input(0x00000000, 36);
  // sim->input(0x00000000, 40);
  // sim->input(0x00000000, 44);
  // sim->input(0x00000000, 48);
  // sim->input(0x00000000, 52);
  // sim->input(0x00000000, 56);
  // sim->input(0x00000000, 60);
  // sim->input(0x00000000, 64);
  // sim->input(0x00000000, 68);
  // sim->input(0x00000000, 72);
  // sim->input(0x00000000, 76);
  // sim->input(0x00000018, 80);
  //
  // sim->input(0x00000005, 4);
  // sim->input(0x00000004, 4);
  //
  // do {
  //   sim->clock(1);
  // } while (sim->output(0) == 0);
  //
  // unsigned int expected_hash[] = {0xba7816bf, 0x8f01cfea, 0x414140de,
  //                                 0x5dae2223, 0xb00361a3, 0x96177a9c,
  //                                 0xb410ff61, 0xf20015ad};
  //
  // // std::cout << "[TEST] Comparing result" << std::endl;
  // for (int i = 0; i < 8; i++) {
  //   unsigned int chunk = sim->output(84 + (i * 4));
  //
  //   if (chunk != expected_hash[7 - i]) {
  //     sim->shutdown();
  //     return false;
  //   }
  //   // else
  //   //   std::cout << std::hex << chunk << "-";
  // }
  // // std::cout << std::endl;
  //
  // sim->shutdown();
  //
  // // std::cout << "[TEST] Success" << std::endl;
  //
  // return true;
}

void sig_handler(int sig) {

  spdlog::info("Shutting down components...");
  system->shutdown();
  spdlog::info("Components are done");

  exit(1);
}
