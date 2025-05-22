#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string.h>


using namespace std;

static vector<string> splitString(const string& str) {
    vector<string> words;
    istringstream stream(str);
    string word;

    // Используем istringstream для разбиения строки на слова
    while (stream >> word) {
        words.push_back(word);
    }

    return words;
}

static void var1() {
    string line;
    cout << "Введите текст: ";
    getline(cin >> ws, line);
    // Список городов
    vector<string> cities = splitString(line);
    int count = 0;

    for (const auto& city : cities) {
        // Приводим название города к нижнему регистру
        string lowerCity = city;
        transform(lowerCity.begin(), lowerCity.end(), lowerCity.begin(), ::tolower);

        // Проверяем, заканчивается ли название на "град" или "grad"
        if (lowerCity.size() >= 4 && (lowerCity.compare(lowerCity.size() - 4, 4, "град") == 0 ||
            lowerCity.compare(lowerCity.size() - 4, 4, "grad") == 0)) {
            count++;
        }
    }

    cout << "Количество городов, название которых заканчивается на 'град' или 'grad': " << count << endl;
}