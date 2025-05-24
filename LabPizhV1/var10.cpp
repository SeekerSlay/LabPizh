#include "var9.cpp"

const string studentFilename = "students.dat";

struct Student {
    char surnameInitials[50]; // ������� � ��������
    char groupNumber[10];     // ����� ������
    int grades[3];            // ������ �� 3 �����������
    double scholarship;       // ������ ���������
};

// ����������� ������� ��� �������� �������� ������
static void createTestStudents(const string& fname) {
    ofstream ofs(fname, ios::binary);
    if (!ofs) {
        cerr << "�� ������� ������� ����." << endl;
        return;
    }

    Student students[] = {
        {"������ �.�.", "101", {5, 5, 5}, 1000},
        {"������ �.�.", "102", {4, 5, 5}, 1200},
        {"������� �.�.", "103", {5, 5, 5}, 1500},
        {"��������� �.�.", "104", {3, 4, 5}, 1100},
        {"������� �.�.", "105", {5, 5, 5}, 1300}
    };

    int count = sizeof(students) / sizeof(students[0]);
    for (int i = 0; i < count; ++i) {
        ofs.write(reinterpret_cast<const char*>(&students[i]), sizeof(Student));
    }
}

// ����������� ������� ��� ���������� ��������� � ��������� �� ����� ���������
static void updateScholarships(const string& fname) {
    ifstream ifs(fname, ios::binary);
    if (!ifs) {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
        return;
    }

    vector<Student> allStudents;

    // ������ ��� ������
    Student temp;
    while (ifs.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        allStudents.push_back(temp);
    }
    ifs.close();

    // ��������� ������: ����������� ��������� �� 50% � ��������� �� ����� ���������
    for (auto& student : allStudents) {
        bool allFives = true;
        for (int grade : student.grades) {
            if (grade != 5) {
                allFives = false;
                break;
            }
        }
        if (allFives) {
            student.scholarship *= 1.5; // ���������� �� 50%
        }
    }

    // �������������� ���� � ������������ �������
    ofstream ofs(fname, ios::binary | ios::trunc);
    if (!ofs) {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
        return;
    }

    for (const auto& student : allStudents) {
        ofs.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }
}

// ����������� �������-������� ��� ���������� ���� ������
static void var10() {
    // �������� ������������� ����� � �������� �������� ������ ��� �������������
    ifstream testFile(studentFilename);
    if (!testFile.good()) {
        cout << "���� �� ������. ������ �������� ������..." << endl;
        createTestStudents(studentFilename);
    }
    else {
        testFile.close();
    }


    ifstream inFile1(studentFilename, ios::binary);
    cout << "������������� ������ ���������:" << endl;

    Student s1;
    while (inFile1.read(reinterpret_cast<char*>(&s1), sizeof(Student))) {
        cout << "������� � ��������: " << s1.surnameInitials
            << ", ������: " << s1.groupNumber
            << ", ������: [" << s1.grades[0] << ", " << s1.grades[1] << ", " << s1.grades[2] << "]"
            << ", ���������: " << s1.scholarship << endl;
    }

    // ��������� ��������� � ��������� �� ����� ���������
    updateScholarships(studentFilename);

    cout << endl;
    // ��� �������� ������� ���������� ����� ����� ����������
    ifstream inFile(studentFilename, ios::binary);
    cout << "����������� ������ ���������:" << endl;

    Student s;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        cout << "������� � ��������: " << s.surnameInitials
            << ", ������: " << s.groupNumber
            << ", ������: [" << s.grades[0] << ", " << s.grades[1] << ", " << s.grades[2] << "]"
            << ", ���������: " << s.scholarship << endl;
    }
    cout << endl;
}