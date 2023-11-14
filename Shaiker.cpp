#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "Shaiker.h"

using namespace std;


void shakerSort(vector<string>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        // Сортировка слева направо
        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        --right;

        if (!swapped) {
            break;
        }

        swapped = false;

        // Сортировка справа налево.
        for (int i = right; i > left; --i) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        ++left;
    }
}


ShaikerSort::ShaikerSort()
{
    sorterName = "shaiker sort";
}


void ShaikerSort::Sort(vector<string>& words) {
    if (words.size() == 0) {
        return;
    }
    shakerSort(words);
}