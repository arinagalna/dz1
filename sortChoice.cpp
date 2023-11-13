#include <iostream>
#include <vector>
#include <string>
#include "sortChoice.h"

using namespace std;

ChoiceSort::ChoiceSort()
{
    sorterName = "choice sort";
}


void ChoiceSort::Sort(vector<string>& words) {
    if (words.size() == 0) {
        return;
    }
    
    int n = words.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (words[j] < words[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(words[i], words[minIndex]);
        }
    }
}