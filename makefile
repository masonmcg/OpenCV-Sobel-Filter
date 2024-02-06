CC = g++
CFLAGS = -Wall -std=c++11 $(shell pkg-config --cflags opencv4)
LIBS = $(shell pkg-config --libs opencv4)

all: sobel_filter

sobel_filter: sobel_filter.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f sobel_filter