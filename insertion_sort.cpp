#include <iostream>
#include <vector>
#include <string>
#include "insertion_sort.h"

using namespace std;

InsertionSort::InsertionSort()
{
    this->sorterName = "insertion sort";
}


// Функция для сортировки вектора строк методом вставок
void insertionSort(vector<string>& words) {
    // Получение размера вектора
    int n = words.size();

    // Основной цикл сортировки, начиная со второго элемента массива
    for (int i = 1; i < n; i++) {
        // Сохранение текущего слова (ключа) для сравнения и вставки
        string key = words[i];
        // Инициализация переменной j для обратного прохода по отсортированной части массива
        int j = i - 1;

        // Перемещение элементов, которые больше ключа, на одну позицию вперед
        while (j >= 0 && words[j] > key) {
            words[j + 1] = words[j];
            // Переход к предыдущему элементу
            j = j - 1;
        }

        // Вставка ключа на правильное место в отсортированной части массива
        words[j + 1] = key;
    }
}
