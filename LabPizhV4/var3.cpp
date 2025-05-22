#include "var2.cpp"

static int countG(const string& city) {
    int count = 0;
    for (char ch : city) {
        if (ch == 'g' || ch == 'G') { // ��������� ��� ��������, ��� � ��������� �����
            count++;
        }
    }
    return count;
}

static void var3() {
    string line;
    cout << "������� �����: ";
    getline(cin >> ws, line);
    // ������ �������
    vector<string> cities = splitString(line);

    string cityWithMaxG;
    int maxCount = 0;

    // ����� ������ � ������������ ����������� ���� 'g'
    for (const auto& city : cities) {
        int gCount = countG(city);
        if (gCount > maxCount) {
            maxCount = gCount;
            cityWithMaxG = city; // ��������� �������� ������ � ������������ ����������� 'g'
        }
    }

    // ������� ���������
    if (maxCount > 0) {
        cout << "����� � ������������ ����������� ���� 'g': " << cityWithMaxG
            << " (" << maxCount << " ����� 'g')" << endl;
    }
    else {
        cout << "� ������ ��� ������� � ������ 'g'." << endl;
    }
}