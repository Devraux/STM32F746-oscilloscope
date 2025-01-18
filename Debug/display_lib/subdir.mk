################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../display_lib/display.c 

OBJS += \
./display_lib/display.o 

C_DEPS += \
./display_lib/display.d 


# Each subdirectory must supply rules for building sources it contributes
display_lib/%.o display_lib/%.su display_lib/%.cyclo: ../display_lib/%.c display_lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SIMPLE -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/lvgl -I../Core/Src/ui -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/krzys/STM32CubeIDE/workspace_1.13.0/STM_Discovery_Oscilloscope/display_lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-display_lib

clean-display_lib:
	-$(RM) ./display_lib/display.cyclo ./display_lib/display.d ./display_lib/display.o ./display_lib/display.su

.PHONY: clean-display_lib

