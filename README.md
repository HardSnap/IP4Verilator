# What

This repository contains an automated simulator builder based on Verilator (an open-source multithread Verilog simulator).
In a nutshell, Verilator generates a cycle-accurate C++ model for the input Verilog files.
This C++ model is a self-contained simulator. To enables remote communication with the model, our toolchain add the following:
* Cycle-accurate peripheral bus commuication. Currently supporting AXI4-Lite and Wishbone.
* An automated communication interface: socket or linux pipe.

Most steps are automated.

# How

```
cd ./automated_builder.sh

IP_PATH=<> TOP_RTL=<> SIM_DRIVER=<> NET_DRIVER=<>
Usage: ./automated_builder.sh [-h|--help] <IP_PATH> <TOP_RTL> <SIM_DRIVER> <NET_DRIVER>
	<IP_PATH>: Target IP Path
	<TOP_RTL>: RTL TOP file
	<SIM_DRIVER>: Simulation driver name
	<NET_DRIVER>: Net driver name
	-h,--help: Prints help
```

Supported SIM_DRIVER are cpp file name in directory ```../system/lib/sim_driver``` without file extension.
Supported NET_DRIVER are cpp file name in directory ```../system/lib/net``` without file extension.

Example with AES_CTR peripheral:

```
git clone git@github.com:Bounti/fpga_ip.git
./automated_builder.sh ./ip/aes_ctr/AES_CTR_1.0/AES_CTR_1.0/ ./ip/aes_ctr/AES_CTR_1.0/AES_CTR_1.0/rtl/AES_CTR_v1_0.v axi_sim_driver mkfifo
```

The generated project contains the followind:
* sw: software example to run in Inception with Makefile. Run it to build software bitcode.
* sim: simulator driver with Makefile. Run it to build the simulator.
* rtl: rtl files with target peripheral IP description and bus interface.

Before compiling the simulator driver, go to the system directory and check-out the README.md to see how to install it.
```
cd system
mkdir build && cd build && cmake .. && make
```

Then compile the AES_CTR simulator

```
cd AES_CTR_1.0/sim
make
```

If you get the following error when running a simulator:
```
terminate called after throwing an instance of 'spdlog::spdlog_ex'
```
run this command in the sim directory 
```
mkdir logs
```

If at a second run the simulator stop without any error message:
```
rm /tmp/cmd_fifo 
rm /tmp/data_fifo 
```

# Running Inception

First start the simulator program in background.
```
./simu &
```

Then, compile the content of sw directory 
```
cd sw && make
```

In case of custom LLVM installation dir:
```
export PATH=/home/nasm/Tools/llvm/build_release/Release+Asserts/bin/:$PATH
```

This step could be automated and largely improved.
Inception uses CRIU to generate simulator snapshot.
However, since CRIU is linked in the Inception-analyzer it cannot fork to start the simulator process.
Futhermore, CRIU requires root access to work. So the current solution consist in starting the simulator
first and then set the simulator pid in the Inception-analyzer configuration file (config.json).

```
pgrep simu

cd sw
nano config.json
```

Then, set in section HardwareEnvironment argument pid the value returned by pgrep.
You can now start Inception-analyzer (in root).


