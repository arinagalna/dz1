#include <iostream>
#include <vector>
#include <string>
#include "buble.h"

using namespace std;

BubleSort::BubleSort()
{
    this->sorterName = "insertion sort";
}

void BubleSort::Sort(vector<string>& words) {
    if (words.size() == 0) {
        return;
    }

    int n = words.size();
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (words[j] > words[j + 1]) {
                swap(words[j], words[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped 
        // by inner loop, then break 
        if (swapped == false)
            break;
    }
}


