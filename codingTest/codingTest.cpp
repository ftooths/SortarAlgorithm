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
} // 

int main() {
	vector<int>arr = initSetting(100000/2, 1, 1000);
	vector<int>sortedArr = bubbleSort(arr);

	for (const auto& num : sortedArr) {
		cout << num << "\n" << "";
	}
}