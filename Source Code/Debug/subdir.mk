################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Demo.cpp \
../Edge.cpp \
../Graph.cpp \
../GraphIllegalAccessException.cpp \
../GraphInvalidInsertionException.cpp \
../Node.cpp \
../RandomEdge.cpp \
../RandomGraph.cpp 

OBJS += \
./Demo.o \
./Edge.o \
./Graph.o \
./GraphIllegalAccessException.o \
./GraphInvalidInsertionException.o \
./Node.o \
./RandomEdge.o \
./RandomGraph.o 

CPP_DEPS += \
./Demo.d \
./Edge.d \
./Graph.d \
./GraphIllegalAccessException.d \
./GraphInvalidInsertionException.d \
./Node.d \
./RandomEdge.d \
./RandomGraph.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


