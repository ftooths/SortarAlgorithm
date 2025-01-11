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

void Sort::bubbleSort() {
    count = 0; 
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "버블 정렬 연산 횟수: " << count << endl;
}

void Sort::selectionSort() {
    count = 0; 
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            count++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
    cout << "선택 정렬 연산 횟수: " << count << endl;
}

void Sort::insertionSort() {
    count = 0; 
    for (int i = 1; i < arr.size(); i++) {
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
    cout << "삽입 정렬 연산 횟수: " << count << endl;
}