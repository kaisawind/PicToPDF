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
INCLUDES += -I./inc/
INCLUDES += -I./

#sources files (*.c *.cpp)
SOURCES += ./src/Picture.cpp
SOURCES += ./src/Bmp.cpp
SOURCES += ./src/Images.cpp
SOURCES += ./src/File.cpp
SOURCES += ./main.cpp

#objects 
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

#libs path
MY_LIBS_PATH += 

#libs
#MY_LIBS += -lSDL2
MY_LIBS +=


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
CXXFLAGS = -g -Wall 

.PHONY:all
#all projects will be compiled
all: objs $(TARGET)
$(TARGET) :
	$(CXX) $(OBJECTS) $(CXXFLAGS) $(MY_LIBS_PATH) $(MY_LIBS) $(INCLUDES) -o $@ 

#all objects will be compiled
objs:$(OBJECTS)
%.o : %.c  
	$(CC) -c $< -o $@ $(INCLUDES)

%.o : %.C  
	$(CC) -c $< -o $@ $(INCLUDES)

%.o : %.cpp 
	$(CXX) -c $< -o $@ $(INCLUDES)

%.o : %.CPP
	$(CXX) -c $< -o $@ $(INCLUDES)

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
