# Sorting Algorithms Performance Analyzer

This repository contains a C++ program that demonstrates and benchmarks the performance of 10 different sorting algorithms. The program generates a vector of random integers, sorts it using the selected algorithm, and displays the time taken for the operation. It also provides an option to run all algorithms sequentially and compare their performance.

## Features

- **Menu-driven Interface:** Choose from 10 individual sorting algorithms or run all at once.
- **Randomized Input Data:** Generates a vector of 50,000 random integers in the range of 1 to 500,000 using the Mersenne Twister pseudo-random generator.
- **Benchmarking:** Measures execution time for each sorting algorithm using the C++ `<chrono>` library.
- **Algorithms Supported:**
  1. Bubble Sort
  2. Insertion Sort
  3. Selection Sort
  4. Merge Sort
  5. Quick Sort
  6. Heap Sort
  7. Shell Sort
  8. Radix Sort
  9. Counting Sort
  10. Bucket Sort
- **Performance Comparison:** Option to execute all algorithms sequentially and display their respective runtimes.

## How It Works

1. Run the program in a terminal.
2. The menu will display 11 options:
   - **Options 1–10:** Select a specific sorting algorithm.
   - **Option 11:** Run all algorithms sequentially and display their runtimes.
3. Upon selecting an algorithm, the program will:
   - Generate a vector of 50,000 random integers.
   - Sort the vector using the chosen algorithm.
   - Display the time taken to sort.

## Requirements

- C++17 or higher
- A C++ compiler (e.g., g++, clang++)
- A terminal to execute the program

