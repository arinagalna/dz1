#pragma once
#include "sorter.h"

// ���������� - ������� ���������� ����������� �� ���������� Sorter
class MergeSort : public Sorter
{
public:
    MergeSort();                                // ���������� ������������

    void Sort(vector<string>& arr) override;    // ���������� ����������
};

