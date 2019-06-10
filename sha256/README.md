# Brief

This repository contains an open-sourced SHA2-256  digital design simulated with Verilator.
It also supports external communication to connect the peripheral to an external
system.


# Compiling

Before compiling, you need to install Verilator and add it to your path.
Go to the official Verilator website for that.
Then compile this project following the instructions below.

```
cd sim

make

# For debug
#make DEBUG=1

#Run the simulator
make run

#Clean the project
make clean

```
