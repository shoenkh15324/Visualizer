################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/api/lcd/lcd_fonts.c \
../Core/api/lcd/ssd1306.c \
../Core/api/lcd/st7735.c 

OBJS += \
./Core/api/lcd/lcd_fonts.o \
./Core/api/lcd/ssd1306.o \
./Core/api/lcd/st7735.o 

C_DEPS += \
./Core/api/lcd/lcd_fonts.d \
./Core/api/lcd/ssd1306.d \
./Core/api/lcd/st7735.d 


# Each subdirectory must supply rules for building sources it contributes
Core/api/lcd/%.o Core/api/lcd/%.su Core/api/lcd/%.cyclo: ../Core/api/lcd/%.c Core/api/lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/source" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FatFs/src" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/fatfs" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/hangul" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/lcd" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/mp3" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/CMSIS/DSP/Include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FreeRTOS/Source/include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FreeRTOS/Source/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-api-2f-lcd

clean-Core-2f-api-2f-lcd:
	-$(RM) ./Core/api/lcd/lcd_fonts.cyclo ./Core/api/lcd/lcd_fonts.d ./Core/api/lcd/lcd_fonts.o ./Core/api/lcd/lcd_fonts.su ./Core/api/lcd/ssd1306.cyclo ./Core/api/lcd/ssd1306.d ./Core/api/lcd/ssd1306.o ./Core/api/lcd/ssd1306.su ./Core/api/lcd/st7735.cyclo ./Core/api/lcd/st7735.d ./Core/api/lcd/st7735.o ./Core/api/lcd/st7735.su

.PHONY: clean-Core-2f-api-2f-lcd

