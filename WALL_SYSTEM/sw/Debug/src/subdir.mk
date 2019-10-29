################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../lscript.ld

C_SRCS += \
../aes.c \
../aes_crt.c \
../helloworld.c \
../platform.c \
../sha256.c

OBJS += \
../aes.o \
../aes_crt.o \
../helloworld.o \
../platform.o \
../sha256.o

C_DEPS += \
../aes.d \
../aes_crt.d \
../helloworld.d \
../platform.d \
../sha256.d


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../app_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


