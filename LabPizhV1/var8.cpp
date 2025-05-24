#include "var7.cpp"
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <sys/stat.h>

const size_t MAX_STRING_SIZE = 50;
const string filename = "workers.dat";

// Функция для проверки существования файла
static bool fileExists(const string& fname) {
    struct stat buffer;
    return (stat(fname.c_str(), &buffer) == 0);
}

// Функция для автоматического создания файла с тестовыми данными
static void createTestData(const string& fname) {
    ofstream ofs(fname, ios::binary);
    if (!ofs) {
        cerr << "Не удалось создать файл." << endl;
        return;
    }

    // Пример данных
    struct WorkerRecord {
        char position[MAX_STRING_SIZE];
        double salary;
    };

    WorkerRecord testRecords[] = {
        {"слесарь", 30000},
        {"инженер", 50000},
        {"слесарь", 32000},
        {"менеджер", 45000},
        {"слесарь", 31000}
    };

    int count = sizeof(testRecords) / sizeof(testRecords[0]);
    for (int i = 0; i < count; ++i) {
        ofs.write(reinterpret_cast<const char*>(&testRecords[i]), sizeof(WorkerRecord));
    }
}

// Запись данных в файл (если файла нет, создаем его автоматически)
static void writeData(const string& fname) {
    if (!fileExists(fname)) {
        cout << "Файл не найден. Создаю файл с тестовыми данными..." << endl;
        createTestData(fname);
    }

    // Можно оставить функцию для ручного добавления данных, если нужно
}

// Анализировать и выводить информацию о слесарях
static void analyzeSlesar(const string& fname) {
    ifstream ifs(fname, ios::binary);
    if (!ifs) {
        cerr << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    int totalSlesarSalary = 0;
    int slesarCount = 0;

    while (true) {
        struct WorkerRecord {
            char position[MAX_STRING_SIZE];
            double salary;
        } record;

        ifs.read(reinterpret_cast<char*>(&record), sizeof(WorkerRecord));
        if (ifs.eof()) break;

        string position(record.position);
        if (position == "слесарь" || position.find("слесарь") != string::npos) {
            totalSlesarSalary += static_cast<int>(record.salary);
            slesarCount++;
        }
    }

    if (slesarCount > 0) {
        double averageSalary = static_cast<double>(totalSlesarSalary) / slesarCount;
        cout << "Количество слесарей: " << slesarCount << endl;
        cout << "Средняя зарплата слесарей: " << averageSalary << endl;
    }
    else {
        cout << "Слесари не найдены." << endl;
    }
}

static void var8() {
    // Проверяем наличие файла и создаем его при необходимости
    writeData(filename);

    // Анализируем и выводим результат
    analyzeSlesar(filename);
}