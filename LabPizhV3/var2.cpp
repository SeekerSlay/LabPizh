#include <iostream>
#include <string>

using namespace std;

static void var2() {
    cout << "������� �����: ";
    string line;
    getline(cin >> ws, line);

    string modifiedLine;
    bool lastWasSpace = false; // ���� ��� ������������ ���������� �������

    for (char ch : line) {
        if (ch != ' ') { // ���� ������� ������ �� ������
            modifiedLine += ch; // ��������� ��� � ���������
            lastWasSpace = false; // ���������� ����
        }
        else if (!lastWasSpace) { // ���� ������� ������ ������ � ���������� �� ��� ��������
            modifiedLine += ' '; // ��������� ���� ������
            lastWasSpace = true; // ������������� ����
        }
    }

    cout << "\n��������� �����:\n" << modifiedLine << "\n";
}