################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/STM32_USBH_Library/Core/subdir.mk
-include Middlewares/STM32_USBH_Library/Class/MSC/subdir.mk
-include Middlewares/FatFs/Options/subdir.mk
-include Middlewares/FatFs/Drivers/subdir.mk
-include Middlewares/FatFs/Core/subdir.mk
-include Drivers/STM32F4xx_HAL_Drivers/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/STM32F411E-Discovery/subdir.mk
-include Drivers/BSP/Components/subdir.mk
-include Application/User/subdir.mk
-include Application/SW4STM32/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: STM32F411E-DISCO.elf

# Tool invocations
STM32F411E-DISCO.elf: $(OBJS) $(USER_OBJS) /home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Projects/STM32F411E-Discovery/Applications/Audio/Audio_playback_and_record/SW4STM32/STM32F411E-DISCO/STM32F411VETx_FLASH.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -L/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_Audio/Addons/PDM -L"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Lib/GCC" -specs=nosys.specs -specs=nano.specs -specs=rdimon.specs -lc -lrdimon -T"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Projects/STM32F411E-Discovery/Applications/Audio/Audio_playback_and_record/SW4STM32/STM32F411E-DISCO/STM32F411VETx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -lm -o "STM32F411E-DISCO.elf" @"objects.list" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "STM32F411E-DISCO.elf" "STM32F411E-DISCO.bin"
	arm-none-eabi-size "STM32F411E-DISCO.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
