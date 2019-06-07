#include "simulator_driver.h"
#include "external_interface.h"

extern std::mutex mtx;

#if TRACE
/*
 * Simulation time used for trace purpose
 */
vluint64_t sim_time;

// Called by $time in Verilog
double sc_time_stamp() { return main_time; }
#endif

SimulatorDriver::SimulatorDriver() {
  top = new Vtop("top");

#if TRACE
  tfp = new VerilatedVcdC;

  top->trace(tfp, 99);

  tfp->open("log/simx.vcd");

  sim_time = 0;
#endif

  running = false;
}

SimulatorDriver::~SimulatorDriver() {
  delete top;

  exit(0);
}

void SimulatorDriver::clock(uint32_t cycles) {
  for (uint32_t i = 0; i < (cycles * 2); i++) {
    top->eval();
    top->clk_i = ~top->clk_i;
    top->eval();
#if TRACE
    tfp->dump(sim_time++);
#endif
  }
}

void SimulatorDriver::init() {
  // Master write address
  top->write_addr = 0;
  // type of write(leave at 0)
  top->write_prot = 0;
  // master indicating address is valid
  top->write_addr_valid = 0;
  // slave ready to receive address
  top->write_addr_ready = 0;

  // Write Data Channel (W)
  // Master write data
  top->write_data = 0;
  // Master byte-wise write strobe
  top->write_strb = 0;
  // Master indicating write data is valid
  top->write_data_valid = 0;
  // slave ready to receive data
  top->write_data_ready = 0;

  // Write Response Channel (WR)
  // Master ready to receive write response
  top->write_resp_ready = 0;
  // slave write response
  top->write_resp = 0;
  // slave response valid
  top->write_resp_valid = 0;

  // Read Address channel (AR)
  // Master read address
  top->read_addr = 0;
  // type of read(leave at 0)
  top->read_prot = 0;
  // Master indicating address is valid
  top->read_addr_valid = 0;
  // slave ready to receive address
  top->read_addr_ready = 0;

  // Read Data Channel (R)
  // Master indicating ready to receive data
  top->read_data_ready = 0;
  // slave read data
  top->read_data = 0;
  // slave read response
  top->read_resp = 0;
  // slave indicating data in channel is valid
  top->read_data_valid = 0;

  top->clk_i = 0;

  top->rst_ni = 0;
  clock(5);

  top->rst_ni = 1;
  clock(1);
}

void SimulatorDriver::run() {

  init();

  // while (!Verilated::gotFinish()) {
  running = true;
  while (running) {
    mtx.lock();
    clock(1);
    mtx.unlock();
  }
}

void SimulatorDriver::input(uint32_t data, uint32_t address) {
  mtx.lock();

  // #3 write_addr <= addr;	//Put write address on bus
  top->write_addr = address;
  // write_data <= data;	//put write data on bus
  top->write_data = data;
  // write_addr_valid <= 1'b1;	//indicate address is valid
  top->write_addr_valid = 1;
  // write_data_valid <= 1'b1;	//indicate data is valid
  top->write_data_valid = 1; // indicate data is valid
  // write_resp_ready <= 1'b1;	//indicate ready for a response
  top->write_resp_ready = 1; // indicate ready for a response
  // write_strb <= 4'hF;		//writing all 4 bytes
  top->write_strb = 0xF; // writing all 4 bytes

  top->eval();

  // wait for one slave ready signal or the other
  // wait(write_data_ready || write_addr_ready);
  while ((top->write_data_ready == false) && (top->write_addr_ready == false)) {
    clock(1);
  }
  clock(1);

  // received both ready signals
  if (top->write_data_ready && top->write_addr_ready) {
    top->write_addr_valid = 0;
    top->write_data_valid = 0;
    top->eval();
  } else {
    // wait for the other signal and a positive edge
    if (top->write_data_ready) {
      // case data handshake completed
      top->write_data_valid = 0;
      // wait(write_addr_ready); //wait for address address ready
      while (top->write_addr_ready == false) {
        clock(1);
      }
    } else if (top->write_addr_ready) {
      // case address handshake completed
      top->write_addr_valid = 0;
      // wait(write_data_ready); //wait for data ready
      while (top->write_data_ready == false) {
        clock(1);
      }
    }

    top->write_addr_valid = 0; // make sure both valid signals are deasserted
    top->write_data_valid = 0;
    top->eval();
  }

  // both handshakes have occured
  // deassert strobe
  top->write_strb = 0;
  top->eval();

  // wait for valid response
  while (top->write_resp_valid == false) {
    clock(1);
  }

  // deassert ready for response
  top->write_resp_ready = 0;
  clock(1);

  mtx.unlock();
}

uint32_t SimulatorDriver::output(uint32_t address) {
  mtx.lock();

  // Put read address on bus
  top->read_addr = address; // axi_araddr
  // Indicate address is valid
  top->read_addr_valid = 1; // axi_arvalid
  // Indicate data ready
  top->read_data_ready = 1; // axi_rready
  clock(1);

  // wait for one slave ready signal or the other
  // while((top->read_data_valid == false) && (top->read_addr_ready == false)) {
  while (top->read_addr_ready == 0) {
    top->eval();
  }
  clock(1);

  top->read_addr_valid = 0;
  top->eval();

  uint32_t res = top->read_data;

  top->read_data_ready = 0;
  top->eval();

  clock(1);

  mtx.unlock();

  return res;
}

void SimulatorDriver::shutdown() {
  Verilated::gotFinish(true);
  running = false;

#if TRACE
  top->final();
  tfp->close();
#endif
}
