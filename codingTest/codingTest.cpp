#include <iostream>
#include "sort.h"

int main() {
    Sort sorter(100, 1, 1000);
    sorter.heapSort();
    sorter.printArray();
    return 0;
}