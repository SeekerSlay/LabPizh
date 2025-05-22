#include "var3.cpp"

static void bubbleSort(vector<string>& names) {
    size_t n = names.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (names[j] > names[j + 1]) {
                swap(names[j], names[j + 1]); // Меняем местами
            }
        }
    }
}

static void var4() {
    // Список фамилий сотрудников
    string line;
    cout << "Введите текст: ";
    getline(cin >> ws, line);
    // Список городов
    vector<string> surnames = splitString(line);

    vector<string> filteredSurnames;

    // Переписываем фамилии, где вторая буква 'л'
    for (const auto& surname : surnames) {
        if (surname.length() > 1 && surname[1] == 'л') { // Проверяем длину и вторую букву
            filteredSurnames.push_back(surname);
        }
    }

    // Сортируем второй список методом пузырька
    bubbleSort(filteredSurnames);

    // Выводим отсортированный список
    cout << "Отсортированный список фамилий с второй буквой 'л':" << endl << endl;
    for (const auto& surname : filteredSurnames) {
        cout << surname << endl;
    }
    cout << endl;
}