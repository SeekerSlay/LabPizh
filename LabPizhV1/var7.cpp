#include "var6.cpp"

using Matrix = vector<int>;

// ������ ������ �� �����
static vector<Matrix> readMatrices(const string& filename) {
    vector<Matrix> matrices;
    ifstream fin(filename);
    if (!fin) {
        cerr << "�� ������� ������� ����: " << filename << endl;
        return matrices;
    }

    string line;
    while (getline(fin, line)) {
        // ���������� ������ ������
        if (line.empty()) continue;

        istringstream iss(line);
        Matrix mat;
        int num;
        while (iss >> num) {
            mat.push_back(num);
        }
        if (!mat.empty()) {
            matrices.push_back(mat);
        }
    }
    return matrices;
}

// ������ ������ � ���� � ����������� ������ ������� ����� ������ �������
static void writeMatrices(const string& filename, const vector<Matrix>& matrices) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "�� ������� ������� ���� ��� ������: " << filename << endl;
        return;
    }

    for (const auto& mat : matrices) {
        for (size_t i = 0; i < mat.size(); ++i) {
            fout << mat[i];
            if (i != mat.size() - 1)
                fout << " ";
        }
        fout << "\n";
    }
}

// ��������� ���� ������ ����������� �������
static bool areMatricesEqual(const Matrix& a, const Matrix& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// �������� ������� ���������
static void var7() {
    // ������ ������ �� ������
    static vector<Matrix> matricesFile1 = readMatrices("file1.txt");
    static vector<Matrix> matricesFile2 = readMatrices("file2.txt");

    // ��� ������ ������� �� ������� ����� ��������� ������� �� ������ �����
    for (const auto& mat : matricesFile1) {
        bool exists = false;
        for (const auto& mat2 : matricesFile2) {
            if (areMatricesEqual(mat, mat2)) {
                exists = true;
                break;
            }
        }
        // ���� �� ������� ���������� � ���������
        if (!exists) {
            matricesFile2.push_back(mat);
        }
    }

    // ���������� ���������� ������� �� ������ ���� � ����������� ������ ������� ����� ������ �������
    writeMatrices("file2.txt", matricesFile2);

    cout << "��������� ���������." << endl;

    // ����� ����������� �����1.txt
    cout << "\n���������� file1:\n";
    for (const auto& mat : readMatrices("file1.txt")) {
        for (size_t i = 0; i < mat.size(); ++i) {
            cout << mat[i] << (i != mat.size() - 1 ? " " : "");
        }
        cout << "\n";
    }

    // ����� ����������� �����2.txt
    cout << "\n���������� file2:\n";
    for (const auto& mat : readMatrices("file2.txt")) {
        for (size_t i = 0; i < mat.size(); ++i) {
            cout << mat[i] << (i != mat.size() - 1 ? " " : "");
        }
        cout << "\n";
    }
}