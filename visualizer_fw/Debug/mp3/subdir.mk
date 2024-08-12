################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mp3/bitstream.c \
../mp3/buffers.c \
../mp3/dct32.c \
../mp3/dequant.c \
../mp3/dqchan.c \
../mp3/huffman.c \
../mp3/hufftabs.c \
../mp3/imdct.c \
../mp3/mp3dec.c \
../mp3/mp3tabs.c \
../mp3/polyphase.c \
../mp3/scalfact.c \
../mp3/stproc.c \
../mp3/subband.c \
../mp3/trigtabs.c 

OBJS += \
./mp3/bitstream.o \
./mp3/buffers.o \
./mp3/dct32.o \
./mp3/dequant.o \
./mp3/dqchan.o \
./mp3/huffman.o \
./mp3/hufftabs.o \
./mp3/imdct.o \
./mp3/mp3dec.o \
./mp3/mp3tabs.o \
./mp3/polyphase.o \
./mp3/scalfact.o \
./mp3/stproc.o \
./mp3/subband.o \
./mp3/trigtabs.o 

C_DEPS += \
./mp3/bitstream.d \
./mp3/buffers.d \
./mp3/dct32.d \
./mp3/dequant.d \
./mp3/dqchan.d \
./mp3/huffman.d \
./mp3/hufftabs.d \
./mp3/imdct.d \
./mp3/mp3dec.d \
./mp3/mp3tabs.d \
./mp3/polyphase.d \
./mp3/scalfact.d \
./mp3/stproc.d \
./mp3/subband.d \
./mp3/trigtabs.d 


# Each subdirectory must supply rules for building sources it contributes
mp3/%.o mp3/%.su mp3/%.cyclo: ../mp3/%.c mp3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/source" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FatFs/src" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/fatfs" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/hangul" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/Core/api/lcd" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/mp3" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/CMSIS/DSP/Include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FreeRTOS/Source/include" -I"C:/Users/mok07/Desktop/Study/Project/STM32CUBEIDE_project/visualizer/visualizer_fw/FreeRTOS/Source/portable/GCC/ARM_CM4F" -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mp3

clean-mp3:
	-$(RM) ./mp3/bitstream.cyclo ./mp3/bitstream.d ./mp3/bitstream.o ./mp3/bitstream.su ./mp3/buffers.cyclo ./mp3/buffers.d ./mp3/buffers.o ./mp3/buffers.su ./mp3/dct32.cyclo ./mp3/dct32.d ./mp3/dct32.o ./mp3/dct32.su ./mp3/dequant.cyclo ./mp3/dequant.d ./mp3/dequant.o ./mp3/dequant.su ./mp3/dqchan.cyclo ./mp3/dqchan.d ./mp3/dqchan.o ./mp3/dqchan.su ./mp3/huffman.cyclo ./mp3/huffman.d ./mp3/huffman.o ./mp3/huffman.su ./mp3/hufftabs.cyclo ./mp3/hufftabs.d ./mp3/hufftabs.o ./mp3/hufftabs.su ./mp3/imdct.cyclo ./mp3/imdct.d ./mp3/imdct.o ./mp3/imdct.su ./mp3/mp3dec.cyclo ./mp3/mp3dec.d ./mp3/mp3dec.o ./mp3/mp3dec.su ./mp3/mp3tabs.cyclo ./mp3/mp3tabs.d ./mp3/mp3tabs.o ./mp3/mp3tabs.su ./mp3/polyphase.cyclo ./mp3/polyphase.d ./mp3/polyphase.o ./mp3/polyphase.su ./mp3/scalfact.cyclo ./mp3/scalfact.d ./mp3/scalfact.o ./mp3/scalfact.su ./mp3/stproc.cyclo ./mp3/stproc.d ./mp3/stproc.o ./mp3/stproc.su ./mp3/subband.cyclo ./mp3/subband.d ./mp3/subband.o ./mp3/subband.su ./mp3/trigtabs.cyclo ./mp3/trigtabs.d ./mp3/trigtabs.o ./mp3/trigtabs.su

.PHONY: clean-mp3

