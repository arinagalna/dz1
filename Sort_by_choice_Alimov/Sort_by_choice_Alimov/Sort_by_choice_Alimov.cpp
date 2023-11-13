#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Функция для разделения текста на слова
vector<string> splitText(string text) {
    stringstream ss(text);
    vector<string> words;
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

// Функция для поиска минимального слова в массиве
int findMinIndex(vector<string>& words, int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (words[i] < words[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Функция для обмена двух слов в массиве
void swapWords(vector<string>& words, int index1, int index2) {
    string temp = words[index1];
    words[index1] = words[index2];
    words[index2] = temp;
}

// Функция для сортировки слов в тексте методом сортировки выбором
void selectionSort(vector<string>& words) {
    int size = words.size();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = findMinIndex(words, i, size - 1);
        swapWords(words, i, minIndex);
    }
}

int main()
{
    string text = "When I was young, my Mum often read me about dinosaurs. "
        "I always want to find a bones of dinosaurs. 1214& &&! "
        "The size of dinosaurs is bigger then the size of whales!&8 and elephants, in addition88, they were stronger and faster.";

    vector<string> words = splitText(text);

    selectionSort(words);

    cout << "Отсортированные слова: " << endl;
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}