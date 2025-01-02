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

int main() {
	vector<int>arr = initSetting(1000000, 1, 1000);
	//vector<int>sortedArr = bubbleSort(arr);
	//vector<int>sortedArr = selectionSort(arr);
	//vector<int>sortedArr = insertionSort(arr);
	vector<int>sortedArr = mergeSortTopDown(arr);
	for (const auto& num : sortedArr) {
		cout << num << "\n" << "";
	}
	cout << "연산 횟수: " << mergeCount << "\n";
}