#pragma once
#include <vector> 
#include <string>
#include "sorter.h"

using namespace std;

class ShaikerSort : public Sorter
{
public:
    ShaikerSort();

    void Sort(vector<string>& words) override;
};
