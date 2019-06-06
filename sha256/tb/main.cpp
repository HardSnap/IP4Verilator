#include <mutex>

std::mutex mtx;

// Shared memory between threads and Klee
u_char* sync_mem_ptr;

#include "simulator.h"
#include "io.h"

#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <signal.h>

// simulation time
vluint64_t main_time = 0;       // Current simulation time

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}

void sig_term_handler(int signum, siginfo_t *info, void *ptr) {

  // Wait for communication completion
  while(sync_mem_ptr[0] == 1 || sync_mem_ptr[1] == 1);

  // Notify watcher from completion
  sync_mem_ptr[2] = 1;

  // Exit the program
  exit(1);
}

void init_shared_memory() {
  const char *sync_path = "/sync_fifo";

  // Create a shared memory object
  int sync_mem = shm_open(sync_path, O_CREAT|O_RDWR, 0644);
  if(sync_mem == -1) {
    perror("Failed to open sync_mem for simulator synchronisation");
    exit(-1);
  }

  // Set the size
  ftruncate(sync_mem, 8);

  // Map the shared memory in this process
  sync_mem_ptr = (u_char *) mmap(NULL, 8, PROT_READ|PROT_WRITE, MAP_SHARED, sync_mem, 0);
  if (sync_mem_ptr == MAP_FAILED) {
    perror("Failed to map sync_mem for simulator synchronisation");
    exit(-1);
  }
}

void sigterm_handling() {
  static struct sigaction _sigact;

  memset(&_sigact, 0, sizeof(_sigact));

  _sigact.sa_sigaction = sig_term_handler;
  _sigact.sa_flags = SA_SIGINFO;

  sigaction(SIGTERM, &_sigact, NULL);
}

bool execute_self_test();

bool running;

int main(int argc, char **argv) {

  // Catch SIGTERM signal
  sigterm_handling();

  init_shared_memory();

  Verilated::commandArgs(argc, argv);
  Verilated::debug(0);
  Verilated::traceEverOn(true);

  // test the hardware model
  if(!execute_self_test())
	  std::cout << "[TEST] Fail" << std::endl;

  // start comm interface
  Simulator* master = new Simulator();
  IO* io = new IO(master);
  io->start();

  running = true;
  while(running) {
    if( io->has_message() ) {
	io->process();
    } else {
        master->clock(1);
    }
  }
  // IO* io = new IO(master);

  // std::thread simulator(&Simulator::run,  master);
  // std::thread com(&IO::run,  io);

  // simulator.join();
  // io->running = false;
  // com.join();
}

bool execute_self_test() {

  Simulator* master = new Simulator();

  master->run();

  std::cout << "[TEST] Computing hash for string 'abc'" << std::endl;
  master->input(0x61626380, 20);
  master->input(0x00000000, 24);
  master->input(0x00000000, 28);
  master->input(0x00000000, 32);
  master->input(0x00000000, 36);
  master->input(0x00000000, 40);
  master->input(0x00000000, 44);
  master->input(0x00000000, 48);
  master->input(0x00000000, 52);
  master->input(0x00000000, 56);
  master->input(0x00000000, 60);
  master->input(0x00000000, 64);
  master->input(0x00000000, 68);
  master->input(0x00000000, 72);
  master->input(0x00000000, 76);
  master->input(0x00000018, 80);

  master->input(0x00000005, 4);
  master->input(0x00000004, 4);

  do {
    master->clock(1);
  } while (master->output(0) == 0);

  unsigned int expected_hash[] = {0xba7816bf, 0x8f01cfea, 0x414140de, 0x5dae2223, 0xb00361a3, 0x96177a9c, 0xb410ff61, 0xf20015ad};

  std::cout << "[TEST] Comparing result" << std::endl;
  for(int i=0; i<8; i++) {
    unsigned int chunk = master->output(84+(i*4));

    if(chunk != expected_hash[7-i])
      return false;
    else
      std::cout << std::hex << chunk << "-";
  }
  std::cout << std::endl;

  //master->output(84);
  //master->output(88);
  //master->output(92);
  //master->output(96);
  //master->output(100);
  //master->output(104);
  //master->output(108);
  //master->output(112);

  master->shutdown();

  std::cout << "[TEST] Success" << std::endl;

  return true;
}
