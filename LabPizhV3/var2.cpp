#include <iostream>
#include <string>

using namespace std;

static void var2() {
    cout << "Введите текст: ";
    string line;
    getline(cin >> ws, line);

    string modifiedLine;
    bool lastWasSpace = false; // Флаг для отслеживания последнего символа

    for (char ch : line) {
        if (ch != ' ') { // Если текущий символ не пробел
            modifiedLine += ch; // Добавляем его в результат
            lastWasSpace = false; // Сбрасываем флаг
        }
        else if (!lastWasSpace) { // Если текущий символ пробел и предыдущий не был пробелом
            modifiedLine += ' '; // Добавляем один пробел
            lastWasSpace = true; // Устанавливаем флаг
        }
    }

    cout << "\nИзменённый текст:\n" << modifiedLine << "\n";
}