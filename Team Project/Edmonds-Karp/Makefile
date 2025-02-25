CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
TARGET = edmonds
SRCS = main.cpp edmonds.cpp
HDRS = edmonds.h
OBJS = main.o edmonds.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

