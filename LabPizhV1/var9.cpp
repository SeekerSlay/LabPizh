#include "var8.cpp"
#include <cctype> // для toupper

const string filename1 = "symbols.bin";

// Функция для вывода содержимого файла
static void printFileContents(const string& fname) {
    ifstream ifs(fname, ios::binary);
    if (!ifs) {
        cout << "Не удалось открыть файл." << endl;
        return;
    }

    cout << "Символы в файле: ";
    char ch;
    while (ifs.read(&ch, 1)) {
        cout << ch;
    }
    cout << endl;
}

// Функция для записи строки в бинарный файл
static void writeStringToFile(const string& str, const string& fname) {
    ofstream ofs(fname, ios::binary);
    for (char ch : str) {
        ofs.write(&ch, 1);
    }
}

// Функция для чтения символов из файла в строку
static string readFileToString(const string& fname) {
    ifstream ifs(fname, ios::binary);
    string result;
    char ch;
    while (ifs.read(&ch, 1)) {
        result += ch;
    }
    return result;
}

// Основная функция программы
static void var9() {
    // Ввод данных пользователем
    cout << "Введите строку латинских символов: ";
    string inputStr;
    getline(cin >> ws, inputStr);

    // Запись исходных символов в бинарный файл
    writeStringToFile(inputStr, filename1);

    // Вывод содержимого файла до изменений
    cout << "\nДо изменения:" << endl;
    printFileContents(filename1);

    // Чтение данных из файла
    string data = readFileToString(filename1);

    // Преобразование всех символов в прописные буквы
    for (char& ch : data) {
        ch = toupper(static_cast<unsigned char>(ch));
    }

    // Перезапись файла с прописными буквами
    writeStringToFile(data, filename1);

    // Вывод содержимого файла после изменений
    cout << "\nПосле изменения:" << endl;
    printFileContents(filename1);
}