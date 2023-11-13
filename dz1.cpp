
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ranges>
#include <fstream>
#include <regex>
#include <chrono> 

#include "sorter.h" 
#include "quickSort.h"
#include "insertion_sort.h"
#include "mergeSort.h"
#include "sortChoice.h"

using namespace std;
using namespace std::chrono;

// Функция чтения файла
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

// Функция валидация текста через регулярное выражения
bool validateString(const string& str) {
    regex reg("^[a-zA-Z \n]*$"); 
    return regex_match(str, reg);
}

// Функция разбиения текста по словам
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

// Функция соединения слов в строку через пробел
string stringsToLine(const vector<string>& strings) {
    string res;
    for (int i = 0; i < strings.size(); i++) {
        if (i != 0) { res += ' '; }
        res += strings[i];
    }
    return res;
}

bool equalStrings(const vector<string>& stringsA, const vector<string>& stringsB) {
    if (stringsA.size() != stringsB.size()) {
        return false;
    }
    for (int i = 0; i < size(stringsA); i++) {
        if (stringsA[i] != stringsB[i]) {
            return false;
        }
    }
    return true;
}

int main()
{   
    const string inputCatalog = "input/";
    cout << "input catalog: \"" << inputCatalog << "\"" << endl;;

    // Инициализация сортировок
    Sorter* sorters[]{
        new QuickSort(),
        new InsertionSort(),
        new ChoiceSort(),
        new MergeSort()
    };

    while (true) {
        // Ввод имени файла
        cout << "% filename: ";
        string fileName;
        cin >> fileName;
        if (fileName == "q") {
            break;
        }

        // Чтение файла
        string fullStr = readFile(inputCatalog + fileName);
        if (fullStr.size() == 0) {
            cout << "% ERROR! File \"" << fileName << "\" is empty" << endl;
            continue;
        }
        cout << fullStr << endl;

        // Валидация текста
        if (!validateString(fullStr)) {
            cout << "% ERROR! file \"" << fileName << "\" is invalid" << endl;
            continue;
        }
        cout << endl;

        // Разбиение текста по словам
        vector<string> words = split(fullStr);

        // Сортировка текста каждой сортировкой
        vector<string> referenceSortedWords;
        for (int i = 0; i < size(sorters); i++) {
            Sorter* sorter = sorters[i];

            auto start = high_resolution_clock::now();
            sorter->Sort(words);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            cout << "% \"" << sorter->sorterName << "\"" << endl;
            cout << "% time: " << duration.count() << endl;

            // Результаты первой сортировки берутся как эталонные
            if (i == 0) {
                referenceSortedWords = words;
                cout << "% reference sorted words from " << sorter->sorterName << ":" << endl;
                cout << stringsToLine(words) << endl;
            }
            // Для остальных сортировок
            else {
                // Вывод результата, если он короткий
                if (words.size() <= 10) {  
                    cout << stringsToLine(words) << endl;
                }
                // Проверка совпадения эталонного результата и результата текущей сортировки
                if (!equalStrings(referenceSortedWords, words)) {
                    cout << "% ERROR! sorted data of " << sorter->sorterName
                        << " not equal with reference sorted" << sorters[0] << endl;
                }
            }
            cout << endl;
        }
    }    
}

