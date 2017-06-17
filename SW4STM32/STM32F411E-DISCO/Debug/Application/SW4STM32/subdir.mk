################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Projects/STM32F411E-Discovery/Applications/Audio/Audio_playback_and_record/SW4STM32/startup_stm32f411xe.s 

OBJS += \
./Application/SW4STM32/startup_stm32f411xe.o 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32f411xe.o: /home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Projects/STM32F411E-Discovery/Applications/Audio/Audio_playback_and_record/SW4STM32/startup_stm32f411xe.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


