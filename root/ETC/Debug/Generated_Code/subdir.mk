################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AS1.c \
../Generated_Code/Bit1.c \
../Generated_Code/CAN1.c \
../Generated_Code/CI2C1.c \
../Generated_Code/Cpu.c \
../Generated_Code/MQX1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PWM1.c \
../Generated_Code/SystemTimer1.c \
../Generated_Code/TU1.c \
../Generated_Code/Vectors.c 

OBJS += \
./Generated_Code/AS1.o \
./Generated_Code/Bit1.o \
./Generated_Code/CAN1.o \
./Generated_Code/CI2C1.o \
./Generated_Code/Cpu.o \
./Generated_Code/MQX1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PWM1.o \
./Generated_Code/SystemTimer1.o \
./Generated_Code/TU1.o \
./Generated_Code/Vectors.o 

C_DEPS += \
./Generated_Code/AS1.d \
./Generated_Code/Bit1.d \
./Generated_Code/CAN1.d \
./Generated_Code/CI2C1.d \
./Generated_Code/Cpu.d \
./Generated_Code/MQX1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PWM1.d \
./Generated_Code/SystemTimer1.d \
./Generated_Code/TU1.d \
./Generated_Code/Vectors.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/Static_Code/PDD" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/Static_Code/IO_Map" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/Sources" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/Generated_Code" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/include" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/config" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/kernel" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/psp/cortex_m" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/psp/cortex_m/core/M4" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


