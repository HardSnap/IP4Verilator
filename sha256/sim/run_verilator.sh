#!/usr/bin/env bash

export PATH=/home/nasm/Tools/verilator/bin:$PATH
export VERILATOR_ROOT=/home/nasm/Tools/verilator
export SYSTEMC_LIBDIR=/home/nasm/Tools/systemc-2.3/config/src/sysc/.libs
export SYSTEMC_INCLUDE=/home/nasm/Tools/systemc-2.3/src
export LD_LIBRARY_PATH=$SYSTEMC_LIBDIR:$LD_LIBRARY_PATH
export PATH=$VERILATOR_ROOT:$PATH
# Might be needed if SystemC 2.3.0
export SYSTEMC_CXX_FLAGS=-pthread -lsystemc

make
