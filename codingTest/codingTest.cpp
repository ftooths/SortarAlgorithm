#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int mergeCount = 0; // merge sort 임시 카운트. 클래스로 변환 후 삭제 예정

vector<int> initSetting(int size, int min, int max) {
	vector<int> arr;

	for (int i = 0; i < size; i++) {
		arr.push_back(min + (rand() % (max - min + 1)));
	}
	return arr;
}

vector<int> bubbleSort(vector<int> arr) {
	int count = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = 0; j < arr.size() - i - 1; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	cout << "연산 횟수: " << count << "\n";
	return arr;
} // 버블 정렬

vector<int> selectionSort(vector<int> arr) {
	int count = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < arr.size(); j++) {
			count++;
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i)
			swap(arr[i], arr[minIndex]);
	}
	cout << "연산 횟수: " << count << "\n";
	return arr;
}// 선택 정렬

vector<int> insertionSort(vector<int>arr) {
	int count = 0;
	for (int i = 1; i < arr.size() ; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			count++;
			arr[j + 1] = arr[j];
			j--;
		}
		count++;
		arr[j + 1] = key;
	}
	cout << "연산 횟수: " << count << "\n";
	return arr;
}// 삽입 정렬

vector<int> merge(const vector<int>& leftArr, const vector<int>& rightArr) {
	vector<int> mergeArr;
	int i = 0, j = 0; // i는 leftArr에 사용, j는 rightArr에 사용.
	
	while (i < leftArr.size() && j< rightArr.size()) {
		mergeCount++;
		
		if (leftArr[i]<=rightArr[j]) {
			mergeArr.push_back(leftArr[i]);
			i++;
		}
		else {
			mergeArr.push_back(rightArr[j]);
			j++;
		}
	}
	while (i < leftArr.size()) {
		mergeArr.push_back(leftArr[i]);
		i++;
	}
	while (j < rightArr.size()) {
		mergeArr.push_back(rightArr[j]);
		j++;
	}
	return mergeArr;
}

vector<int> mergeSortTopDown(vector<int>& arr) {
	if (arr.size() <= 1)
		return arr;

	int mid = arr.size() / 2;
	vector<int> leftArr(arr.begin(), arr.begin() + mid);
	vector<int> rightArr(arr.begin() + mid, arr.end());

	vector<int> sortedLaft = mergeSortTopDown(leftArr);
	vector<int> sortedRight= mergeSortTopDown(rightArr);

	return merge(sortedLaft, sortedRight);
}

vector<int> mergeSortBottomUp(vector<int>& arr) {
	int arrSize = arr.size();
	int count = 0;

	for (int size = 1; size < arrSize; size *= 2) {
		for (int leftStart = 0; leftStart < arrSize - size; leftStart += 2 * size) { 
			int mid = min(leftStart + size - 1, arrSize - 1);
			int rightEnd = min(leftStart + 2 * size - 1, arrSize - 1);

			vector<int> leftArr(arr.begin() + leftStart, arr.begin() + mid + 1);
			vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + rightEnd + 1);

			int i = 0, j = 0, k = leftStart;
			while (i < leftArr.size() && j < rightArr.size()) {
				count++; 
				if (leftArr[i] <= rightArr[j]) {
					arr[k++] = leftArr[i++];
				}
				else {
					arr[k++] = rightArr[j++];
				}
			}
			while (i < leftArr.size()) {
				arr[k++] = leftArr[i++];
			}
			while (j < rightArr.size()) {
				arr[k++] = rightArr[j++];
			}
		}
	}
	cout << "연산 횟수: " << count << "\n"; 
	return arr;
}

int partition(vector<int>& arr, int low, int high, int& count) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		count++;
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSortRecursive(vector<int>& arr, int low, int high, int& count) {
	if (low < high) {
		int pi = partition(arr, low, high, count);
		quickSortRecursive(arr, low, pi - 1, count);
		quickSortRecursive(arr, pi + 1, high, count);
	}
}

vector<int> quickSort(vector<int> arr) {
	int count = 0;
	quickSortRecursive(arr, 0, arr.size() - 1, count);
	cout << "연산 횟수:" << count << "\n";
	return arr;
}

void heapify(vector<int>& arr, int n, int i, int& count) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	count++;
	if (left < n && arr[left] > arr[largest])
		largest = left;

	count++;
	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest, count);
	}
}
vector<int> heapSort(vector<int>& arr) {
	int count = 0;
	int n = arr.size();

	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i, count);
	}

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, count);
	}

	cout << "연산 횟수: " << count << "\n";
	return arr;
}

int main() {
	vector<int>arr = initSetting(1000, 1, 1000);
	//vector<int>sortedArr = bubbleSort(arr);
	//vector<int>sortedArr = selectionSort(arr);
	//vector<int>sortedArr = insertionSort(arr);
	//vector<int>sortedArr = mergeSortTopDown(arr);
	//vector<int>sortedArr = mergeSortBottomUp(arr);
	//vector<int>sortedArr = quickSort(arr);
	vector<int>sortedArr = heapSort(arr);


	for (const auto& num : sortedArr) {
		cout << num << "\n" << "";
	}
	//cout << "연산 횟수: " << mergeCount << "\n";
}

/*
	예상치 못한 상황 목록
	1. count 횟수 출력이 안됨.
	배열 출력하는 연산이 너무 많아 원소가 10000일 때 기준으로 99 이하는 표기가 안됨.
	그 위에 뭍혀 있음. 추후 클래스로 수정 때, 카운터 횟수 저장 기능 따로 만들 예정
*/