################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FatFs/src/option/syscall.c \
../FatFs/src/option/unicode.c 

OBJS += \
./FatFs/src/option/syscall.o \
./FatFs/src/option/unicode.o 

C_DEPS += \
./FatFs/src/option/syscall.d \
./FatFs/src/option/unicode.d 


# Each subdirectory must supply rules for building sources it contributes
FatFs/src/option/%.o FatFs/src/option/%.su FatFs/src/option/%.cyclo: ../FatFs/src/option/%.c FatFs/src/option/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/source" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FatFs/src" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/fatfs" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/hangul" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/lcd" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FatFs-2f-src-2f-option

clean-FatFs-2f-src-2f-option:
	-$(RM) ./FatFs/src/option/syscall.cyclo ./FatFs/src/option/syscall.d ./FatFs/src/option/syscall.o ./FatFs/src/option/syscall.su ./FatFs/src/option/unicode.cyclo ./FatFs/src/option/unicode.d ./FatFs/src/option/unicode.o ./FatFs/src/option/unicode.su

.PHONY: clean-FatFs-2f-src-2f-option

