#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <cmath>
#include "sortingtimings.h"
using namespace std;

void SortingTimings::merge(vector<int>& mergeVec, int start, int mid, int end) {
    // Create temporary vectors to hold the left and right subarrays
    vector<int> left(mergeVec.begin() + start, mergeVec.begin() + mid + 1);
    vector<int> right(mergeVec.begin() + mid + 1, mergeVec.begin() + end + 1);

    // Indices for traversing the left, right subarrays and the main vector
    int i = 0, j = 0, k = start;

    // Merge the two subarrays (left and right) into the original array (mergeVec)
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            mergeVec[k] = left[i];  // If left element is smaller, copy it to mergeVec
            i++;  // Move to the next element in the left subarray
        }
        else {
            mergeVec[k] = right[j];  // If right element is smaller, copy it to mergeVec
            j++;  // Move to the next element in the right subarray
        }
        k++;  // Move to the next position in the main vector
    }

    // If there are any remaining elements in the left subarray, copy them to mergeVec
    while (i < left.size()) {
        mergeVec[k] = left[i];  // Copy remaining left elements
        i++;  // Move to the next element in the left subarray
        k++;  // Move to the next position in the main vector
    }

    // If there are any remaining elements in the right subarray, copy them to mergeVec
    while (j < right.size()) {
        mergeVec[k] = right[j];  // Copy remaining right elements
        j++;  // Move to the next element in the right subarray
        k++;  // Move to the next position in the main vector
    }
}

void SortingTimings::mergeSort(vector<int>& mergeVec, int start, int end) {
    // Base case: if the start index is greater than or equal to the end index, the array is already sorted
    if (start >= end) return;

    // Find the middle point of the current range (divide the array)
    int mid = (start + end) / 2;

    // Recursively sort the left half of the array (from start to mid)
    mergeSort(mergeVec, start, mid);

    // Recursively sort the right half of the array (from mid+1 to end)
    mergeSort(mergeVec, mid + 1, end);

    // Merge the two sorted halves into a single sorted array
    merge(mergeVec, start, mid, end);
}

void SortingTimings::insertionSort(vector<int>& vec) {
    int n = vec.size();  // Get the size of the vector

    // Outer loop: Start from the second element and iterate to the last element
    for (int i = 1; i < n; i++) {
        int key = vec[i];  // The current element to be inserted into the sorted portion
        int j = i - 1;  // Index for the sorted portion (elements before the current element)

        // Inner loop: Shift elements larger than 'key' one position to the right
        while (j >= 0 && vec[j] > key) {
            vec[static_cast<vector<int, allocator<int>>::size_type>(j) + 1] = vec[j];  // Move the larger element to the right
            j = j - 1;  // Move to the next element in the sorted portion
        }

        // Place the 'key' in the correct position in the sorted portion
        vec[static_cast<vector<int, allocator<int>>::size_type>(j) + 1] = key;
    }
}

void SortingTimings::bubbleSort(vector<int>& vec) {
    size_t n = vec.size();  // Get the size of the vector

    // Outer loop: Repeat the process for each element (n-1 times)
    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;  // Flag to check if any elements were swapped in the inner loop

        // Inner loop: Compare adjacent elements and swap them if they are out of order
        for (size_t j = 0; j < n - 1 - i; ++j) {
            if (vec[j] > vec[j + 1]) {  // If the current element is greater than the next element
                swap(vec[j], vec[j + 1]);  // Swap them to order them correctly
                swapped = true;  // Mark that a swap occurred
            }
        }

        // If no elements were swapped during the inner loop, the list is already sorted
        if (!swapped) {
            break;  // Exit the loop early since the list is sorted
        }
    }
}

void SortingTimings::selectionSort(vector<int>& vec) {
    size_t n = vec.size();  // Get the size of the vector

    // Outer loop: Iterate over each element, except the last one
    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIndex = i;  // Assume the current element is the smallest

        // Inner loop: Find the smallest element in the unsorted part of the vector
        for (size_t j = i + 1; j < n; ++j) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;  // Update the index of the smallest element
            }
        }

        // If the smallest element is not already in its correct position, swap it
        if (minIndex != i) {
            swap(vec[i], vec[minIndex]);  // Swap the found minimum element with the current element
        }
    }
}

void SortingTimings::quickSort(vector<int>& vec, int low, int high) {
    // Base case: if the low index is less than the high index, the subarray is not yet sorted
    if (low < high) {
        // Partition the array and get the index of the pivot element
        int pivot_index = q_partition(vec, low, high);

        // Recursively apply quickSort to the left subarray (elements before the pivot)
        quickSort(vec, low, pivot_index - 1);

        // Recursively apply quickSort to the right subarray (elements after the pivot)
        quickSort(vec, pivot_index + 1, high);
    }
}

int SortingTimings::q_partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];  // Choose the pivot element (last element in the current range)
    int i = low - 1;  // Index for the smaller element, initialized to one less than the low index

    // Loop through the elements in the range from low to high - 1
    for (int j = low; j < high; ++j) {
        // If the current element is less than or equal to the pivot, swap it to the left side
        if (vec[j] <= pivot) {
            i = i + 1;  // Increment the index for the smaller element
            swap(vec[i], vec[j]);  // Swap elements to place smaller ones to the left of pivot
        }
    }

    // Place the pivot element in the correct position by swapping it with the element at index i + 1
    swap(vec[static_cast<vector<int, allocator<int>>::size_type>(i) + 1], vec[high]);

    // Return the index of the pivot element after partitioning
    return i + 1;
}

void SortingTimings::heapSort(vector<int>& vec) {
    int n = vec.size();

    // Build a Max-Heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(vec, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 1; --i) {
        // Move current root to the end (extract max)
        swap(vec[0], vec[i]);

        // Call heapify on the reduced heap
        heapify(vec, i, 0);
    }
}

void SortingTimings::heapify(vector<int>& vec, int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // Left child index
    int right = 2 * i + 2;     // Right child index

    // If the left child exists and is greater than the root
    if (left < n && vec[left] > vec[largest]) {
        largest = left;
    }

    // If the right child exists and is greater than the largest so far
    if (right < n && vec[right] > vec[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i) {
        swap(vec[i], vec[largest]);

        // Recursively heapify the affected subtree
        heapify(vec, n, largest);
    }
}

void SortingTimings::radixSort(vector<int>& vec) {
    int max = findMax(vec);  // Find the maximum number in the array
    int exp = 1;             // Start with the least significant digit (1's place)

    // Process each digit (1's, 10's, 100's, etc.)
    while (max / exp > 0) {
        counting_sort_by_digit(vec, exp);
        exp *= 10;  // Move to the next significant digit
    }
}

void SortingTimings::counting_sort_by_digit(vector<int>& vec, int exp) {
    int n = vec.size();  // Get the size of the vector
    vector<int> output(n);   // Output array to store sorted elements
    vector<int> count(10, 0); // Counting array to store frequencies of digits (0 to 9)

    // Count the occurrences of each digit at the given place value (exp)
    for (int i = 0; i < n; ++i) {
        int digit = (vec[i] / exp) % 10;  // Extract the digit at the current place value
        count[digit]++;  // Increment the count for that digit
    }

    // Compute the cumulative count (position of elements in output array)
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];  // Add previous counts to get cumulative counts
    }

    // Build the output array by placing the elements in the correct position
    for (int i = n - 1; i >= 0; --i) {
        int digit = (vec[i] / exp) % 10;  // Extract the digit at the current place value
        output[count[digit] - 1] = vec[i];  // Place the element at the correct position
        count[digit]--;  // Decrement the count for that digit
    }

    // Copy the sorted elements from the output array back to the original vector
    for (int i = 0; i < n; ++i) {
        vec[i] = output[i];  // Replace original vector with the sorted output
    }
}

void SortingTimings::countingSort(vector<int>& vec) {
    int k = findMax(vec);      // Find the maximum value in the vector to determine the range of the counting array
    int n = vec.size();        // Get the size of the vector
    vector<int> C(k + 1, 0);   // Create a counting array C, initialized to 0. Size is (k + 1) to accommodate all values up to the max
    vector<int> B(n);          // Create a temporary array B to store the sorted elements

    // Count the occurrences of each element in the original vector
    for (int i = 0; i < n; ++i) {
        C[vec[i]]++;  // Increment the count for the corresponding element in C
    }

    // Calculate the cumulative count in C
    for (int i = 1; i <= k; ++i) {
        C[i] += C[i - 1];  // Update C[i] to hold the actual position of each element in the sorted array
    }

    // Build the sorted array in B by placing elements in the correct positions
    for (int i = n - 1; i >= 0; --i) {
        B[C[vec[i]] - 1] = vec[i];  // Place the element in the correct position in B
        C[vec[i]]--;  // Decrease the count in C for the placed element
    }

    // Copy the sorted array B back into the original vector vec
    for (int i = 0; i < n; ++i) {
        vec[i] = B[i];  // Copy the elements from B to the original vector vec
    }
}

void SortingTimings::bucketSort(vector<int>& vec) {
    int maxVal = findMax(vec);  // Find the maximum value in the vector
    int n = vec.size();  // Get the size of the vector

    // Calculate the number of buckets based on the size of the vector
    int numBuckets = sqrt(n);
    // Determine the range of each bucket based on the maximum value
    int bucketRange = ceil((float)maxVal / numBuckets);

    // Create the buckets (2D vector of integers)
    vector<vector<int>> buckets(numBuckets);

    // Distribute the elements of the vector into the corresponding buckets
    for (int x : vec) {
        int index = x / bucketRange;  // Determine the bucket index for the current element
        buckets[index].push_back(x);  // Place the element into the appropriate bucket
    }

    // Sort each individual bucket
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());  // Sort elements within each bucket
    }

    // Collect the sorted elements back into the original vector
    int k = 0;  // Index for inserting elements back into the vector
    for (const auto& bucket : buckets) {
        for (int x : bucket) {
            vec[k++] = x;  // Place each element from the bucket back into the original vector
        }
    }
}

void SortingTimings::shellSort(vector<int>& vec) {
    int n = vec.size();  // Get the size of the vector

    // Start with a large gap and reduce it in each iteration
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // Perform a gapped insertion sort for the current gap value
        for (int i = gap; i < n; ++i) {
            int temp = vec[i];  // Store the current element to be inserted
            int j = i;

            // Shift elements that are greater than temp to the right
            while (j >= gap && vec[j - gap] > temp) {
                vec[j] = vec[j - gap];
                j -= gap;  // Move the index by the gap distance
            }

            // Place the stored element (temp) at the correct position
            vec[j] = temp;
        }
    }
}

void SortingTimings::runAllSorts() {
    auto startAll = chrono::high_resolution_clock::now();  // Record the start time for all sorting algorithms

    // Measure the execution time of each sorting algorithm
    measureFunc("Selection Sort", [&](vector<int>& vec) { selectionSort(vec); });
    measureFunc("Bubble Sort", [&](vector<int>& vec) { bubbleSort(vec); });
    measureFunc("Insertion Sort", [&](vector<int>& vec) { insertionSort(vec); });
    measureFunc("Merge Sort", [&](vector<int>& vec) {
        mergeSort(vec, 0, static_cast<int>(vec.size()) - 1);  // Merge Sort uses low and high indices
        });
    measureFunc("Quick Sort", [&](vector<int>& vec) {
        quickSort(vec, 0, static_cast<int>(vec.size()) - 1);  // Quick Sort uses low and high indices
        });
    measureFunc("Heap Sort", [&](vector<int>& vec) { heapSort(vec); });
    measureFunc("Radix Sort", [&](vector<int>& vec) { radixSort(vec); });
    measureFunc("Counting Sort", [&](vector<int>& vec) { countingSort(vec); });
    measureFunc("Bucket Sort", [&](vector<int>& vec) { bucketSort(vec); });
    measureFunc("Shell Sort", [&](vector<int>& vec) { shellSort(vec); });

    auto endAll = chrono::high_resolution_clock::now();  // Record the end time after all sorting algorithms finish
    chrono::duration<double> elapsedAll = endAll - startAll;  // Calculate the total time taken for all sorts

    cout << "All sorting algorithms together took: " << elapsedAll.count() << " seconds" << endl;  // Output the total time
}

int SortingTimings::findMax(vector<int>& vec) {
    return *max_element(vec.begin(), vec.end()); //Returns the max value of the vec
}

void SortingTimings::measureFunc(const string& name, function<void(vector<int>&)> sortFunc) const {
    vector<int> copyVec = vec;  // Create a copy of the original vector to avoid modifying the original
    auto startTime = chrono::high_resolution_clock::now();  // Record the start time using high-resolution clock

    sortFunc(copyVec);  // Call the sorting function passed as an argument, sorting the copied vector

    auto endTime = chrono::high_resolution_clock::now();  // Record the end time after sorting is done
    chrono::duration<double> elapsedTime = endTime - startTime;  // Calculate the time elapsed

    cout << name << " took: " << elapsedTime.count() << " seconds\n" << endl;  // Output the elapsed time
}

void SortingTimings::fillVector() {
    random_device rd;  // Obtain a random seed from the system's random device
    mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator, seeded with random_device
    uniform_int_distribution<> dist(1, 500000); // Define a uniform distribution for random numbers between 1 and 500000

    // Fill the vector with random numbers
    for (size_t i = 0; i < 50000; ++i) {
        vec[i] = dist(gen);  // Assign a random value from the distribution to each element of the vector
    }
}

void SortingTimings::userInterface() {
    bool continueRunning = true;  // Flag to control the loop
    char choice2;  

    while (continueRunning) {
        fillVector();  // Fill the vector with random numbers
        displayMenu();  // Display the available sorting algorithms

        int choice;
        cout << "Choose an algorithm to measure its time: ";  // Prompt user for algorithm choice
        cin >> choice;

        processChoice(choice);  // Process the selected sorting algorithm

        cout << "Would you like to try again with a new size or algorithm? (y for yes, n for no): ";
        cin >> choice2;

        // If the user chooses 'n', stop the loop
        if (choice2 == 'n') {
            continueRunning = false;
        }
        // If the input is invalid, assume 'yes' and continue
        else if (choice2 != 'y') {
            cout << "Invalid input, assuming 'yes'." << endl;
        }
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
        << "6. Heap Sort\n"
        << "7. Radix Sort\n"
        << "8. Counting Sort\n"
        << "9. Bucket Sort\n"
        << "10. Shell Sort\n"
        << "11. ALL AT ONCE\n";
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
    case 7:
        measureFunc("Radix Sort", [&](vector<int>& vec) { radixSort(vec); });
        break;
    case 8:
        measureFunc("Counting Sort", [&](vector<int>& vec) { countingSort(vec); });
        break;
    case 9:
        measureFunc("Bucket Sort", [&](vector<int>& vec) { bucketSort(vec); });
        break;
    case 10:
        measureFunc("Shell Sort", [&](vector<int>& vec) { shellSort(vec); });
        break;
    case 11:
        runAllSorts();
        break;
    default:
        cout << "Invalid choice, please try again." << endl;
    }
}

