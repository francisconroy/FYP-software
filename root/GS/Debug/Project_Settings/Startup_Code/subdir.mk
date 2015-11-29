################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Settings/Startup_Code/startup.c 

OBJS += \
./Project_Settings/Startup_Code/startup.o 

C_DEPS += \
./Project_Settings/Startup_Code/startup.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/%.o: ../Project_Settings/Startup_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/Static_Code/PDD" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/Static_Code/IO_Map" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/Sources" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/Generated_Code" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/MQXLITE/include" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/MQXLITE/config" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/MQXLITE/kernel" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/MQXLITE/psp/cortex_m" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/MQXLITE/psp/cortex_m/core/M4" -I"/Users/francisconroy/Documents/repos/FYP-software/root/GS/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


