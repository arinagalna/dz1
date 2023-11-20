#pragma once
#include <vector> 
#include <string>

using namespace std;

// Интерфейс сортера
class Sorter
{
public:
	string sorterName;							// Имя сортировки

	virtual void Sort(vector<string>& arr) = 0;	// Метод интерфейса
};

