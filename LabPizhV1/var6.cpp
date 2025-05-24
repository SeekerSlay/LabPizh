#include "var5.cpp"
#include <limits>

static void var6() {
    ifstream inputFile("input2.txt");
    if (!inputFile) {
        cerr << "Не удалось открыть файл input2.txt" << endl;
        system("pause");
        exit(0);
    }

    vector<double> numbers;
    double num;

    // Чтение чисел из файла
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        cerr << "Файл не содержит чисел." << endl;
        system("pause");
        exit(0);
    }

    // Инициализация переменных для поиска min и max
    double minVal = numeric_limits<double>::max();
    double maxVal = numeric_limits<double>::lowest();

    for (double n : numbers) {
        if (n > maxVal) maxVal = n;
        if (n < minVal) minVal = n;
    }

    double sum = maxVal + minVal;

    // Запись результатов в файл result.txt
    ofstream outputFile("result.txt");
    if (!outputFile) {
        cerr << "Не удалось открыть файл result.txt" << endl;
        system("pause");
        exit(0);
    }

    outputFile << "Наибольшее значение: " << maxVal << "\n";
    outputFile << "Наименьшее значение: " << minVal << "\n";
    outputFile << "Сумма наибольшего и наименьшего: " << sum << "\n";
    cout << "Данные записаны в файл." << endl;
    cout << "Наибольшее значение: " << maxVal << endl;
    cout << "Наименьшее значение: " << minVal << endl;
    cout << "Сумма наибольшего и наименьшего: " << sum << endl;
}