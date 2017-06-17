################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c \
/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c \
/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c 

OBJS += \
./Middlewares/STM32_USBH_Library/Class/MSC/usbh_msc.o \
./Middlewares/STM32_USBH_Library/Class/MSC/usbh_msc_bot.o \
./Middlewares/STM32_USBH_Library/Class/MSC/usbh_msc_scsi.o 

C_DEPS += \
./Middlewares/STM32_USBH_Library/Class/MSC/usbh_msc.d \
./Middlewares/STM32_USBH_Library/Class/MSC/usbh_msc_bot.d \
./Middlewares/STM32_USBH_Library/Class/MSC/usbh_msc_scsi.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STM32_USBH_Library/Class/MSC/usbh_msc.o: /home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F411xE -DUSE_STM32F411E_DISCO -D__FPU_PRESENT -DARM_MATH_CM4 -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Projects/STM32F411E-Discovery/Applications/Audio/Audio_playback_and_record/Inc" -I/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Include -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Include" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/BSP/STM32F411E-Discovery" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_Audio/Addons/PDM" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/Third_Party/FatFs/src" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/Third_Party/FatFs/src/drivers"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/STM32_USBH_Library/Class/MSC/usbh_msc_bot.o: /home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F411xE -DUSE_STM32F411E_DISCO -D__FPU_PRESENT -DARM_MATH_CM4 -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Projects/STM32F411E-Discovery/Applications/Audio/Audio_playback_and_record/Inc" -I/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Include -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Include" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/BSP/STM32F411E-Discovery" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_Audio/Addons/PDM" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/Third_Party/FatFs/src" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/Third_Party/FatFs/src/drivers"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/STM32_USBH_Library/Class/MSC/usbh_msc_scsi.o: /home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F411xE -DUSE_STM32F411E_DISCO -D__FPU_PRESENT -DARM_MATH_CM4 -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Projects/STM32F411E-Discovery/Applications/Audio/Audio_playback_and_record/Inc" -I/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Include -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Include" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Drivers/BSP/STM32F411E-Discovery" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/ST/STM32_Audio/Addons/PDM" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/Third_Party/FatFs/src" -I"/home/pampa/dev-folder/embedded/stm32/STM32Cube_FW_F4_V1.15.0/Middlewares/Third_Party/FatFs/src/drivers"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


