#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>
#include <random>

class Sort {
private:
	int count;
	std::vector<int> arr;
	std::vector<int> arrBackUp;
	std::vector<int> merge(const std::vector<int>& leftArr, const std::vector<int>& rightArr);
	std::vector<int> mergeSortTopDownRecursive(std::vector<int>& arr);
	int partition(std::vector<int>& arr, int low, int high);
	void quickSortRecursive(std::vector<int>& arr, int low, int high);
	void heapify(std::vector<int>& arr, int n, int i);

public:
	Sort(int size, int min, int max); // 생성자

	void shuffleArray(); // 자체 배열 arr을 섞을
	void printArray() const; // 배열 arr 출력용 함수

	inline int getCount() const { return count; }

	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void mergeSortTopDown();
	void mergeSortBottomUp();
	void quickSort();
	void heapSort();

};

#endif // SORT_H