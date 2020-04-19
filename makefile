make: main.o binPacking.o
	g++ main.o binPackingUtils.o -o output

binPacking.o: binPackingUtils.cpp binPackingUtils.h binPacking.h
	g++ -c binPackingUtils.cpp

main.o: main.cpp
	g++ -c main.cpp