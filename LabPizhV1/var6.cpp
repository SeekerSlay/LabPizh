#include "var5.cpp"
#include <limits>

static void var6() {
    ifstream inputFile("input2.txt");
    if (!inputFile) {
        cerr << "�� ������� ������� ���� input2.txt" << endl;
        system("pause");
        exit(0);
    }

    vector<double> numbers;
    double num;

    // ������ ����� �� �����
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        cerr << "���� �� �������� �����." << endl;
        system("pause");
        exit(0);
    }

    // ������������� ���������� ��� ������ min � max
    double minVal = numeric_limits<double>::max();
    double maxVal = numeric_limits<double>::lowest();

    for (double n : numbers) {
        if (n > maxVal) maxVal = n;
        if (n < minVal) minVal = n;
    }

    double sum = maxVal + minVal;

    // ������ ����������� � ���� result.txt
    ofstream outputFile("result.txt");
    if (!outputFile) {
        cerr << "�� ������� ������� ���� result.txt" << endl;
        system("pause");
        exit(0);
    }

    outputFile << "���������� ��������: " << maxVal << "\n";
    outputFile << "���������� ��������: " << minVal << "\n";
    outputFile << "����� ����������� � �����������: " << sum << "\n";
    cout << "������ �������� � ����." << endl;
    cout << "���������� ��������: " << maxVal << endl;
    cout << "���������� ��������: " << minVal << endl;
    cout << "����� ����������� � �����������: " << sum << endl;
}