#include "var3.cpp"

static void bubbleSort(vector<string>& names) {
    size_t n = names.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (names[j] > names[j + 1]) {
                swap(names[j], names[j + 1]); // ������ �������
            }
        }
    }
}

static void var4() {
    // ������ ������� �����������
    string line;
    cout << "������� �����: ";
    getline(cin >> ws, line);
    // ������ �������
    vector<string> surnames = splitString(line);

    vector<string> filteredSurnames;

    // ������������ �������, ��� ������ ����� '�'
    for (const auto& surname : surnames) {
        if (surname.length() > 1 && surname[1] == '�') { // ��������� ����� � ������ �����
            filteredSurnames.push_back(surname);
        }
    }

    // ��������� ������ ������ ������� ��������
    bubbleSort(filteredSurnames);

    // ������� ��������������� ������
    cout << "��������������� ������ ������� � ������ ������ '�':" << endl << endl;
    for (const auto& surname : filteredSurnames) {
        cout << surname << endl;
    }
    cout << endl;
}