
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ranges> 

#include "sorter.h" 
#include "quickSort.h"

using namespace std;


int main()
{   
    vector<string> arr{ "cc", "ab", "aa" };

    Sorter* sorter =  new QuickSort();
    
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    sorter->Sort(arr);
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
}

