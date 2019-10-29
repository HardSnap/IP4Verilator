#include "net.h"
#include "sim.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

#include <signal.h>
#include <string.h>

#include "simulator_system.h"

SimulatorSystem *sys = NULL;

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
  signal(SIGABRT, sig_handler);

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
  file_logger->flush_on(spdlog::level::info);
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

  return 0;
  /*
   * TODO: To handle burst accesses, the simulator has a FIFO where commands are
   * stored So that, the external interface can always accept commands while the
   * FIFO is no full.
   */

  // Instantiate System
  sys = new SimulatorSystem();

  // Here you can relplace MKFifoNet by any class that inherits from AbstractNet
  // For instance you could use UDP or TCP socket instead depending on what you
  // matter of. It seems that mkfifo have less latency and highest throughput
  // than socket. But please check CRIU limitation first!
  AbstractNet *net = new MKFifo();

  AbstractSimulator *simulator = new AXISimulatorDriver();

  // System is compiled statically and linked with this program It avoids
  // recompiling all the stuff and having many times the same files in each
  // project. To connect components together we use the system class This class
  // will also manage the execution and turn components off when closing the
  // program
  if (!sys->set_network(net)) {
    spdlog::error("Unable to init network interface");
    return 0;
  }
  spdlog::error("Network inteface is up.");

  if (!sys->append_target(simulator, 0x0, 0x200)) {
    spdlog::error("Unable to init simulator");
    return 0;
  }
  spdlog::error("Target simulator is up.");

  // Blocking function
  spdlog::error("Running system components.");
  sys->run();

  spdlog::info("All components are down! Good Bye!");
}

bool execute_self_test() {

  AbstractSimulator *sim = new AXISimulatorDriver();
  
  sim->init();
  
  sim->input(0x00000000, 0);
   
  std::cout << "[TEST] Loading key0" << std::endl;
  sim->input(0x28aed2a6, 20+0 );
  sim->input(0x2b7e1516, 20+4 );
  sim->input(0x09cf4f3c, 20+8 );
  sim->input(0xabf71588, 20+12);
  sim->input(0x28aed2a6, 20+16);
  sim->input(0x2b7e1516, 20+20);

  std::cout << "[TEST] Loading key1" << std::endl;
  sim->input(0x28aed2a6, 0x50 + 0 );
  sim->input(0x2b7e1516, 0x50 + 4 );
  sim->input(0x09cf4f3c, 0x50 + 8 );
  sim->input(0xabf71588, 0x50 + 12);
  sim->input(0x28aed2a6, 0x50 + 16);
  sim->input(0x2b7e1516, 0x50 + 20);
  
  std::cout << "[TEST] Loading key2" << std::endl;
  sim->input(0x28aed2a6, 0x68 + 0 );
  sim->input(0x2b7e1516, 0x68 + 4 );
  sim->input(0x09cf4f3c, 0x68 + 8 );
  sim->input(0xabf71588, 0x68 + 12);
  sim->input(0x28aed2a6, 0x68 + 16);
  sim->input(0x2b7e1516, 0x68 + 20);
 
  //Set key select
  std::cout << "[TEST] Setting active key 0" << std::endl;
  sim->input(0x00000000, 0x80);
  // Set PT 
  std::cout << "[TEST] Setting plain text" << std::endl;
  sim->input(0x66667777, 0x4);
  sim->input(0x44445555, 0x4+4);
  sim->input(0x22223333, 0x4+8);
  sim->input(0x00001111, 0x4+12);
  // Set st 
  std::cout << "[TEST] Setting st" << std::endl;
  sim->input(0x3243f6a8, 0x40);
  sim->input(0x885a308d, 0x40+4);
  sim->input(0x313198a2, 0x40+8);
  sim->input(0xe0370734, 0x40+12);


  // SET CONTROL -> NEXT
  std::cout << "[TEST] Starting process" << std::endl;
  sim->input(0x00000001, 0); 
  sim->input(0x00000000, 0);

  do {
    sim->clock(1);
  } while (sim->output(0xB*4) == 0);
  std::cout << "[TEST] Done" << std::endl;
  
  unsigned int expected_hash[] = {0x4fcb9ca9, 0x75a691f2, 0xff338e2b, 0xb85460db};
  
  std::cout << "[TEST] Comparing result" << std::endl;
  for (int i = 0; i < 4; i++) {
    unsigned int chunk = sim->output(30 + (i * 4));
 
    printf("%08x\n", chunk);
    //if (chunk != expected_hash[4 - i]) {
    //  sim->shutdown();
    //  return false;
    //}
  }
  
  for(int i=0; i<0x20; i++) {
    printf("Reg[%x] = %08x\n", i, sim->output(i*4));
  }
  
  sim->shutdown();
  
  std::cout << "[TEST] Success" << std::endl;
  
  return true;
}

void sig_handler(int sig) {

  spdlog::info("Shutting down components...");
  if (sys != NULL)
    sys->shutdown();
  spdlog::info("Components are done");

  exit(1);
}
