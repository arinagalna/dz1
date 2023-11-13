#pragma once
#include "sorter.h"

class QuickSort : public Sorter
{
public:
    QuickSort();

    void Sort(vector<string>& arr) override;
};

