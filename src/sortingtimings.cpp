#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include "sortingtimings.h"
using namespace std;

void SortingTimings::merge(vector<int>& mergeVec, int start, int mid, int end) {
    vector<int> left(mergeVec.begin() + start, mergeVec.begin() + mid + 1);
    vector<int> right(mergeVec.begin() + mid + 1, mergeVec.begin() + end + 1);

    int i = 0, j = 0, k = start;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            mergeVec[k] = left[i];
            i++;
        }
        else {
            mergeVec[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left.size()) {
        mergeVec[k] = left[i];
        i++;
        k++;
    }
    while (j < right.size()) {
        mergeVec[k] = right[j];
        j++;
        k++;
    }
}

void SortingTimings::mergeSort(vector<int>& mergeVec, int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(mergeVec, start, mid);
    mergeSort(mergeVec, mid + 1, end);
    merge(mergeVec, start, mid, end);
}

void SortingTimings::insertionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[static_cast<vector<int, allocator<int>>::size_type>(j) + 1] = vec[j];
            j = j - 1;
        }
        vec[static_cast<vector<int, allocator<int>>::size_type>(j) + 1] = key;
    }
}

void SortingTimings::bubbleSort(vector<int>& vec) {
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

void SortingTimings::selectionSort(vector<int>& vec) {
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

void SortingTimings::quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pivot_index = q_partition(vec, low, high);
        quickSort(vec, low, pivot_index - 1);
        quickSort(vec, pivot_index + 1, high);
    }
}

int SortingTimings::q_partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (vec[j] <= pivot) {
            i = i + 1;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[static_cast<vector<int, allocator<int>>::size_type>(i) + 1], vec[high]);

    return i + 1;
}

void SortingTimings::heapSort(vector<int>& vec) {
    int n = vec.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(vec, n, i);
    }
    for (int i = n - 1; i >= 1; --i) {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

void SortingTimings::heapify(vector<int>& vec, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && vec[left] > vec[largest]) {
        largest = left;
    }
    if(right < n && vec[right] > vec[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(vec[i], vec[largest]);
        heapify(vec, n, largest);
    }
}

void SortingTimings::userInterface() {
    bool continueRunning = true;
    char choice2;

    while (continueRunning) {
        size_t vectorSize;
        cout << "Enter the amount of numbers to measure: ";
        cin >> vectorSize;

        fillVector(vectorSize);

        cout << "Unsorted:" << endl;
        displayVector(vec);

        displayMenu();

        int choice;
        cout << "Choose an algorithm to measure its time: ";
        cin >> choice;

        processChoice(choice);

        cout << "Would you like to try again with a new size or algorithm? (y for yes, n for no): ";
        cin >> choice2;

        if (choice2 == 'n') {
            continueRunning = false;
        }
        else if (choice2 != 'y') {
            cout << "Invalid input, assuming 'yes'." << endl;
        }
    }
}

void SortingTimings::measureFunc(const string& name, function<void(vector<int>&)> sortFunc) const {
    vector<int> copyVec = vec; // Work on a copy of the vector
    auto startTime = chrono::high_resolution_clock::now();
    sortFunc(copyVec);
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedTime = endTime - startTime;
    cout << name << " took: " << elapsedTime.count() << " seconds" << endl;
    cout << "Sorted:" << endl;
    displayVector(copyVec);
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

void SortingTimings::displayVector(const vector<int>& vec) const {
    for (const int& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void SortingTimings::displayMenu() const {
    cout << "1. Selection Sort\n"
        << "2. Bubble Sort\n"
        << "3. Insertion Sort\n"
        << "4. Merge Sort\n"
        << "5. Quick Sort\n"
        << "6. Heap Sort\n";
}

void SortingTimings::processChoice(int choice) {
    switch (choice) {
    case 1:
        measureFunc("Selection Sort", [&](vector<int>& vec) { selectionSort(vec); });
        break;
    case 2:
        measureFunc("Bubble Sort", [&](vector<int>& vec) { bubbleSort(vec); });
        break;
    case 3:
        measureFunc("Insertion Sort", [&](vector<int>& vec) { insertionSort(vec); });
        break;
    case 4:
        measureFunc("Merge Sort", [&](vector<int>& vec) {
            mergeSort(vec, 0, static_cast<int>(vec.size()) - 1);
            });
        break;
    case 5:
        measureFunc("Quick Sort", [&](vector<int>& vec) {
            quickSort(vec, 0, static_cast<int>(vec.size()) - 1);
            });
        break;
    case 6:
        measureFunc("Heap Sort", [&](vector<int>& vec) { heapSort(vec); });
        break;
    default:
        cout << "Invalid choice, please try again." << endl;
    }
}

