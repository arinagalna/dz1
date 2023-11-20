#pragma once
#include "sorter.h"

// —ортировка - быстра€ сортировка наследуетс€ от интерфейса Sorter
class QuickSort : public Sorter
{
public:
    QuickSort();                                // ќбъ€вление конструктора

    void Sort(vector<string>& arr) override;    // ќбъ€вление сортировки
};

