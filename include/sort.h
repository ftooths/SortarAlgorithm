#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Sort {
private:
	int count;
	vector<int> arr;

	vector<int> merge(const std::vector<int>& leftArr, const std::vector<int>& rightArr);
	vector<int> mergeSortTopDownRecursive(std::vector<int>& arr);
	int partition(vector<int>& arr, int low, int high);
	void quickSortRecursive(vector<int>& arr, int low, int high);
	void heapify(vector<int>& arr, int n, int i);

public:
	Sort(int size, int min, int max); // ������
	
	void shuffleArray(); // ��ü �迭 arr�� ���� 
	void printArray() const; // �迭 arr ��¿� �Լ�
	
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