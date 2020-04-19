#include "binPackingUtils.h"
#include "binPacking.h"
#include <algorithm>

void addValue(binPacking& bins, int binIndex, int value) {
    bins.bins.at(binIndex).sum += value;
    bins.bins.at(binIndex).bin.push_back(value);
}

bool valueWillFit(const binPacking& bins, int binIndex, int value) {
    return bins.bins.at(binIndex).sum + value <= bins.bins.at(binIndex).capacity;
}

void makeNewBin(binPacking& bins) {
    binPacking::bin newBin;
    bins.bins.push_back(newBin);
}

vector<binPacking::bin> binPackingUtils::nextFit(const int* values, int size) {
    binPacking bins;
    makeNewBin(bins);
    int currentBin = 0;

    for (int i = 0; i < size; i++) {
        int value = values[i];
        if (!valueWillFit(bins, currentBin, value)) {
            makeNewBin(bins);
            currentBin++;
        }
        addValue(bins, currentBin, value);
    }

    return bins.bins;
}

vector<binPacking::bin> binPackingUtils::bestFitOnline(const int* values, int size){
    binPacking bins;
    makeNewBin(bins);

    for (int i = 0; i < size; i++) {
        int value = values[i];
        bool valueDidFit = false;
        int bestBinIndex = 0;

        for (int j = 0; j < bins.bins.size(); j++)
            if (valueWillFit(bins, j, value) && 
                bins.bins[j].sum > bins.bins[bestBinIndex].sum) { 
                    bestBinIndex = j;
                    valueDidFit = true;
            }

        if (!valueDidFit) {
            makeNewBin(bins);
            bestBinIndex = bins.bins.size() - 1;
        }

        addValue(bins, bestBinIndex, value);
    }
    
    for (int i = 0; i < bins.bins.size() - 1; i++) 
        bins.bins[i] = bins.bins[i + 1];
    bins.bins.pop_back();

    return bins.bins;
}

vector<binPacking::bin> binPackingUtils::bestFitOffline(int* values, int size){
    int *newArray = new int[size];
    copy(values, values + size, newArray);
    sort(newArray, newArray + size, greater<int>());
    return bestFitOnline(newArray, size);
}

vector<binPacking::bin> binPackingUtils::firstFitOnline(const int* values, int size){
    binPacking bins;
    makeNewBin(bins);

    for (int i = 0; i < size; i++) {
        int value = values[i];
        bool valueDidFit = false;

        for (int j = 0; j < bins.bins.size(); j++)
            if (valueWillFit(bins, j, value)) { 
                valueDidFit = true;
                addValue(bins, j, value);
                break;
            }

        if (!valueDidFit) {
            makeNewBin(bins);
            addValue(bins, bins.bins.size() - 1, value);
        }
    }

    return bins.bins;
}

vector<binPacking::bin> binPackingUtils::firstFitOffline(int* values, int size){
    int *newArray = new int[size];
    copy(values, values + size, newArray);
    sort(newArray, newArray + size, greater<int>());
    return firstFitOffline(newArray, size);
    // return {};
}

void binPackingUtils::outputBins(const vector<binPacking::bin>& bins) {
    for (int binsIndex = 0; binsIndex < bins.size(); binsIndex++) {
        cout << "Bin " << binsIndex << ": ";
        for (int i = 0; i < bins[binsIndex].bin.size(); i++)
            cout << bins[binsIndex].bin.at(i) << " ";
        cout << endl;
    }
}