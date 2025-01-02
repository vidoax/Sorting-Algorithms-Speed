#include <iostream>
#include <random>
#include "sortingtimings.h"
using namespace std;


void SortingTimings::userInterface() {
    size_t vectorSize;
    int choice;

    cout << "Enter the amount of numbers to measure:" << endl;
    cin >> vectorSize;

    cout << "1. Selection Sort\n"
        "2. Bubble Sort\n"
        "3. Insertion Sort\n"
        "4. Merge Sort\n"
        "5. Quick Sort\n"
        "6. Heap Sort\n"
        "7. Radix Sort\n"
        "8. Shell Sort\n"
        "9. Bucket Sort\n"
        "10. Counting Sort\n"
        "11. Cocktail Shaker Sort\n"
        "12. Tim Sort\n"
        "13. ALL AT ONCE\n" << endl;

    cout << "Choose an algorithm to measure it's time: ";
    cin >> choice;

    //fill vector
    fillVector(vectorSize);

    //testing the sorts
    cout << "Unsorted:" << endl;
    for (const int& num : vec) {
        cout << num << " ";
    }
    cout << endl;

    //call sorter
    bubbleSort();

    cout << "Sorted:" << endl;
    for (const int& num : vec) {
        cout << num << " ";
    }
}

void SortingTimings::insertionSort() {

}

void SortingTimings::bubbleSort() {
    size_t n = vec.size();

    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < n - 1 - i; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void SortingTimings::selectionSort() {
    size_t n = vec.size();

    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(vec[i], vec[minIndex]);
        }
    }
}

void SortingTimings::fillVector(size_t vSize) {
    vec.resize(vSize); 

    //random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100); //random number between 1 and 100

    //fill the vector
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i] = dist(gen); 
    }
}