#include "var8.cpp"
#include <cctype> // ��� toupper

const string filename1 = "symbols.bin";

// ������� ��� ������ ����������� �����
static void printFileContents(const string& fname) {
    ifstream ifs(fname, ios::binary);
    if (!ifs) {
        cout << "�� ������� ������� ����." << endl;
        return;
    }

    cout << "������� � �����: ";
    char ch;
    while (ifs.read(&ch, 1)) {
        cout << ch;
    }
    cout << endl;
}

// ������� ��� ������ ������ � �������� ����
static void writeStringToFile(const string& str, const string& fname) {
    ofstream ofs(fname, ios::binary);
    for (char ch : str) {
        ofs.write(&ch, 1);
    }
}

// ������� ��� ������ �������� �� ����� � ������
static string readFileToString(const string& fname) {
    ifstream ifs(fname, ios::binary);
    string result;
    char ch;
    while (ifs.read(&ch, 1)) {
        result += ch;
    }
    return result;
}

// �������� ������� ���������
static void var9() {
    // ���� ������ �������������
    cout << "������� ������ ��������� ��������: ";
    string inputStr;
    getline(cin >> ws, inputStr);

    // ������ �������� �������� � �������� ����
    writeStringToFile(inputStr, filename1);

    // ����� ����������� ����� �� ���������
    cout << "\n�� ���������:" << endl;
    printFileContents(filename1);

    // ������ ������ �� �����
    string data = readFileToString(filename1);

    // �������������� ���� �������� � ��������� �����
    for (char& ch : data) {
        ch = toupper(static_cast<unsigned char>(ch));
    }

    // ���������� ����� � ���������� �������
    writeStringToFile(data, filename1);

    // ����� ����������� ����� ����� ���������
    cout << "\n����� ���������:" << endl;
    printFileContents(filename1);
}