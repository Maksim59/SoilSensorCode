################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/SOIL-SENSOR.c 

OBJS += \
./Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/SOIL-SENSOR.o 

C_DEPS += \
./Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/SOIL-SENSOR.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/%.o Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/%.su Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/%.cyclo: ../Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/%.c Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F302x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-TH-2d-NPK-2d-SOIL-2d-SENSOR-2d-DRIVER-2f-Src

clean-Drivers-2f-TH-2d-NPK-2d-SOIL-2d-SENSOR-2d-DRIVER-2f-Src:
	-$(RM) ./Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/SOIL-SENSOR.cyclo ./Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/SOIL-SENSOR.d ./Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/SOIL-SENSOR.o ./Drivers/TH-NPK-SOIL-SENSOR-DRIVER/Src/SOIL-SENSOR.su

.PHONY: clean-Drivers-2f-TH-2d-NPK-2d-SOIL-2d-SENSOR-2d-DRIVER-2f-Src

