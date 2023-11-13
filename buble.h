
#pragma once
#include <vector> 
#include <string>
#include "sorter.h"

using namespace std;

class BubleSort : public Sorter
{
public:
    BubleSort();

    void Sort(vector<string>& words) override;
};