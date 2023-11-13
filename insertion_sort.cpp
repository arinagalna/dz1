#include <iostream>
#include <vector>
#include <string>
#include "insertion_sort.h"

using namespace std;

InsertionSort::InsertionSort()
{
    this->sorterName = "insertion sort";
}

void InsertionSort::Sort(vector<string>& words) {
    if (words.size() == 0) {
        return;
    }
    
    int n = words.size();

    for (int i = 1; i < n; i++) {
        string key = words[i];
        int j = i - 1;

        while (j >= 0 && words[j] > key) {
            words[j + 1] = words[j];
            j = j - 1;
        }

        words[j + 1] = key;
    }
}