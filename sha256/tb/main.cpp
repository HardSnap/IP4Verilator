#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
#include <fcntl.h>
#include <mutex>
#include <netinet/in.h>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "external_interface.h"
#include "simulator_driver.h"

std::mutex mtx;

// Shared memory between threads and Klee
u_char *sync_mem_ptr;

// SimulatorDriver ptr made global to close it properly when sigterm is emitted
SimulatorDriver *sim;
std::thread *sim_thread;
// ExternalInterface ptr made global to close it properly when sigterm is
// emitted
ExternalInterface *io;
std::thread *io_thread;

/*
 * Catch process signal to close the simulator using the right way
 */
// void sig_term_handler(int signum, siginfo_t *info, void *ptr);
// void sigterm_handling();

void init_shared_memory();

void sigint_handler(int sig);

/*
 * Execute self test before running core functions
 * If test fails the program returns
 */
bool execute_self_test();

int main(int argc, char **argv) {

  // Catch SIGTERM signal
  // sigterm_handling();
  signal(SIGINT, sigint_handler);
  signal(SIGTERM, sigint_handler);
  signal(SIGKILL, sigint_handler);

  init_shared_memory();

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

  // Instantiate simulator and comm interface
  sim = new SimulatorDriver();
  io = new ExternalInterface(sim);

  // Start simulator and comm interface
  std::thread simulator(&SimulatorDriver::run, sim);
  sim_thread = &simulator;

  std::thread com(&ExternalInterface::run, io);
  io_thread = &com;

  com.join();
  sim->shutdown();
  simulator.join();
}

bool execute_self_test() {

  SimulatorDriver *sim = new SimulatorDriver();

  sim->init();

  // std::cout << "[TEST] Computing hash for string 'abc'" << std::endl;
  sim->input(0x61626380, 20);
  sim->input(0x00000000, 24);
  sim->input(0x00000000, 28);
  sim->input(0x00000000, 32);
  sim->input(0x00000000, 36);
  sim->input(0x00000000, 40);
  sim->input(0x00000000, 44);
  sim->input(0x00000000, 48);
  sim->input(0x00000000, 52);
  sim->input(0x00000000, 56);
  sim->input(0x00000000, 60);
  sim->input(0x00000000, 64);
  sim->input(0x00000000, 68);
  sim->input(0x00000000, 72);
  sim->input(0x00000000, 76);
  sim->input(0x00000018, 80);

  sim->input(0x00000005, 4);
  sim->input(0x00000004, 4);

  do {
    sim->clock(1);
  } while (sim->output(0) == 0);

  unsigned int expected_hash[] = {0xba7816bf, 0x8f01cfea, 0x414140de,
                                  0x5dae2223, 0xb00361a3, 0x96177a9c,
                                  0xb410ff61, 0xf20015ad};

  // std::cout << "[TEST] Comparing result" << std::endl;
  for (int i = 0; i < 8; i++) {
    unsigned int chunk = sim->output(84 + (i * 4));

    if (chunk != expected_hash[7 - i]) {
      sim->shutdown();
      return false;
    }
    // else
    //   std::cout << std::hex << chunk << "-";
  }
  // std::cout << std::endl;

  sim->shutdown();

  // std::cout << "[TEST] Success" << std::endl;

  return true;
}

void sig_term_handler(int signum, siginfo_t *info, void *ptr) {

  // Wait for communication completion
  while (sync_mem_ptr[0] == 1 || sync_mem_ptr[1] == 1)
    ;

  // Notify watcher from completion
  sync_mem_ptr[2] = 1;

  spdlog::info("Shutting down components...");
  sim->shutdown();
  io->shutdown();

  sim_thread->join();
  io_thread->join();
  spdlog::info("Components are done");

  exit(1);
}

void init_shared_memory() {
  const char *sync_path = "/sync_fifo";

  // Create a shared memory object
  int sync_mem = shm_open(sync_path, O_CREAT | O_RDWR, 0644);
  if (sync_mem == -1) {
    perror("Failed to open sync_mem for simulator synchronisation");
    exit(-1);
  }

  // Set the size
  ftruncate(sync_mem, 8);

  // Map the shared memory in this process
  sync_mem_ptr =
      (u_char *)mmap(NULL, 8, PROT_READ | PROT_WRITE, MAP_SHARED, sync_mem, 0);
  if (sync_mem_ptr == MAP_FAILED) {
    perror("Failed to map sync_mem for simulator synchronisation");
    exit(-1);
  }
}

void sigint_handler(int sig) {
  printf("Good bye!!!\n");

  // Wait for communication completion
  while (sync_mem_ptr[0] == 1 || sync_mem_ptr[1] == 1)
    ;

  // Notify watcher from completion
  sync_mem_ptr[2] = 1;

  spdlog::info("Shutting down components...");
  sim->shutdown();
  io->shutdown();

  sim_thread->join();
  io_thread->join();
  spdlog::info("Components are done");

  exit(1);
}

// void sigterm_handling() {
//   static struct sigaction _sigact;
//
//   memset(&_sigact, 0, sizeof(_sigact));
//
//   _sigact.sa_sigaction = sig_term_handler;
//   _sigact.sa_flags = SA_SIGINFO;
//
//   sigaction(SIGTERM, &_sigact, NULL);
//
//   signal(SIGINT, sigint_handler);
// }
