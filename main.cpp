#include "binPackingUtils.h"
#include "binPacking.h"
#include <vector>
#include <stdio.h> 
#include <stdlib.h>   
#include <time.h> 
#include <algorithm>
#include <fstream>

void generateRandomData(int* data, ofstream& rawdataFile) {
    rawdataFile << "Values" << endl;
    for (int i = 0; i < 100; i++) {
        data[i] = rand() % 100;
        rawdataFile << data[i] << ", ";
    }
}

void printBinContents(vector<binPacking::bin> bins, ofstream& rawdataFile) {
    
    for (int j = 0; j < bins.size(); j++) {
        int sum = 0;
        rawdataFile << "BIN " << j << " CONTENTS: ";
        for (int contentIdx = 0; contentIdx < bins[j].bin.size(); contentIdx++) {
            rawdataFile << bins[j].bin[contentIdx] << " ";
            sum += bins[j].bin[contentIdx];
        }
        rawdataFile << "(SIZE: " << sum << ")" << endl;
    }
}

int main() {
    ofstream rawdataFile;
    ofstream resultsFile;
    rawdataFile.open("rawData.txt", std::ofstream::out | std::ofstream::trunc);
    resultsFile.open("results.txt", std::ofstream::out | std::ofstream::trunc);
    int data[100] = {0};
    int averageBins[5] = {0};
    int bestCounts[5] = {0};
    int results[5] = {0};
    srand (time(NULL));

    for (int i = 0; i < 10; i++) {
        rawdataFile << "RUN " << i << endl;
        generateRandomData(data, rawdataFile);


        auto nextFitResults = binPackingUtils::nextFit(data, 100);
        results[0] = nextFitResults.size();
        averageBins[0] += nextFitResults.size();
        rawdataFile << endl << "NEXT FIT:"<< endl;
        printBinContents(nextFitResults, rawdataFile);
        
        auto bestFitOnlineResults = binPackingUtils::bestFitOnline(data, 100);
        averageBins[1] += bestFitOnlineResults.size();
        results[1] = bestFitOnlineResults.size();
        rawdataFile << endl << "BEST FIT ONLINE:"<< endl;
        printBinContents(bestFitOnlineResults, rawdataFile);

        auto bestFitOfflineResults = binPackingUtils::bestFitOffline(data, 100);
        averageBins[2] += bestFitOfflineResults.size();
        results[2] = bestFitOfflineResults.size();
        rawdataFile << endl << "BEST FIT OFFLINE:"<< endl;
        printBinContents(bestFitOfflineResults, rawdataFile);

        auto firstFitOnlineResults = binPackingUtils::firstFitOnline(data, 100);
        averageBins[3] += firstFitOnlineResults.size();
        results[3] = firstFitOnlineResults.size();
        rawdataFile << endl << "FIRST FIT ONLINE:" << endl;
        printBinContents(firstFitOnlineResults, rawdataFile);

        auto firstFitOfflineResults = binPackingUtils::firstFitOffline(data, 100);
        averageBins[4] += firstFitOfflineResults.size();
        results[4] = firstFitOfflineResults.size();
        rawdataFile << endl << "FIRST FIT OFFLINE:" << endl;
        printBinContents(firstFitOfflineResults, rawdataFile);

        int min = *min_element(results, results + 5);
        for (int j = 0; j < 5; j++) {
            if (results[j] == min) {
                bestCounts[j]++;
            }
        }
        rawdataFile << endl << endl;
    }
    
    // Getting average number of bins.
    for (int i = 0; i < 5; i++) {
        averageBins[i] /= 10;
    }

    // Print what bin each number was assigned to
    // Print final contnets of each bin 

    cout << endl << "Average Bins Used: " << endl;
    resultsFile << endl << "Average Bins Used: " << endl;
    cout << "\tNext Fit: " << averageBins[0] << " bins" << endl;
    resultsFile << "\tNext Fit: " << averageBins[0] << " bins" << endl;
    cout << "\tBest Fit Offline: " << averageBins[2] << " bins" << endl;
    resultsFile << "\tBest Fit Offline: " << averageBins[2] << " bins" << endl;
    cout << "\tBest Fit Online: " << averageBins[1] << " bins" << endl;
    resultsFile << "\tBest Fit Online: " << averageBins[1] << " bins" << endl;
    cout << "\tFirst Fit Offline: " << averageBins[4] << " bins" << endl;
    resultsFile << "\tFirst Fit Offline: " << averageBins[4] << " bins" << endl;
    cout << "\tFirst Fit Online: " << averageBins[3] << " bins" << endl;
    resultsFile << "\tFirst Fit Online: " << averageBins[3] << " bins" << endl;

    cout << endl << "Best Strategy Counts: " << endl;
    resultsFile << endl << "Best Strategy Counts: " << endl;
    cout << "\tNext Fit: " << bestCounts[0] << " times" << endl;
    resultsFile << "\tNext Fit: " << bestCounts[0] << " times" << endl;
    cout << "\tBest Fit Offline: " << bestCounts[2] << " times" << endl;
    resultsFile << "\tBest Fit Offline: " << bestCounts[2] << " times" << endl; 
    cout << "\tBest Fit Online: " << bestCounts[1] << " times" << endl;
    resultsFile << "\tBest Fit Online: " << bestCounts[1] << " times" << endl;
    cout << "\tFirst Fit Offline: " << bestCounts[4] << " times" << endl;
    resultsFile << "\tFirst Fit Offline: " << bestCounts[4] << " times" << endl;
    cout << "\tFirst Fit Online: " << bestCounts[3] << " times" << endl;
    resultsFile << "\tFirst Fit Online: " << bestCounts[3] << " times" << endl;
}