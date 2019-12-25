################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ant.cpp \
../src/AntHill.cpp \
../src/LinkedList.cpp \
../src/Program1.cpp 

OBJS += \
./src/Ant.o \
./src/AntHill.o \
./src/LinkedList.o \
./src/Program1.o 

CPP_DEPS += \
./src/Ant.d \
./src/AntHill.d \
./src/LinkedList.d \
./src/Program1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


