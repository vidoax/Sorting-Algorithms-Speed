#ifndef SORTINGTIMINGS_H
#define SORTINGTIMINGS_H
#include <vector>

class SortingTimings {
private:
	std::vector<int> vec;
	void selectionSort();
	void bubbleSort();
	void insertionSort();
public:
    SortingTimings() {};
	void fillVector(size_t vSize);
	void userInterface();
	void run() {
		userInterface();
	};
};

#endif // !SORTINGTIMINGS_H
