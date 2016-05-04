CC := gcc
CXX := g++

CFLAGS := -O0 -g 
CXXFLAGS := -O0 -g -std=c++11

OBJ := cmap_test cmap
OBJS := $(addsuffix .o,$(OBJ))

TARGET := cmap_test_exe

all:
	make compile

compile:
	@echo "Compiling ..."
	-make $(OBJS)
	-make $(TARGET)

$(TARGET): $(OBJS)
	-$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	-./$(TARGET)

cmap_test.o: cmap_test.c
	-$(CC) $(CFLAGS) -c -o cmap_test.o cmap_test.c

cmap.o: cmap.cpp
	-$(CXX) $(CXXFLAGS) -c -o cmap.o cmap.cpp

clean:
	-rm -rf *.o $(TARGET)