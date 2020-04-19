#include "binPackingUtils.h"
#include "binPacking.h"
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>


void generateRandomData(int* data) {
    for (int i = 0; i < 100; i++) {
        data[i] = rand() % 100;
    }
}

int main() {
    int data[100] = {0};
    int averageBins[5] = {0};
    int bestCounts[5] = {0};
    int results[5] = {0};
    srand (time(NULL));

    for (int i = 0; i < 10; i++) {
        cout << "RUN " << i + 1 << ": " << endl;
        generateRandomData(data);
        auto nextFitResults = binPackingUtils::nextFit(data, 100);
        results[0] = nextFitResults.size();
        averageBins[0] += nextFitResults.size();

        auto bestFitOnlineResults = binPackingUtils::bestFitOnline(data, 100);
        averageBins[1] += bestFitOnlineResults.size();
        results[1] = bestFitOnlineResults.size();

        auto bestFitOfflineResults = binPackingUtils::bestFitOffline(data, 100);
        averageBins[2] += bestFitOfflineResults.size();
        results[2] = bestFitOfflineResults.size();

        auto firstFitOnlineResults = binPackingUtils::firstFitOnline(data, 100);
        averageBins[3] += firstFitOnlineResults.size();
        results[3] = firstFitOnlineResults.size();

        auto firstFitOfflineResults = binPackingUtils::firstFitOffline(data, 100);
        averageBins[4] += firstFitOfflineResults.size();
        results[4] = firstFitOfflineResults.size();

        int min = *min_element(results, results + 5);
        for (int j = 0; j < 5; j++) {
            if (results[j] == min) {
                bestCounts[j]++;
            }
        }

        cout << "Bin Counts: " << endl;
        cout << "\tNext Fit: " << nextFitResults.size() << " bins" << endl;
        cout << "\tBest Fit Offline: " << bestFitOfflineResults.size() << " bins" << endl;
        cout << "\tBest Fit Online: " << bestFitOnlineResults.size() << " bins" << endl;
        cout << "\tFirst Fit Offline: " << firstFitOfflineResults.size() << " bins" << endl;
        cout << "\tFirst Fit Online: " << firstFitOnlineResults.size() << " bins" << endl;
    }

    for (int i = 0; i < 5; i++) {
        averageBins[i] /= 10;
    }

    cout << endl << "-------------------------------------------------" << endl;
    cout << endl << "Average Bins Used: " << endl;
    cout << "\tNext Fit: " << averageBins[0] << " bins" << endl;
    cout << "\tBest Fit Offline: " << averageBins[2] << " bins" << endl;
    cout << "\tBest Fit Online: " << averageBins[1] << " bins" << endl;
    cout << "\tFirst Fit Offline: " << averageBins[4] << " bins" << endl;
    cout << "\tFirst Fit Online: " << averageBins[3] << " bins" << endl;

    cout << endl << "Best Strategy Counts: " << endl;
    cout << "\tNext Fit: " << bestCounts[0] << " times" << endl;
    cout << "\tBest Fit Offline: " << bestCounts[2] << " times" << endl;
    cout << "\tBest Fit Online: " << bestCounts[1] << " times" << endl;
    cout << "\tFirst Fit Offline: " << bestCounts[4] << " times" << endl;
    cout << "\tFirst Fit Online: " << bestCounts[3] << " times" << endl;
}