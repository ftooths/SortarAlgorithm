#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

vector<int> initSetting(int size, int min, int max) {
	vector<int> arr;

	for (int i = 0; i < size; i++) {
		arr.push_back(min + (rand()%(max-min+1)));
	}
	return arr;
}


int main() {
	vector<int>arr = initSetting(1000000, 1, 100);


	for (const auto& num : arr) {
		cout << num << "\n" << "";
	}
}