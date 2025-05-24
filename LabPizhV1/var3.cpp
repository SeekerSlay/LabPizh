#include "var2.cpp"
#include <string>
#include <sstream>

static void var3() {
    ifstream fin("input.txt");   // исходный файл
    ofstream fout("output.txt"); // файл для результата

    if (!fin) {
        cerr << "Не удалось открыть входной файл input.txt" << endl;
        system("pause");
        exit(0);
    }
    if (!fout) {
        cerr << "Не удалось открыть выходной файл output.txt" << endl;
        system("pause");
        exit(0);
    }

    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string word;
        bool first_word = true;

        // Обработка строки: пропускаем лишние пробелы между словами
        while (iss >> word) {
            if (first_word) {
                fout << word; // первая слово без пробела
                first_word = false;
            }
            else {
                fout << " " << word; // добавляем один пробел перед словом
            }
        }
        fout << "\n"; // перенос строки после обработки каждой строки
    }

    fin.close();
    fout.close();

    cout << "Обработка завершена. Лишние пробелы удалены." << endl;
}