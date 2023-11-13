#pragma once
#include "sorter.h"

// Сортировка - быстрая сортировка
class QuickSort : public Sorter
{
public:
    QuickSort();                                // Объявление конструктора

    void Sort(vector<string>& arr) override;    // Объявление сортировки
};

