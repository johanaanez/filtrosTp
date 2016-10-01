################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DilationFilter.cpp \
../src/ErosionFilter.cpp \
../src/Filter.cpp \
../src/Image.cpp \
../src/Pattern.cpp \
../src/Thread.cpp \
../src/tp.cpp 

OBJS += \
./src/DilationFilter.o \
./src/ErosionFilter.o \
./src/Filter.o \
./src/Image.o \
./src/Pattern.o \
./src/Thread.o \
./src/tp.o 

CPP_DEPS += \
./src/DilationFilter.d \
./src/ErosionFilter.d \
./src/Filter.d \
./src/Image.d \
./src/Pattern.d \
./src/Thread.d \
./src/tp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


