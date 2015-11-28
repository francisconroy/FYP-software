################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/ADC0.c \
../Generated_Code/CLUTCH_SW.c \
../Generated_Code/Cpu.c \
../Generated_Code/FC1.c \
../Generated_Code/FLTCLR1.c \
../Generated_Code/FLTCLR2.c \
../Generated_Code/FLTSD1.c \
../Generated_Code/FLTSD2.c \
../Generated_Code/FreeCntrLdd1.c \
../Generated_Code/HIN1.c \
../Generated_Code/HIN2.c \
../Generated_Code/LIN1.c \
../Generated_Code/LIN2.c \
../Generated_Code/MODE_ENG.c \
../Generated_Code/MOTEC_GEAR_SIG.c \
../Generated_Code/NEUT_SW.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PTA.c \
../Generated_Code/ROT_SW_P1.c \
../Generated_Code/ROT_SW_P2.c \
../Generated_Code/ROT_SW_P3.c \
../Generated_Code/SHIFT_LEV_ANGLE.c \
../Generated_Code/SH_DN.c \
../Generated_Code/SH_UP.c \
../Generated_Code/TEMP1.c \
../Generated_Code/TEMP2.c \
../Generated_Code/TU1.c \
../Generated_Code/UART0.c \
../Generated_Code/VREF.c 

OBJS += \
./Generated_Code/ADC0.o \
./Generated_Code/CLUTCH_SW.o \
./Generated_Code/Cpu.o \
./Generated_Code/FC1.o \
./Generated_Code/FLTCLR1.o \
./Generated_Code/FLTCLR2.o \
./Generated_Code/FLTSD1.o \
./Generated_Code/FLTSD2.o \
./Generated_Code/FreeCntrLdd1.o \
./Generated_Code/HIN1.o \
./Generated_Code/HIN2.o \
./Generated_Code/LIN1.o \
./Generated_Code/LIN2.o \
./Generated_Code/MODE_ENG.o \
./Generated_Code/MOTEC_GEAR_SIG.o \
./Generated_Code/NEUT_SW.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PTA.o \
./Generated_Code/ROT_SW_P1.o \
./Generated_Code/ROT_SW_P2.o \
./Generated_Code/ROT_SW_P3.o \
./Generated_Code/SHIFT_LEV_ANGLE.o \
./Generated_Code/SH_DN.o \
./Generated_Code/SH_UP.o \
./Generated_Code/TEMP1.o \
./Generated_Code/TEMP2.o \
./Generated_Code/TU1.o \
./Generated_Code/UART0.o \
./Generated_Code/VREF.o 

C_DEPS += \
./Generated_Code/ADC0.d \
./Generated_Code/CLUTCH_SW.d \
./Generated_Code/Cpu.d \
./Generated_Code/FC1.d \
./Generated_Code/FLTCLR1.d \
./Generated_Code/FLTCLR2.d \
./Generated_Code/FLTSD1.d \
./Generated_Code/FLTSD2.d \
./Generated_Code/FreeCntrLdd1.d \
./Generated_Code/HIN1.d \
./Generated_Code/HIN2.d \
./Generated_Code/LIN1.d \
./Generated_Code/LIN2.d \
./Generated_Code/MODE_ENG.d \
./Generated_Code/MOTEC_GEAR_SIG.d \
./Generated_Code/NEUT_SW.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PTA.d \
./Generated_Code/ROT_SW_P1.d \
./Generated_Code/ROT_SW_P2.d \
./Generated_Code/ROT_SW_P3.d \
./Generated_Code/SHIFT_LEV_ANGLE.d \
./Generated_Code/SH_DN.d \
./Generated_Code/SH_UP.d \
./Generated_Code/TEMP1.d \
./Generated_Code/TEMP2.d \
./Generated_Code/TU1.d \
./Generated_Code/UART0.d \
./Generated_Code/VREF.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/Static_Code/PDD" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/Static_Code/IO_Map" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/Sources" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


