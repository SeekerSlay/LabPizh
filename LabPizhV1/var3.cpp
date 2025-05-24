#include "var2.cpp"
#include <string>
#include <sstream>

static void var3() {
    ifstream fin("input.txt");   // �������� ����
    ofstream fout("output.txt"); // ���� ��� ����������

    if (!fin) {
        cerr << "�� ������� ������� ������� ���� input.txt" << endl;
        system("pause");
        exit(0);
    }
    if (!fout) {
        cerr << "�� ������� ������� �������� ���� output.txt" << endl;
        system("pause");
        exit(0);
    }

    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string word;
        bool first_word = true;

        // ��������� ������: ���������� ������ ������� ����� �������
        while (iss >> word) {
            if (first_word) {
                fout << word; // ������ ����� ��� �������
                first_word = false;
            }
            else {
                fout << " " << word; // ��������� ���� ������ ����� ������
            }
        }
        fout << "\n"; // ������� ������ ����� ��������� ������ ������
    }

    fin.close();
    fout.close();

    cout << "��������� ���������. ������ ������� �������." << endl;
}