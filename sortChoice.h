#pragma once
#include <vector> 
#include <string>
#include "sorter.h"

using namespace std;

class ChoiceSort : public Sorter
{
public:
    ChoiceSort();

    void Sort(vector<string>& words) override;
};