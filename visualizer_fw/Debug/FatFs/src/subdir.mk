################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FatFs/src/diskio.c \
../FatFs/src/ff.c \
../FatFs/src/ff_gen_drv.c 

OBJS += \
./FatFs/src/diskio.o \
./FatFs/src/ff.o \
./FatFs/src/ff_gen_drv.o 

C_DEPS += \
./FatFs/src/diskio.d \
./FatFs/src/ff.d \
./FatFs/src/ff_gen_drv.d 


# Each subdirectory must supply rules for building sources it contributes
FatFs/src/%.o FatFs/src/%.su FatFs/src/%.cyclo: ../FatFs/src/%.c FatFs/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/source" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FatFs/src" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/fatfs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FatFs-2f-src

clean-FatFs-2f-src:
	-$(RM) ./FatFs/src/diskio.cyclo ./FatFs/src/diskio.d ./FatFs/src/diskio.o ./FatFs/src/diskio.su ./FatFs/src/ff.cyclo ./FatFs/src/ff.d ./FatFs/src/ff.o ./FatFs/src/ff.su ./FatFs/src/ff_gen_drv.cyclo ./FatFs/src/ff_gen_drv.d ./FatFs/src/ff_gen_drv.o ./FatFs/src/ff_gen_drv.su

.PHONY: clean-FatFs-2f-src

