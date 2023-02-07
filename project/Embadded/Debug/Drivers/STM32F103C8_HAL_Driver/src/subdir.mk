################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F103C8_HAL_Driver/src/GPIO.c 

OBJS += \
./Drivers/STM32F103C8_HAL_Driver/src/GPIO.o 

C_DEPS += \
./Drivers/STM32F103C8_HAL_Driver/src/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F103C8_HAL_Driver/src/%.o Drivers/STM32F103C8_HAL_Driver/src/%.su: ../Drivers/STM32F103C8_HAL_Driver/src/%.c Drivers/STM32F103C8_HAL_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Project_Grad/graduation-project/project/Embadded/Drivers/STM32F103C8_HAL_Driver/inc" -I"D:/EmbadedSystemDiploma/C_Programming/embedded_System_Online_Diploma/C_Programming/unit7/lec3_section/HAl/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F103C8_HAL_Driver-2f-src

clean-Drivers-2f-STM32F103C8_HAL_Driver-2f-src:
	-$(RM) ./Drivers/STM32F103C8_HAL_Driver/src/GPIO.d ./Drivers/STM32F103C8_HAL_Driver/src/GPIO.o ./Drivers/STM32F103C8_HAL_Driver/src/GPIO.su

.PHONY: clean-Drivers-2f-STM32F103C8_HAL_Driver-2f-src

