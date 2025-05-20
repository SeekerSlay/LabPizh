#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// ������� ��� ���������� ����� �� ������ � �������� ���������� � ���� ������
static vector<int> stringToVectorInt(const string& str, size_t a) {
    vector<int> result;

    int N = stoi(str);
    int i = 0;
    while (i < a)
    {
        result.push_back(N % 10);
        N /= 10;
        i++;
    }

    return result;
}

static void var3() {
    cout << "������� �����: ";
    string line;
    getline(cin >> ws, line);

    // ������� ������� ������� '*'
    int starPos = line.find("*");

    if (starPos == -1)
    {
        cout << "������ '*' �� ������ � ������." << endl;
    }
    else
    {
        // ��������� ��������� ����� '*'
        string beforeStar = line.substr(0, starPos);
        vector<int> numbers = stringToVectorInt(beforeStar, beforeStar.size());
        sort(begin(numbers), end(numbers));
        // ������� ���������� �����
        cout << "���������� �����: ";
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            cout << numbers[i];
        }
        cout << endl;
    }
}