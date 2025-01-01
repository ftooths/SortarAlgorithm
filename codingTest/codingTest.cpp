#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

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
}

int main() {
	vector<int>arr = initSetting(1000, 1, 1000);
	//vector<int>sortedArr = bubbleSort(arr);
	//vector<int>sortedArr = selectionSort(arr);
	vector<int>sortedArr = insertionSort(arr);

	for (const auto& num : sortedArr) {
		cout << num << "\n" << "";
	}
}