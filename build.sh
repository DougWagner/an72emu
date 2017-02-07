#!/bin/bash
# this is a horrible build script that only exists because i don't know how to write makefiles

#g++ -std=c++11 -c src/ReadOnlyMemory.cpp -o src/ReadOnlyMemory.o -Wall
#g++ -std=c++11 -c src/RandomAccessMemory.cpp -o src/RandomAccessMemory.o -Wall
#g++ -std=c++11 -c src/cpu.cpp -o src/cpu.o -Wall
#g++ -std=c++11 -c src/main.cpp -o src/main.o -Wall
g++ -std=c++11 -o an72emu src/main.cpp src/cpu.cpp src/ReadOnlyMemory.cpp src/RandomAccessMemory.cpp -Wall
