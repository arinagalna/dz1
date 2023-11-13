#pragma once
#include <vector> 
#include <string>
#include "sorter.h"

using namespace std;

class InsertionSort : public Sorter
{
public:
    InsertionSort();

    void Sort(vector<string>& words) override;
};