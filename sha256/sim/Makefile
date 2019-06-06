######################################################################
#
# DESCRIPTION: Verilator Example: Small Makefile
#
# This calls the object directory makefile.  That allows the objects to
# be placed in the "current directory" which simplifies the Makefile.
#
# Copyright 2003-2018 by Wilson Snyder. This program is free software; you can
# redistribute it and/or modify it under the terms of either the GNU
# Lesser General Public License Version 3 or the Perl Artistic License
# Version 2.0.
#
######################################################################
# Set up env. variables
# export VERILATOR_ROOT=/home/noname/Tools/verilator
# export SYSTEMC_LIBDIR=/home/noname/Tools/systemc-2.3/config/src/sysc/.libs
# export SYSTEMC_INCLUDE=/home/noname/Tools/systemc-2.3/src
# export PATH=$VERILATOR_ROOT:$PATH
# export LD_LIBRARY_PATH=$SYSTEMC_LIBDIR:$LD_LIBRARY_PATH
#  # Might be needed if SystemC 2.3.0
# export SYSTEMC_CXX_FLAGS=-pthread

TB_LG := CC

######################################################################
# Check for sanity to avoid later confusion

ifneq ($(words $(CURDIR)),1)
 $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif

######################################################################
# Set up variables

# If $VERILATOR_ROOT isn't in the environment, we assume it is part of a
# package inatall, and verilator is in your path. Otherwise find the
# binary relative to $VERILATOR_ROOT (such as when inside the git sources).
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
VERILATOR_COVERAGE = verilator_coverage
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
VERILATOR_COVERAGE = $(VERILATOR_ROOT)/bin/verilator_coverage
endif

VERILATOR_FLAGS =
# Generate SystemC in executable form
ifeq ($(TB_LG),SC)
VERILATOR_FLAGS += -sc --exe
else
VERILATOR_FLAGS += --cc --exe
endif
# Generate makefile dependencies (not shown as complicates the Makefile)
#VERILATOR_FLAGS += -MMD
# Optimize
VERILATOR_FLAGS += -O3 -x-assign 0
# Warn abount lint issues; may not want this on less solid designs
VERILATOR_FLAGS += -Wall
# Make waveforms
VERILATOR_FLAGS += --trace
# Check SystemVerilog assertions
# VERILATOR_FLAGS += --assert
# Generate coverage analysis
# VERILATOR_FLAGS += --coverage
# Run Verilator in debug mode
#VERILATOR_FLAGS += --debug
# Add this trace to get a backtrace in gdb
# VERILATOR_FLAGS += --gdbbt

TOP_RTL      = top
TOP_RTL_FILE = $(patsubst %,%.sv,$(TOP_RTL))
RTL_PATH     = ../rtl/
ifeq ($(TB_LG),SC)
SC_TB_FILE   = ../tb/main.cpp
else
SC_TB_FILE   = ../tb/main.cpp
endif
OBJ_DIR      = obj_dir
EXE          = simu

# Check if SC exists via a verilator call (empty if not)
SYSTEMC_EXISTS := $(shell $(VERILATOR) --getenv SYSTEMC_INCLUDE)

######################################################################

src := \
sha256_v1_0_S00_AXI.v \
sha256_v1_0.v \
tb_axi_lite_slave.v

ifneq ($(SYSTEMC_EXISTS),)
default: all
else
default: nosc
endif

.PHONY: gen exe all clean wave

all:
	make gen
	make exe

gen:
	@echo
	@echo "-- VERILATE ----------------"
	# verilator $(VERILATOR_FLAGS) -y $(RTL_PATH) $(TOP_RTL_FILE) $(SC_TB_FILE) -o ../$(EXE)
	verilator                                                                                  \
											$(filter-out %.vhd, $(src))                                            \
	                    --unroll-count 256                                                     \
											--trace                                                                \
	                    -Werror-PINMISSING                                                     \
	                    -Werror-IMPLICIT                                                       \
	                    -Wno-fatal                                                             \
	                    -Wno-PINCONNECTEMPTY                                                   \
	                    -Wno-ASSIGNDLY                                                         \
	                    -Wno-DECLFILENAME                                                      \
	                    -Wno-UNOPTFLAT                                                         \
	                    -Wno-UNUSED                                                            \
	                    -Wno-style                                                             \
	                    -Wno-lint                                                              \
                      -y $(RTL_PATH)                                                         \
	                    $(if $(DEBUG),--trace-structs --trace,)                                \
	                    -CFLAGS -std=c++11 -Wall --cc  --vpi                                   \
                      -LDFLAGS "-lpthread -lrt"                                              \
	                    $(list_incdir) --top-module $(TOP_RTL)                                 \
	                    --Mdir $(OBJ_DIR) -O3                                                  \
	                    --exe ../tb/main.cpp -o ../$(EXE)

exe:
	@echo "-- EXECUTABLE ----------------"
	# $(MAKE) -j 4 -C $(OBJ_DIR) OBJ_DIR=$(OBJ_DIR) SC_TB_FILE=$(SC_TB_FILE) -f ../Makefile_obj
	make -C $(OBJ_DIR) -f $(patsubst %,V%.mk, $(TOP_RTL))
	# $(MAKE) -C $(OBJ_DIR) -f ../Makefile_obj

run:
	@echo
	@echo "-- RUN ---------------------"
	@mkdir -p logs
	./simu +trace

covarage:
	@echo
	@echo "-- COVERAGE ----------------"
	$(VERILATOR_COVERAGE) --annotate logs/annotated logs/coverage.dat

wave:
	@echo
	@echo "-- DONE --------------------"
	@echo "To see waveforms, open vlt_dump.vcd in a waveform viewer"
	@echo
	gtkwave ./logs/vlt_dump.vcd

clean:
	rm -f *.vcd
	rm -fr $(OBJ_DIR)
	rm -f $(EXE)


######################################################################
# Other targets

nosc:
	@echo
	@echo "%Skip: SYSTEMC_INCLUDE not in environment"
	@echo "(If you have SystemC see the README, and rebuild Verilator)"
	@echo

show-config:
	$(VERILATOR) -V
