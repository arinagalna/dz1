#pragma once
#include <vector> 
#include <string>

using namespace std;

class Sorter
{
public:
	string sorterName;

	virtual void Sort(vector<string>& arr) = 0;
};

