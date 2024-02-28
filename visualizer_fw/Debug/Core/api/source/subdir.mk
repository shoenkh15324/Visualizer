################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/api/source/cdc.c \
../Core/api/source/cli.c 

OBJS += \
./Core/api/source/cdc.o \
./Core/api/source/cli.o 

C_DEPS += \
./Core/api/source/cdc.d \
./Core/api/source/cli.d 


# Each subdirectory must supply rules for building sources it contributes
Core/api/source/%.o Core/api/source/%.su Core/api/source/%.cyclo: ../Core/api/source/%.c Core/api/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-api-2f-source

clean-Core-2f-api-2f-source:
	-$(RM) ./Core/api/source/cdc.cyclo ./Core/api/source/cdc.d ./Core/api/source/cdc.o ./Core/api/source/cdc.su ./Core/api/source/cli.cyclo ./Core/api/source/cli.d ./Core/api/source/cli.o ./Core/api/source/cli.su

.PHONY: clean-Core-2f-api-2f-source

