
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ranges>
#include <fstream>
#include <regex>
#include <chrono> 
#include <filesystem>

#include "sorter.h" 
#include "quickSort.h"
#include "insertion_sort.h"
#include "mergeSort.h"
#include "sortChoice.h"
#include "Shaiker.h"
#include "buble.h"


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

//Функция фильтрации допустисых символов
string filterString(const std::string& str) {
    std::string result;
    for (char c : str) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-' || c == ' ' || c == '\n') {
            result += c;
        }
    }
    return result;
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

/*
void save_file(const vector<string>& strings)
{   

    ofstream out;
    string f_name;
    cout << "Enter file name: ";
    cin >> f_name;
    out.open("save" + f_name + ".txt");
    if (out.is_open()) {
        out << strings << endl;
        out.close();
        cout << "File has been saved " << endl;
    }
    else {
        cout << "empty vec" << endl;
    };

};
*/

int main()
{   
    const string inputCatalog = "input/";
    cout << "input catalog: \"" << inputCatalog << "\"" << endl;;
    const string outputCatalog = "out/";

    // Инициализация сортировок
    Sorter* sorters[]{
        new QuickSort(),
        new InsertionSort(),
        new ChoiceSort(),
        new MergeSort(),
        new BubleSort(),
        new ShaikerSort()
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

        //Фильтр допустимых символов
        string result = filterString(fullStr);

        // Разбиение текста по словам
        vector<string> words = split(result);

        // Сортировка текста каждой сортировкой
        vector<string> referenceSortedWords;

        ofstream file(outputCatalog + fileName);

        if (!file.is_open()) {
            cout << "% ERROR! Out file " << outputCatalog + fileName << " not open" << endl;
            continue;
        }
        for (int i = 0; i < size(sorters); i++) {
            Sorter* sorter = sorters[i];

            auto start = high_resolution_clock::now();
            sorter->Sort(words);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            cout << "% \"" << sorter->sorterName << "\"" << endl;
            cout << "% time: " << duration.count() << endl;
            file << "% \"" << sorter->sorterName << "\"" << endl;
            file << "% time: " << duration.count() << endl;

            // Результаты первой сортировки берутся как эталонные
            if (i == 0) {
                referenceSortedWords = words;
                cout << "% reference sorted words from " << sorter->sorterName << ":" << endl;
                cout << stringsToLine(words) << endl;
                file << "% reference sorted words from " << sorter->sorterName << ":" << endl;
                file << stringsToLine(words) << endl;
            }
            // Для остальных сортировок
            else {
                // Вывод результата, если он короткий
                if (words.size() <= 10) {  
                    cout << stringsToLine(words) << endl;
                }
                file << stringsToLine(words) << endl;
                // Проверка совпадения эталонного результата и результата текущей сортировки
                if (!equalStrings(referenceSortedWords, words)) {
                    cout << "% ERROR! sorted data of " << sorter->sorterName
                        << " not equal with reference sorted" << sorters[0] << endl;
                    file << "% ERROR! sorted data of " << sorter->sorterName
                        << " not equal with reference sorted" << sorters[0] << endl;
                }
            }
            cout << endl;
            file << endl;
        }
        file.close();
        std::cout << "Successfully written to the file." << std::endl;
    }    
}

