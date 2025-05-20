#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

static string toLower(const string& s) {
    string res = s;
    string res1 = "";
    for (int i = 0; i <= s.size(); i++) {
        res1 += tolower(res[i]);
    }
    return res1;
}

static void var1() {
    string line;
    cout << "������� �����: ";
    getline(cin >> ws, line);

    // ������� � ������ ����� "Pascal"
    int pascalCount = 0;
    int computerCount = 0;
    string l = line;

    for (int i = 0; i < line.size();i++) {
        int val = toLower(line).find("pascal");
        int val1 = toLower(l).find("���������");
        int val2 = toLower(l).find("���������");
        if (val != -1) {
            line.replace(toLower(line).find("pascal"), 6, "C++");
            pascalCount++;
        }
        if (val1 != -1) {
            l.replace(l.find("���������"), 9, "0");
            computerCount++;
        }
        if (val2 != -1) {
            l.replace(l.find("���������"), 9, "0");
            computerCount++;
        }
    }

    cout << "\n��������� �����:\n" << line << "\n";
    cout << "���������� ���������� ���� 'Pascal': " << pascalCount << "\n";
    cout << "���������� ���� '���������': " << computerCount << "\n";
}