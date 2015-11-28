################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MQXLITE/config/task_template_list.c 

OBJS += \
./MQXLITE/config/task_template_list.o 

C_DEPS += \
./MQXLITE/config/task_template_list.d 


# Each subdirectory must supply rules for building sources it contributes
MQXLITE/config/%.o: ../MQXLITE/config/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/Static_Code/PDD" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/Static_Code/IO_Map" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/Sources" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/Generated_Code" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/include" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/config" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/kernel" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/psp/cortex_m" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/psp/cortex_m/core/M4" -I"/Users/francisconroy/Documents/repos/FYP-software/root/ETC/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


