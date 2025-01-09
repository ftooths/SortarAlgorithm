#include "sort.h"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

Sort::Sort(int size, int min, int max) : count(0), arr(size) {
	for (int i = 0; i < size; i++) {
		arr.push_back(min + (rand() % (max - min + 1)));
	}
}