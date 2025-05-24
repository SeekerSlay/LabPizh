#include "var1.cpp"

static void var2() {
    ifstream fin1("a1.txt");
    ifstream fin2("a2.txt");

    if (!fin1) {
        cerr << "�� ������� ������� ���� a1.txt" << endl;
        system("pause");
        exit(0);
    }
    if (!fin2) {
        cerr << "�� ������� ������� ���� a2.txt" << endl;
        system("pause");
        exit(0);
    }

    double num;
    double sum_positive = 0.0;

    // ��������� ������� �����
    while (fin1 >> num) {
        if (num > 0) {
            sum_positive += num;
        }
    }

    // ��������� ������� �����
    while (fin2 >> num) {
        if (num > 0) {
            sum_positive += num;
        }
    }

    fin1.close();
    fin2.close();

    cout << "����� ������������� ��������� � ���� ������: " << sum_positive << endl;
}