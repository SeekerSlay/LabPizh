#include "var6.cpp"

using Matrix = vector<int>;

// Чтение матриц из файла
static vector<Matrix> readMatrices(const string& filename) {
    vector<Matrix> matrices;
    ifstream fin(filename);
    if (!fin) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return matrices;
    }

    string line;
    while (getline(fin, line)) {
        // пропускаем пустые строки
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

// Запись матриц в файл с разделением пустой строкой после каждой матрицы
static void writeMatrices(const string& filename, const vector<Matrix>& matrices) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "Не удалось открыть файл для записи: " << filename << endl;
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

// Сравнение двух матриц произвольно размера
static bool areMatricesEqual(const Matrix& a, const Matrix& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Основная функция обработки
static void var7() {
    // Чтение матриц из файлов
    static vector<Matrix> matricesFile1 = readMatrices("file1.txt");
    static vector<Matrix> matricesFile2 = readMatrices("file2.txt");

    // Для каждой матрицы из первого файла проверяем наличие во втором файле
    for (const auto& mat : matricesFile1) {
        bool exists = false;
        for (const auto& mat2 : matricesFile2) {
            if (areMatricesEqual(mat, mat2)) {
                exists = true;
                break;
            }
        }
        // Если не найдено совпадения — добавляем
        if (!exists) {
            matricesFile2.push_back(mat);
        }
    }

    // Записываем обновлённые матрицы во второй файл с разделением пустой строкой после каждой матрицы
    writeMatrices("file2.txt", matricesFile2);

    cout << "Обработка завершена." << endl;

    // Вывод содержимого файла1.txt
    cout << "\nСодержимое file1:\n";
    for (const auto& mat : readMatrices("file1.txt")) {
        for (size_t i = 0; i < mat.size(); ++i) {
            cout << mat[i] << (i != mat.size() - 1 ? " " : "");
        }
        cout << "\n";
    }

    // Вывод содержимого файла2.txt
    cout << "\nСодержимое file2:\n";
    for (const auto& mat : readMatrices("file2.txt")) {
        for (size_t i = 0; i < mat.size(); ++i) {
            cout << mat[i] << (i != mat.size() - 1 ? " " : "");
        }
        cout << "\n";
    }
}