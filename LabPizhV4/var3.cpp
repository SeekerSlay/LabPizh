#include "var2.cpp"

static int countG(const string& city) {
    int count = 0;
    for (char ch : city) {
        if (ch == 'g' || ch == 'G') { // Учитываем как строчные, так и заглавные буквы
            count++;
        }
    }
    return count;
}

static void var3() {
    string line;
    cout << "Введите текст: ";
    getline(cin >> ws, line);
    // Список городов
    vector<string> cities = splitString(line);

    string cityWithMaxG;
    int maxCount = 0;

    // Поиск города с максимальным количеством букв 'g'
    for (const auto& city : cities) {
        int gCount = countG(city);
        if (gCount > maxCount) {
            maxCount = gCount;
            cityWithMaxG = city; // Обновляем название города с максимальным количеством 'g'
        }
    }

    // Выводим результат
    if (maxCount > 0) {
        cout << "Город с максимальным количеством букв 'g': " << cityWithMaxG
            << " (" << maxCount << " буквы 'g')" << endl;
    }
    else {
        cout << "В списке нет городов с буквой 'g'." << endl;
    }
}