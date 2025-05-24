#include <iostream>
#include <fstream>

using namespace std;

static void var1() {
    ifstream fin("a.txt");
    if (!fin) {
        cerr << "�� ������� ������� ���� a.txt" << endl;
        system("pause");
        exit(0);
    }

    double num;
    int count_fives = 0;
    double sum_positive = 0.0;

    while (fin >> num) {
        if (num == 5.0) {
            ++count_fives;
        }
        if (num > 0) {
            sum_positive += num;
        }
    }

    fin.close();

    cout << "���������� ��������� ������ 5: " << count_fives << endl;
    cout << "����� ������������� ���������: " << sum_positive << endl;
}