#pragma once
#include "sorter.h"

// ���������� - ������� ���������� ����������� �� ���������� Sorter
class QuickSort : public Sorter
{
public:
    QuickSort();                                // ���������� ������������

    void Sort(vector<string>& arr) override;    // ���������� ����������
};

