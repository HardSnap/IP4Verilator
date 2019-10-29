# Define version and name

LLVM_VERSION=3.6

TARGET=TEST_CASE

OUTPUT=bin

# Toolchain Path

TOOL_PATH=/home/nasm/Tools/build_debug/Debug+Asserts/bin/
# Toolchain

IR           = $(TOOL_PATH)clang
IC           = inception-cl
#CC          = $(TOOL_PATH)clang
#CXX         = $(TOOL_PATH)clang++
CC           = arm-none-eabi-gcc
CXX          = arm-none-eabi-g++
LLVM_LINK    = $(TOOL_PATH)llvm-link
LLVM_AS      = $(TOOL_PATH)llvm-as
#AS           = $(TOOL_PATH)clang
AS           = arm-none-eabi-as
LD           = arm-none-eabi-ld
OBJDUMP      = arm-none-eabi-objdump
SIZE         = arm-none-eabi-size

# Arguments

COMMON_ARGS  = -target arm-none-eabi -mcpu=cortex-m3 -O0 -mfloat-abi=soft
GCC_ARGS     = -march=armv7-m -mthumb -mcpu=cortex-m3 -Wa,-mimplicit-it=thumb

CC_FLAGS     = $(GCC_ARGS)
CXX_ARGS     = $(GCC_ARGS)
ASM_FLAGS    = -mcpu=cortex-m3 -mthumb -mfloat-abi=softfp
#ASM_FLAGS    = $(COMMON_ARGS) -nostdlib
LD_FLAGS     =
IR_FLAGS     = $(COMMON_ARGS) -emit-llvm -S -g -DKLEE

# Linker Option

LINKED       =

LINKER_SCRIPT= link.ld

# Include sub config

-include config.mk

# Linker Option suite

LD_FLAGS     += -T $(LINKER_SCRIPT)

# Include

#CC_FLAGS     += -I/usr/include/newlib/
#AS_FLAGS      += -I/usr/include/newlib/
#CXX_FLAGS     += -I/usr/include/newlib/
IR_FLAGS     += -I/usr/include/newlib/

# Define sources

C_FILES      := $(shell find ./ -type f -name "*.c" -printf "%p\n")
CXX_FILES    := $(shell find ./ -type f -name "*.cpp" -printf "%p\n")
ASM_FILES    := $(shell find ./ -type f -name "*.s" -printf "%p\n")

HEADER       := $(shell find ./ -type f -name "*.h" -exec dirname {} \; | sort -u | sed ':a;N;$$!ba;s/\n/ -I/g' | xargs -0 printf "%s")

C_OBJS        = $(patsubst %.c,%.o,$(C_FILES))
CXX_OBJS      = $(patsubst %.cpp,%.o,$(CXX_FILES))
ASM_OBJS      = $(patsubst %.s,%.o,$(ASM_FILES))

LL_OBJS       = $(patsubst %.c,%.ll,$(C_FILES))
LL_OBJS      += $(patsubst %.cpp,%.ll,$(CXX_FILES))

OBJS          = $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS)

# Verbose

V = 0
ifeq ($V, 0)
        Q = @
        P = 2>&1 >/dev/null
endif

#################### Rules ###########################
######################################################

all: BIN IR ADAPT_BC_ASM

BIN: $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS) ELF

IR: $(LL_OBJS) BC

# Compilation rules

%.ll : %.cpp
	@echo "[LL]      $(notdir $<)"
	$Q$(IR) $(IR_FLAGS) -o $@ -c $<

%.ll : %.c
	@echo "[LL]      $(notdir $<)"
	$Q$(IR) $(IR_FLAGS) -o $@ -c $<

%.o : %.c
	@echo "[CC]      $(notdir $<)"
	$Q$(CC) $(CC_FLAGS) $(DEBUG) -o $@ -c $<

%.o : %.s
	@echo "[AS]      $(notdir $<)"
	$Q$(AS) $(ASM_FLAGS) -o $@ -c $<

%.o : %.cpp
	@echo "[CXX]      $(notdir $<)"
	$Q$(CXX) $(CXX_FLAGS) -c -o $@ $< -MMD -MF dep/$(*F).d

# Link rules

ELF: $(OBJS)
	@echo "[LD]      $(OUTPUT).elf"
	$Q$(LD) $(LD_FLAGS) $^ -o $(OUTPUT).elf
	@echo "[OBJDUMP] $(OUTPUT).lst"
	$Q$(OBJDUMP) -St $(OUTPUT).elf >$(TARGET).lst
	@echo "[SIZE]    $(OUTPUT).elf"
	$Q$(SIZE) $(OUTPUT).elf

BC: $(LL_OBJS)
	@echo "[LLVM-LINK]      $(OUTPUT).ll"
	$Q$(LLVM_LINK) -S $^ -o $(OUTPUT).ll
	sed -i 's/ linkonce_odr / /g' $(OUTPUT).ll
	sed -i 's/ internal / /g' $(OUTPUT).ll
	sed -ri 's/external global ([\._%0-9a-zA-Z]*)\*/ global \1\* undef/g' $(OUTPUT).ll
	sed -ri 's/external global ([0-9a-zA-Z]*)/ global \1 0/g' $(OUTPUT).ll
	sed -ri 's/extern_weak global ([0-9a-zA-Z]*)/ global \1 0/g' $(OUTPUT).ll
	echo "[LLVM-AS]       $(OUTPUT).ll"
	$Q$(LLVM_AS) $(OUTPUT).ll -o $(OUTPUT).bc

# Clean rules

clean:
	$Qrm -rf *.o $P
	$Qrm -rf *.ll $P
	$Qrm -rf klee-* $P
	$Qrm -rf *.ll $P
	$Qrm -rf *.bc $P
	$Qrm -rf *.elf $P
	$Qrm -rf *.lst $P

ADAPT_BC_ASM:
	@echo "[INCEPTION-COMPILER]      $(OUTPUT).bc"
	$Q$(IC) $(IC_FLAGS) $(OUTPUT).elf $(OUTPUT).bc $P
	@echo "[LLVM-AS]       $(OUTPUT).ll"
	$Q$(LLVM_AS) $(OUTPUT).elf.ll -o $(OUTPUT).bc $P
	#$Q$(LLVM_AS) $(OUTPUT).elf.ll -o $(OUTPUT)_raw.bc $P
	#opt -O3 -adce $(OUTPUT)_raw.bc -o $(OUTPUT).bc

INCEPTION:
	inception --allocate-determ --allocate-determ-start-address 0x90000000 --allocate-determ-size 10000 --elf ./bin.elf --bitcode ./bin.bc --mem_conf_file ./mem.json --interrupt_conf_file ./irq.json --has_debugger
