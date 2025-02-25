TARGET=dinic
CC=g++
CFLAGS= -std=c++17 -Wall -O2 -o
SRCS= dinic.cpp
HDRS= dinic.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(SRCS) $(CFLAGS) $(TARGET)

clean:
	rm -rf *.o $(TARGET)
