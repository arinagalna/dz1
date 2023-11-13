
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
        return "";
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

string stringsToLine(const vector<string>& strings) {
    string res;
    for (int i = 0; i < strings.size(); i++) {
        if (i != 0) { res += ' '; }
        res += strings[i];
    }
    return res;
}

int main()
{   
    Sorter* sorters[]{
        new QuickSort()
    };

    while (true) {
        string fileName;
        cin >> fileName;
        if (fileName == "q") {
            break;
        }

        string fullStr = readFile(fileName);
        cout << fullStr << endl << endl;

        vector<string> words = split(fullStr);

        Sorter* sorter = new QuickSort();

        for (Sorter* sorter : sorters) {
            sorter->Sort(words);

            cout << sorter->sortedName << endl << stringsToLine(words) << endl;
        }
    }    
}

