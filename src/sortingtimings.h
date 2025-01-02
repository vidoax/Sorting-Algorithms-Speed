#ifndef SORTINGTIMINGS_H
#define SORTINGTIMINGS_H

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <chrono>
#include <cstdlib>
#include <ctime>

class SortingTimings {
private:
    std::vector<int> vec;

    // Sorting methods
    void selectionSort(std::vector<int>& vec);
    void bubbleSort(std::vector<int>& vec);
    void insertionSort(std::vector<int>& vec);
    void merge(std::vector<int>& vec, int start, int mid, int end);
    void mergeSort(std::vector<int>& vec, int start, int end);
    void quickSort(std::vector<int>& vec, int low, int high);
    int q_partition(std::vector<int>& vec, int low, int high);
    void heapSort(std::vector<int>& vec);
    void heapify(std::vector<int>& vec, int n, int i);

    // Utility methods
    void fillVector(size_t vSize);
    void measureFunc(const std::string& name, std::function<void(std::vector<int>&)> sortFunc) const;
    void userInterface();
    void displayVector(const std::vector<int>&vec) const;
    void displayMenu() const;
    void processChoice(int choice);

public:
    SortingTimings() = default; // Default constructor
    void run() {
        userInterface();
    }
};

#endif // SORTINGTIMINGS_H
