CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRCS = main.cc
OBJS = $(SRCS:.cc=.o)

TARGET = ~/practicas/practica_1

all: $(TARGET)

$(TARGET): $(OBJS) | bin
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin:
	mkdir -p bin

clean:
	rm -f *.o $(TARGET)
	rm -rf bin

.PHONY: all clean