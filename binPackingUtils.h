#ifndef BIN_PACKING_UTILS_H_
#define BIN_PACKING_UTILS_H_

#include "binPacking.h"
using namespace std;

class binPackingUtils {
    public: 
        static vector<binPacking::bin> nextFit(const int* values, int size);
        static vector<binPacking::bin> bestFitOnline(const int* values, int size);
        static vector<binPacking::bin> bestFitOffline(int* values, int size);
        static vector<binPacking::bin> firstFitOnline(const int* values, int size);
        static vector<binPacking::bin> firstFitOffline(int* values, int size);
        static void outputBins(const vector<binPacking::bin>& bins);
};

#endif