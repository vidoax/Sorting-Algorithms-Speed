#ifndef SORTINGTIMINGS_H
#define SORTINGTIMINGS_H

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

class SortingTimings {
private:
    vector<int> vec;

    // Sorting methods
    void selectionSort(vector<int>& vec);
    void bubbleSort(vector<int>& vec);
    void insertionSort(vector<int>& vec);
    void merge(vector<int>& vec, int start, int mid, int end);
    void mergeSort(vector<int>& vec, int start, int end);
    void quickSort(vector<int>& vec, int low, int high);
    int q_partition(vector<int>& vec, int low, int high);
    void heapSort(vector<int>& vec);
    void heapify(vector<int>& vec, int n, int i);
    void radixSort(vector<int>& vec);
    void counting_sort_by_digit(vector<int>& vec, int exp);
    void countingSort(vector<int>& vec);

    // Utility methods
    int findMax(vector<int>& vec);
    void fillVector(size_t vSize);
    void measureFunc(const string& name, function<void(vector<int>&)> sortFunc) const;
    void userInterface();
    void displayVector(const vector<int>&vec) const;
    void displayMenu() const;
    void processChoice(int choice);

public:
    SortingTimings() = default; // Default constructor
    void run() {
        userInterface();
    }
};

#endif // SORTINGTIMINGS_H
