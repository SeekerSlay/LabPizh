#include "var7.cpp"
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <sys/stat.h>

const size_t MAX_STRING_SIZE = 50;
const string filename = "workers.dat";

// ������� ��� �������� ������������� �����
static bool fileExists(const string& fname) {
    struct stat buffer;
    return (stat(fname.c_str(), &buffer) == 0);
}

// ������� ��� ��������������� �������� ����� � ��������� �������
static void createTestData(const string& fname) {
    ofstream ofs(fname, ios::binary);
    if (!ofs) {
        cerr << "�� ������� ������� ����." << endl;
        return;
    }

    // ������ ������
    struct WorkerRecord {
        char position[MAX_STRING_SIZE];
        double salary;
    };

    WorkerRecord testRecords[] = {
        {"�������", 30000},
        {"�������", 50000},
        {"�������", 32000},
        {"��������", 45000},
        {"�������", 31000}
    };

    int count = sizeof(testRecords) / sizeof(testRecords[0]);
    for (int i = 0; i < count; ++i) {
        ofs.write(reinterpret_cast<const char*>(&testRecords[i]), sizeof(WorkerRecord));
    }
}

// ������ ������ � ���� (���� ����� ���, ������� ��� �������������)
static void writeData(const string& fname) {
    if (!fileExists(fname)) {
        cout << "���� �� ������. ������ ���� � ��������� �������..." << endl;
        createTestData(fname);
    }

    // ����� �������� ������� ��� ������� ���������� ������, ���� �����
}

// ������������� � �������� ���������� � ��������
static void analyzeSlesar(const string& fname) {
    ifstream ifs(fname, ios::binary);
    if (!ifs) {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
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
        if (position == "�������" || position.find("�������") != string::npos) {
            totalSlesarSalary += static_cast<int>(record.salary);
            slesarCount++;
        }
    }

    if (slesarCount > 0) {
        double averageSalary = static_cast<double>(totalSlesarSalary) / slesarCount;
        cout << "���������� ��������: " << slesarCount << endl;
        cout << "������� �������� ��������: " << averageSalary << endl;
    }
    else {
        cout << "������� �� �������." << endl;
    }
}

static void var8() {
    // ��������� ������� ����� � ������� ��� ��� �������������
    writeData(filename);

    // ����������� � ������� ���������
    analyzeSlesar(filename);
}