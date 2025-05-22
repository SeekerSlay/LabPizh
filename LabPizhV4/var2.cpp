#include "var1.cpp"

static void var2() {
    string line;
    cout << "������� �����: ";
    getline(cin >> ws, line);
    // ������ �������
    vector<string> cities = splitString(line);

    // ������������� ���������� ��� �������� ��������
    int minIndex = 0;
    int maxIndex = 0;

    // ����� ������ ��������� � ������ �������� �������� ������
    for (size_t i = 1; i < cities.size(); ++i) {
        if (cities[i].length() < cities[minIndex].length()) {
            minIndex = i; // ��������� ������ ������ ��������� ������
        }
        if (cities[i].length() > cities[maxIndex].length()) {
            maxIndex = i; // ��������� ������ ������ �������� ������
        }
    }

    // ������ ������� �������� ������ �������� � ������ ��������� ������
    swap(cities[minIndex], cities[maxIndex]);

    // ������� ���������� ������ �������
    cout << "���������� ������ �������:" << endl;
    for (const auto& city : cities) {
        cout << city << " ";
    }

    cout << endl;
}