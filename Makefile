#############################################################  
# Generic Makefile for C/C++ Program  
#   
# Author:  wind.kaisa@gmail.com 
# Date:    2016/12/17 (version 0.1)   
#  
#############################################################  

#this is the name of this project
TARGET = pictopdf

#head files   
INCLUDES += -I./inc

#sources files (*.c *.cpp)
SOURCES += ./main.cpp

#objects 
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

#libs path
MY_LIBS_PATH += 

#libs
MY_LIBS += -lSDL2


export DEBUG

#C Compiler
CC = gcc
#C++ Compiler
CXX = g++
#delete files
RM = rm -f
#C's flags
CFLAGS = -g -Wall -O0
#c++'s flags
CXXFLAGS = -g -Wall -std=c++11

.PHONY:all
#all projects will be compiled
all: $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(MY_LIBS_PATH) $(MY_LIBS) -o $@ 

#all objects will be compiled
objs:$(OBJECTS)
%.o : %.c  
	$(CC) $< -o $@ $(MY_LIBS_PATH) $(MY_LIBS)

%.o : %.C  
	$(CC) $< -o $@ $(MY_LIBS_PATH) $(MY_LIBS)

%.o : %.cpp 
	$(CXX) $< -o $@ $(MY_LIBS_PATH) $(MY_LIBS)

%.o : %.CPP
	$(CXX) $< -o $@ $(MY_LIBS_PATH) $(MY_LIBS)

#clean all objects and targets
clean:
	$(RM) $(OBJECTS) $(TARGET)

#some params
help:
	@echo 'TARGET       :' $(TARGET)  
	@echo 'CXXFLAGS     :' $(CXXFLAGS)  
	@echo 'INCLUDES     :' $(INCLUDES)  
	@echo 'SOURCES      :' $(SOURCES)  
	@echo 'OBJECTS      :' $(OBJECTS)  
	@echo 'CFLAGS       :' $(CFLAGS)  
