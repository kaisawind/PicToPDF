#############################################################  
# Generic Makefile for C/C++ Program  
#   
# Author:  wind.kaisa@gmail.com 
# Date:    2016/12/17 (version 0.1)   
#  
#############################################################  

export DEBUG
#head files   
INCLUDES += ./inc
#sources files (*.c *.cpp)
SOURCES += ./main.cpp

OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

MY_LIBS = 

#C Compiler
CC = gcc
#C++ Compiler
CXX = g++
#delete files
RM = rm -f

CFLAGS = -g -Wall -O0
CXXFLAGS = -c -g -Wall -std=c++11


TARGET = test

.PHONY:all

all: $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(MY_LIBS) -o $@  

objs:$(OBJECTS)
%.o : %.c  
	$(CC) $< -o $@

%.o : %.C  
	$(CC) $< -o $@ 

%.o : %.cpp 
	$(CXX) $< -o $@ 


clean:
	$(RM) $(OBJECTS) $(TARGET)

help:
	@echo 'TARGET       :' $(TARGET)  
	@echo 'CXXFLAGS     :' $(CXXFLAGS)  
	@echo 'INCLUDES     :' $(INCLUDES)  
	@echo 'SOURCES      :' $(SOURCES)  
	@echo 'OBJECTS      :' $(OBJECTS)  
	@echo 'CFLAGS       :' $(CFLAGS)  
