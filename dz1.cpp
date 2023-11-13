
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ranges> 
#include <fstream> 
#include <regex> 

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

bool validateString(const string& str) {
    regex reg("^[a-zA-Z \n]*$"); 
    return regex_match(str, reg);
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
    // Инициализация сортировок
    Sorter* sorters[]{
        new QuickSort()
    };

    while (true) {
        // Ввод имени файла
        cout << "filename: ";
        string fileName;
        cin >> fileName;
        if (fileName == "q") {
            break;
        }
        string fullFileName = "input/" + fileName;

        // Чтение файла
        string fullStr = readFile(fullFileName);
        cout << fullStr << endl << endl;

        // Валидация текста
        if (!validateString(fullStr)) {
            cout << "file " << fileName << " is invalid" << endl;
            continue;
        }

        // Валидация Разбиение текста по словам
        vector<string> words = split(fullStr);

        // Сортировка текста каждой сортировкой
        for (Sorter* sorter : sorters) {
            sorter->Sort(words);

            cout << sorter->sorterName << endl << stringsToLine(words) << endl << endl;
        }
    }    
}

