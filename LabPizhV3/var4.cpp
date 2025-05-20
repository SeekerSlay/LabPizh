#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

// Функция для удаления пробелов из строки
static string removeSpaces(const string& str) {
    string result;
    for (char c : str) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

// Функция для подсчета вхождений символов из str1 в str2
static unordered_map<char, int> countCharacters(const string& str1, const string& str2) {
    unordered_map<char, int> countMap;

    // Удаляем пробелы из строк
    string cleanedStr1 = removeSpaces(str1);
    string cleanedStr2 = removeSpaces(str2);

    // Инициализируем счетчик для каждого символа из cleanedStr1
    for (char c : cleanedStr1) {
        countMap[c] = 0;
    }

    // Подсчитываем количество вхождений каждого символа из cleanedStr1 во второй строке
    for (char c : cleanedStr2) {
        if (countMap.find(c) != countMap.end()) {
            countMap[c]++;
        }
    }

    return countMap;
}

// Функция для замены слова "компьютер" на "ПК"
static string replaceComputerWithPC(const string& text) {
    string result = text;
    size_t pos = 0;

    // Заменяем все вхождения слова "компьютер" на "ПК"
    while ((pos = result.find("компьютер", pos)) != string::npos) {
        result.replace(pos, 10, "ПК");
        pos += 2; // Пропускаем замененное слово
    }

    return result;
}

static void var4() {
    cout << "Введите текст: ";
    string str1;
    getline(cin >> ws, str1);
    cout << "Введите текст: ";
    string str2;
    getline(cin >> ws, str2);

    // Подсчет символов
    unordered_map<char, int> characterCounts = countCharacters(str1, str2);

    cout << "Количество вхождений символов:" << endl;
    for (const auto& pair : characterCounts) {
        cout << "'" << pair.first << "' – встречается " << pair.second << " раз" << endl;
    }

    // Замена слов
    string updatedText = replaceComputerWithPC(str1);

    cout << "\nОбновленный текст:" << endl;
    cout << updatedText << endl;
}