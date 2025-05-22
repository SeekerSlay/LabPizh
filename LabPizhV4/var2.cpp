#include "var1.cpp"

static void var2() {
    string line;
    cout << "Введите текст: ";
    getline(cin >> ws, line);
    // Список городов
    vector<string> cities = splitString(line);

    // Инициализация переменных для хранения индексов
    int minIndex = 0;
    int maxIndex = 0;

    // Поиск самого короткого и самого длинного названия города
    for (size_t i = 1; i < cities.size(); ++i) {
        if (cities[i].length() < cities[minIndex].length()) {
            minIndex = i; // Обновляем индекс самого короткого города
        }
        if (cities[i].length() > cities[maxIndex].length()) {
            maxIndex = i; // Обновляем индекс самого длинного города
        }
    }

    // Меняем местами названия самого длинного и самого короткого города
    swap(cities[minIndex], cities[maxIndex]);

    // Выводим измененный список городов
    cout << "Измененный список городов:" << endl;
    for (const auto& city : cities) {
        cout << city << " ";
    }

    cout << endl;
}