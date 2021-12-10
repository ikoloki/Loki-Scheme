# the compiler: gcc for C program, define as g++ for C++
  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings

CC = gcc
CXX = g++
CRUNFLAGS = -o
CDEBUGFLAGS = -g3 -Wall -O0 -o 
RMRF = rm -rf
TARGET = main
R = ./
CLS = clear

SOURCES =$(wildcard *.cpp tokenizer/*.cpp compiler/*.cpp)
ASMSOURCES =$(wildcard *.s)

.PHONY: all clean debug pretty
all:
	make $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) --std=c++17 $(CRUNFLAGS) $(TARGET) $(SOURCES)
	$(R)$(TARGET)
clean:	
	-$(RMRF) $(TARGET) $(ASMSOURCES)
debug:
	$(CXX) $(CDEBUGFLAGS) $(TARGET) $(SOURCES)