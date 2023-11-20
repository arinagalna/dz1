#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ranges> 
#include <vector> 
using namespace std;

// Функция для проверки, является ли символ буквой
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Функция для преобразования символа в нижний регистр
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Функция для сортировки слов в тексте по алфавиту методом "шейкер"
string sortWords(string text) {
    istringstream iss(text);
    string word;
    vector<string> words;

    // Разбиение текста на слова
    while (iss >> word) {
        words.push_back(word);
    }

    // Сортировка слов методом "шейкер"
    int left = 0;
    int right = words.size() - 1;

    while (left <= right) {
        // Проход слева направо
        for (int i = left; i < right; i++) {
            string& word1 = words[i];
            string& word2 = words[i + 1];

            // Приведение слов к нижнему регистру
            transform(word1.begin(), word1.end(), word1.begin(), toLower);
            transform(word2.begin(), word2.end(), word2.begin(), toLower);

            // Сравнение слов по алфавиту
            if (word1 > word2) {
                swap(word1, word2);
            }
        }

        right--;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            string& word1 = words[i - 1];
            string& word2 = words[i];

            // Приведение слов к нижнему регистру
            transform(word1.begin(), word1.end(), word1.begin(), toLower);
            transform(word2.begin(), word2.end(), word2.begin(), toLower);

            // Сравнение слов по алфавиту
            if (word1 > word2) {
                swap(word1, word2);
            }
        }

        left++;
    }

    // Сборка отсортированного текста
    string sortedText;
    for (const string& word : words) {
        sortedText += word + " ";
    }

    return sortedText;
}

int main()
{
    string text = "When I was young, my Mum often read me about dinosaurs."
        "I always want to find a bones of dinosaurs. 1214& &&!"
        "The size of dinosaurs is bigger then the size of whales!&8 and elephants, in addition88, they were stronger and faster. ";

    string sortedText = sortWords(text);
    cout << sortedText << endl;

    return 0;
}