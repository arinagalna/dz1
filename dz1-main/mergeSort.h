#pragma once
#include "sorter.h"

// —ортировка - быстра€ сортировка наследуетс€ от интерфейса Sorter
class MergeSort : public Sorter
{
public:
    MergeSort();                                // ќбъ€вление конструктора

    void Sort(vector<string>& arr) override;    // ќбъ€вление сортировки
};

