################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../distribs.c \
../main.c \
../network.c \
../sleeping.c \
../transmission.c 

OBJS += \
./distribs.o \
./main.o \
./network.o \
./sleeping.o \
./transmission.o 

C_DEPS += \
./distribs.d \
./main.d \
./network.d \
./sleeping.d \
./transmission.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


