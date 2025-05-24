#include "var3.cpp"

static void var4() {
    ifstream fin("numbers.txt");
    if (!fin) {
        cerr << "�� ������� ������� ���� numbers.txt" << endl;
        system("pause");
        exit(0);
    }

    int num;
    int position = 1; // ������� �������� (���������� � 1)
    int count_negatives_odd_positions = 0;

    while (fin >> num) {
        if (position % 2 != 0 && num < 0) {
            ++count_negatives_odd_positions;
        }
        ++position;
    }

    fin.close();

    cout << "���������� ������������� ��������� �� �������� ��������: "
        << count_negatives_odd_positions << endl;
}