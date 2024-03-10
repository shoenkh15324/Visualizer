################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/api/source/cdc.c \
../Core/api/source/cli.c \
../Core/api/source/fatfs.c \
../Core/api/source/gpio_api.c \
../Core/api/source/lcd.c \
../Core/api/source/led.c \
../Core/api/source/sd.c \
../Core/api/source/spi_api.c \
../Core/api/source/uart.c 

OBJS += \
./Core/api/source/cdc.o \
./Core/api/source/cli.o \
./Core/api/source/fatfs.o \
./Core/api/source/gpio_api.o \
./Core/api/source/lcd.o \
./Core/api/source/led.o \
./Core/api/source/sd.o \
./Core/api/source/spi_api.o \
./Core/api/source/uart.o 

C_DEPS += \
./Core/api/source/cdc.d \
./Core/api/source/cli.d \
./Core/api/source/fatfs.d \
./Core/api/source/gpio_api.d \
./Core/api/source/lcd.d \
./Core/api/source/led.d \
./Core/api/source/sd.d \
./Core/api/source/spi_api.d \
./Core/api/source/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/api/source/%.o Core/api/source/%.su Core/api/source/%.cyclo: ../Core/api/source/%.c Core/api/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/source" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FatFs/src" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/fatfs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-api-2f-source

clean-Core-2f-api-2f-source:
	-$(RM) ./Core/api/source/cdc.cyclo ./Core/api/source/cdc.d ./Core/api/source/cdc.o ./Core/api/source/cdc.su ./Core/api/source/cli.cyclo ./Core/api/source/cli.d ./Core/api/source/cli.o ./Core/api/source/cli.su ./Core/api/source/fatfs.cyclo ./Core/api/source/fatfs.d ./Core/api/source/fatfs.o ./Core/api/source/fatfs.su ./Core/api/source/gpio_api.cyclo ./Core/api/source/gpio_api.d ./Core/api/source/gpio_api.o ./Core/api/source/gpio_api.su ./Core/api/source/lcd.cyclo ./Core/api/source/lcd.d ./Core/api/source/lcd.o ./Core/api/source/lcd.su ./Core/api/source/led.cyclo ./Core/api/source/led.d ./Core/api/source/led.o ./Core/api/source/led.su ./Core/api/source/sd.cyclo ./Core/api/source/sd.d ./Core/api/source/sd.o ./Core/api/source/sd.su ./Core/api/source/spi_api.cyclo ./Core/api/source/spi_api.d ./Core/api/source/spi_api.o ./Core/api/source/spi_api.su ./Core/api/source/uart.cyclo ./Core/api/source/uart.d ./Core/api/source/uart.o ./Core/api/source/uart.su

.PHONY: clean-Core-2f-api-2f-source

