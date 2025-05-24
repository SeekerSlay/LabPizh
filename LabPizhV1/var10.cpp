#include "var9.cpp"

const string studentFilename = "students.dat";

struct Student {
    char surnameInitials[50]; // фамилия и инициалы
    char groupNumber[10];     // номер группы
    int grades[3];            // оценки по 3 дисциплинам
    double scholarship;       // размер стипендии
};

// Статическая функция для создания тестовых данных
static void createTestStudents(const string& fname) {
    ofstream ofs(fname, ios::binary);
    if (!ofs) {
        cerr << "Не удалось создать файл." << endl;
        return;
    }

    Student students[] = {
        {"Иванов И.И.", "101", {5, 5, 5}, 1000},
        {"Петров П.П.", "102", {4, 5, 5}, 1200},
        {"Сидоров С.С.", "103", {5, 5, 5}, 1500},
        {"Кузнецова А.А.", "104", {3, 4, 5}, 1100},
        {"Морозов М.М.", "105", {5, 5, 5}, 1300}
    };

    int count = sizeof(students) / sizeof(students[0]);
    for (int i = 0; i < count; ++i) {
        ofs.write(reinterpret_cast<const char*>(&students[i]), sizeof(Student));
    }
}

// Статическая функция для обновления стипендий у студентов со всеми пятерками
static void updateScholarships(const string& fname) {
    ifstream ifs(fname, ios::binary);
    if (!ifs) {
        cerr << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    vector<Student> allStudents;

    // Читаем все записи
    Student temp;
    while (ifs.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        allStudents.push_back(temp);
    }
    ifs.close();

    // Обновляем данные: увеличиваем стипендию на 50% у студентов со всеми пятерками
    for (auto& student : allStudents) {
        bool allFives = true;
        for (int grade : student.grades) {
            if (grade != 5) {
                allFives = false;
                break;
            }
        }
        if (allFives) {
            student.scholarship *= 1.5; // увеличение на 50%
        }
    }

    // Перезаписываем файл с обновленными данными
    ofstream ofs(fname, ios::binary | ios::trunc);
    if (!ofs) {
        cerr << "Не удалось открыть файл для записи." << endl;
        return;
    }

    for (const auto& student : allStudents) {
        ofs.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }
}

// Статическая функция-обертка для выполнения всей логики
static void var10() {
    // Проверка существования файла и создание тестовых данных при необходимости
    ifstream testFile(studentFilename);
    if (!testFile.good()) {
        cout << "Файл не найден. Создаю тестовые данные..." << endl;
        createTestStudents(studentFilename);
    }
    else {
        testFile.close();
    }


    ifstream inFile1(studentFilename, ios::binary);
    cout << "Необновленные данные студентов:" << endl;

    Student s1;
    while (inFile1.read(reinterpret_cast<char*>(&s1), sizeof(Student))) {
        cout << "Фамилия и инициалы: " << s1.surnameInitials
            << ", Группа: " << s1.groupNumber
            << ", Оценки: [" << s1.grades[0] << ", " << s1.grades[1] << ", " << s1.grades[2] << "]"
            << ", Стипендия: " << s1.scholarship << endl;
    }

    // Обновляем стипендии у студентов со всеми пятерками
    updateScholarships(studentFilename);

    cout << endl;
    // Для проверки выводим содержимое файла после обновления
    ifstream inFile(studentFilename, ios::binary);
    cout << "Обновленные данные студентов:" << endl;

    Student s;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        cout << "Фамилия и инициалы: " << s.surnameInitials
            << ", Группа: " << s.groupNumber
            << ", Оценки: [" << s.grades[0] << ", " << s.grades[1] << ", " << s.grades[2] << "]"
            << ", Стипендия: " << s.scholarship << endl;
    }
    cout << endl;
}