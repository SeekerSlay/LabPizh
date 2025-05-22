#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string.h>


using namespace std;

static vector<string> splitString(const string& str) {
    vector<string> words;
    istringstream stream(str);
    string word;

    // ���������� istringstream ��� ��������� ������ �� �����
    while (stream >> word) {
        words.push_back(word);
    }

    return words;
}

static void var1() {
    string line;
    cout << "������� �����: ";
    getline(cin >> ws, line);
    // ������ �������
    vector<string> cities = splitString(line);
    int count = 0;

    for (const auto& city : cities) {
        // �������� �������� ������ � ������� ��������
        string lowerCity = city;
        transform(lowerCity.begin(), lowerCity.end(), lowerCity.begin(), ::tolower);

        // ���������, ������������� �� �������� �� "����" ��� "grad"
        if (lowerCity.size() >= 4 && (lowerCity.compare(lowerCity.size() - 4, 4, "����") == 0 ||
            lowerCity.compare(lowerCity.size() - 4, 4, "grad") == 0)) {
            count++;
        }
    }

    cout << "���������� �������, �������� ������� ������������� �� '����' ��� 'grad': " << count << endl;
}