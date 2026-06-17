################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SOIL_SENSOR_DRIVER/Src/SOIL_SENSOR.c 

OBJS += \
./Drivers/SOIL_SENSOR_DRIVER/Src/SOIL_SENSOR.o 

C_DEPS += \
./Drivers/SOIL_SENSOR_DRIVER/Src/SOIL_SENSOR.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SOIL_SENSOR_DRIVER/Src/SOIL_SENSOR.o: ../Drivers/SOIL_SENSOR_DRIVER/Src/SOIL_SENSOR.c Drivers/SOIL_SENSOR_DRIVER/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F302x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-SOIL_SENSOR_DRIVER-2f-Src

clean-Drivers-2f-SOIL_SENSOR_DRIVER-2f-Src:
	-$(RM) ./Drivers/SOIL_SENSOR_DRIVER/Src/SOIL_SENSOR.cyclo ./Drivers/SOIL_SENSOR_DRIVER/Src/SOIL_SENSOR.d ./Drivers/SOIL_SENSOR_DRIVER/Src/SOIL_SENSOR.o ./Drivers/SOIL_SENSOR_DRIVER/Src/SOIL_SENSOR.su

.PHONY: clean-Drivers-2f-SOIL_SENSOR_DRIVER-2f-Src

