#ifndef BIN_PACKING_H_
#define BIN_PACKING_H_

#include <iostream>
#include <vector> 
using namespace std;

// This class is all bins idiot
class binPacking {
    public:
        struct bin {
            int sum = 0; 
            int capacity = 100;
            vector<int> bin; 
        };

        vector<bin> bins;
};

#endif