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
        cout << num << " " << endl;

    }
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

vector<int> Sort::merge(const vector<int>& leftArr, const vector<int>& rightArr) {
    vector<int> mergeArr;
    int i = 0, j = 0; 
    while (i < leftArr.size() && j < rightArr.size()) {
        count++;
        if (leftArr[i] <= rightArr[j]) {
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

vector<int> Sort::mergeSortTopDownRecursive(std::vector<int>& subArr) {
    if (subArr.size() <= 1) {
        return subArr;
    }

    int mid = subArr.size() / 2;
    std::vector<int> leftArr(subArr.begin(), subArr.begin() + mid);
    std::vector<int> rightArr(subArr.begin() + mid, subArr.end());

    std::vector<int> sortedLeft = mergeSortTopDownRecursive(leftArr);
    std::vector<int> sortedRight = mergeSortTopDownRecursive(rightArr);

    return merge(sortedLeft, sortedRight);
}

void Sort::mergeSortTopDown() {
    count = 0; 
    arr = mergeSortTopDownRecursive(arr);
    cout << "병합 정렬 (Top-Down) 연산 횟수: " << count << endl;
}

void Sort::mergeSortBottomUp() {
    count = 0; 
    int n = arr.size();
    for (int size = 1; size < n; size *= 2) {
        for (int leftStart = 0; leftStart < n - size; leftStart += 2 * size) {
            int mid = std::min(leftStart + size - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * size - 1, n - 1);

            std::vector<int> leftArr(arr.begin() + leftStart, arr.begin() + mid + 1);
            std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + rightEnd + 1);

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
    cout << "병합 정렬 (Bottom-Up) 연산 횟수: " << count << endl;
}

int Sort::partition(vector<int>& arr, int low, int high) {
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

void Sort::quickSortRecursive(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

void Sort::quickSort() {
    count = 0;
    quickSortRecursive(arr, 0, arr.size() - 1);
    cout << "퀵 정렬 연산 횟수: " << count << endl;
}

void Sort::heapify(vector<int>& arr, int n, int i) {
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
        heapify(arr, n, largest);
    }
}

void Sort::heapSort() {
    count = 0;
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    cout << "힙 정렬 연산 횟수: " << count << endl;
}
