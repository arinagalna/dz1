#include "quickSort.h"

// функция быстрой сортировки 
void quickSort(vector<string>& arr, int left, int right) {
    int i = left, j = right;
    string pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

QuickSort::QuickSort()
{
    sortedName = "quick sort";
}

void QuickSort::Sort(vector<string>& arr) {
    if (arr.size() == 0) {
        return;
    }
    quickSort(arr, 0, arr.size() - 1);
}