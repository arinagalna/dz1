
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ranges> 
#include <fstream> 

#include "sorter.h" 
#include "quickSort.h"

using namespace std;

string readFile(const string& fileName)
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        throw runtime_error("Could not open file " + fileName);
    }

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

vector<string> split(const string& s) {
    vector<string> words;
    string word;
    for (char c : s) {
        if (c == ' ' || c == '\n') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

void printStrings(const vector<string>& strings) {
    for (const auto& str : strings) {
        cout << str << endl;
    }
}

int main()
{   
    string fullStr = readFile("in.txt");
    cout << fullStr << endl << endl;

    vector<string> words = split(fullStr);

    Sorter* sorter =  new QuickSort();
    
    sorter->Sort(words);

    printStrings(words); cout << endl;
    
}

