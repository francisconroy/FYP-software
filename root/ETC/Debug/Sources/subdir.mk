################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/MPI.c \
../Sources/SCI.c \
../Sources/main.c 

OBJS += \
./Sources/Events.o \
./Sources/MPI.o \
./Sources/SCI.o \
./Sources/main.o 

C_DEPS += \
./Sources/Events.d \
./Sources/MPI.d \
./Sources/SCI.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"D:/Users/Josh/Documents/GitHub/FYP-software/root/ETC/Static_Code/PDD" -I"D:/Users/Josh/Documents/GitHub/FYP-software/root/ETC/Static_Code/IO_Map" -I"D:/Users/Josh/Documents/GitHub/FYP-software/root/ETC/Sources" -I"D:/Users/Josh/Documents/GitHub/FYP-software/root/ETC/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


