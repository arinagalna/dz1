#pragma once
#include <vector> 
#include <string>

using namespace std;

class Sorter
{
public:
	string sortedName;

	virtual void Sort(vector<string>& arr) = 0;
};

