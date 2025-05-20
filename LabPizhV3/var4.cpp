#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

// ������� ��� �������� �������� �� ������
static string removeSpaces(const string& str) {
    string result;
    for (char c : str) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

// ������� ��� �������� ��������� �������� �� str1 � str2
static unordered_map<char, int> countCharacters(const string& str1, const string& str2) {
    unordered_map<char, int> countMap;

    // ������� ������� �� �����
    string cleanedStr1 = removeSpaces(str1);
    string cleanedStr2 = removeSpaces(str2);

    // �������������� ������� ��� ������� ������� �� cleanedStr1
    for (char c : cleanedStr1) {
        countMap[c] = 0;
    }

    // ������������ ���������� ��������� ������� ������� �� cleanedStr1 �� ������ ������
    for (char c : cleanedStr2) {
        if (countMap.find(c) != countMap.end()) {
            countMap[c]++;
        }
    }

    return countMap;
}

// ������� ��� ������ ����� "���������" �� "��"
static string replaceComputerWithPC(const string& text) {
    string result = text;
    size_t pos = 0;

    // �������� ��� ��������� ����� "���������" �� "��"
    while ((pos = result.find("���������", pos)) != string::npos) {
        result.replace(pos, 10, "��");
        pos += 2; // ���������� ���������� �����
    }

    return result;
}

static void var4() {
    cout << "������� �����: ";
    string str1;
    getline(cin >> ws, str1);
    cout << "������� �����: ";
    string str2;
    getline(cin >> ws, str2);

    // ������� ��������
    unordered_map<char, int> characterCounts = countCharacters(str1, str2);

    cout << "���������� ��������� ��������:" << endl;
    for (const auto& pair : characterCounts) {
        cout << "'" << pair.first << "' � ����������� " << pair.second << " ���" << endl;
    }

    // ������ ����
    string updatedText = replaceComputerWithPC(str1);

    cout << "\n����������� �����:" << endl;
    cout << updatedText << endl;
}