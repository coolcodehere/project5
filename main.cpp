#include "binPackingUtils.h"
#include "binPacking.h"
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 


void generateRandomData(int* data) {
    for (int i = 0; i < 100; i++) {
        data[i] = rand() % 100;
    }
}

int main() {
    int data[100];
    srand (time(NULL));

    for (int i = 0; i < 10; i++) {
        cout << "RUN " << i + 1 << ": " << endl;
        generateRandomData(data);
        // auto nextFitResults = binPackingUtils::nextFit(data, 100);
        // auto bestFitOnlineResults = binPackingUtils::bestFitOnline(data, 100);
        // auto bestFitOfflineResults = binPackingUtils::bestFitOffline(data, 100);
        // auto firstFitOnlineResults = binPackingUtils::firstFitOnline(data, 100);
        auto firstFitOfflineResults = binPackingUtils::firstFitOffline(data, 100);

        // cout << "Bin Counts: " << endl << endl;
        // cout << "\tNext Fit: " << nextFitResults.size() << " bins" << endl;
        // cout << "\tBest Fit Offline: " << bestFitOnlineResults.size() << " bins" << endl;
        // cout << "\tBest Fit Online: " << bestFitOfflineResults.size() << " bins" << endl;
        // cout << "\tFirst Fit Offline: " << firstFitOnlineResults.size() << " bins" << endl;
        // cout << "\tFirst Fit Online: " << firstFitOfflineResults.size() << " bins" << endl;

    }
}