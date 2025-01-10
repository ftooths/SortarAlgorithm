#include "sort.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

Sort::Sort(int size, int min, int max) : count(0), arr(size) {
    for (int i = 0; i < size; i++) {
        arr[i] = min + (rand() % (max - min + 1));
    }
    arrBackUp = arr; 
}

void Sort::shuffleArray() {
    arr = arrBackUp;
}

void Sort::printArray() const {
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;
}