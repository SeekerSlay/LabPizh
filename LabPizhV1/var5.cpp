#include "var4.cpp"
#include <vector>
#include <iomanip>


static struct Address {
    string postal_index;
    string country;
    string region;
    string district;
    string city;
    string street;
    string house_number;
    string apartment_number;
};

static struct Buyer {
    string last_name;
    string first_name;
    string middle_name;
    string gender; // пол
    string nationality;
    double height; // рост
    double weight; // вес
    string birth_date; // дата рождения
    string phone_number;
    Address address;
    string credit_card_number;
    string bank_account;
};

// Функция для создания файла с произвольными данными
static void createSampleFile(const string& filename) {
    ofstream ofs(filename);
    if (!ofs) {
        cerr << "Не удалось открыть файл для записи.\n";
        return;
    }

    // Заполняем примерными данными
    ofs << "Иванов;Иван;Иванович;Мужской;Русский;180;80;1985-05-20;89261234567;"
        << "123456,Россия,Ставропольский край,городской район,Ставрополь,Ленина,12,34\n";

    ofs << "Петрова;Мария;Александровна;Женский;Русская;165;60;1990-08-15;89261234568;"
        << "654321,Россия,Краснодарский край,городской район,Краснодар,Кавказская,45,67\n";

    ofs << "Сидоров;Алексей;Петрович;Мужской;Русский;175;75;1980-12-01;89261234569;"
        << "111222,Россия,Ставропольский край,городской район,Ставрополь,Советская,23,56\n";

    ofs.close();
}

// Функция для парсинга строки в структуру Buyer
static Buyer parseLine(const string& line) {
    Buyer b;

    // Разделяем по точке с запятой
    stringstream ss(line);

    // Вспомогательная функция для разделения
#define GET_NEXT_FIELD(field) \
{ \
    if (getline(ss, field_str, ';')) { \
        field = field_str; \
    } \
}

    string field_str;

    GET_NEXT_FIELD(b.last_name);
    GET_NEXT_FIELD(b.first_name);
    GET_NEXT_FIELD(b.middle_name);
    GET_NEXT_FIELD(b.gender);
    GET_NEXT_FIELD(b.nationality);

    {
        // Рост и вес - преобразуем в double
        string height_str, weight_str;

        GET_NEXT_FIELD(height_str);
        b.height = stod(height_str);

        GET_NEXT_FIELD(weight_str);
        b.weight = stod(weight_str);
    }

    GET_NEXT_FIELD(b.birth_date);
    GET_NEXT_FIELD(b.phone_number);

    // Адрес: почтовый индекс и остальные поля через запятую внутри строки
    string address_line;

    GET_NEXT_FIELD(address_line);

    // Теперь разбираем адрес по запятым
    stringstream addr_ss(address_line);

    vector<string> addr_fields;

    while (getline(addr_ss, field_str, ',')) {
        addr_fields.push_back(field_str);
    }

    // Проверка количества полей адреса
    if (addr_fields.size() >= 8) {
        b.address.postal_index = addr_fields[0];
        b.address.country = addr_fields[1];
        b.address.region = addr_fields[2];
        b.address.district = addr_fields[3];
        b.address.city = addr_fields[4];
        b.address.street = addr_fields[5];

        // Дом и квартира - последние два поля
        b.address.house_number = addr_fields[6];
        b.address.apartment_number = addr_fields[7];
    }

    GET_NEXT_FIELD(b.credit_card_number);
    GET_NEXT_FIELD(b.bank_account);

    return b;

#undef GET_NEXT_FIELD
}


// Функция для просмотра содержимого файла
// Функция для просмотра содержимого файла в виде таблицы
static void viewFile(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "Не удалось открыть файл для чтения.\n";
        return;
    }

    // Заголовки таблицы
    cout << "+---------------+---------------+---------------+--------------+----------------+-------------+-------------+-------------+\n";
    cout << "| Фамилия       | Имя           | Отчество      | Пол          | Национальность | Рост (см)   | Вес (кг)    | Дата рожд.  |\n";
    cout << "+---------------+---------------+---------------+--------------+----------------+-------------+-------------+-------------+\n";

    string line;
    while (getline(ifs, line)) {
        Buyer b = parseLine(line);

        // Форматируем вывод, чтобы столбцы были шириной примерно по 14 символов
        cout << "| "
            << setw(14) << left << b.last_name
            << "| " << setw(14) << left << b.first_name
            << "| " << setw(14) << left << b.middle_name
            << "| " << setw(13) << left << b.gender
            << "| " << setw(15) << left << b.nationality
            << "| " << setw(12) << left << b.height
            << "| " << setw(12) << left << b.weight
            << "| " << setw(12) << left << b.birth_date
            << "|\n";
    }

    cout << "+---------------+---------------+---------------+--------------+----------------+-------------+-------------+-------------+\n";
}


// Функция для обработки файла и поиска покупателей из города Ставрополь
static void processFile(const string& input_filename,
    const string& output_filename) {

    ifstream ifs(input_filename);
    if (!ifs) {
        cerr << "Не удалось открыть входной файл.\n";
        return;
    }

    ofstream ofs(output_filename);
    if (!ofs) {
        cerr << "Не удалось открыть выходной файл.\n";
        return;
    }

    ofs << "Покупатели из города Ставрополь:\n";

    string line;
    while (getline(ifs, line)) {
        Buyer b = parseLine(line);

        if (b.address.city == "Ставрополь") {
            // Записываем информацию о таком покупателе в файл
            ofs << "Фамилия: " << b.last_name << "\n"
                << "Имя: " << b.first_name << "\n"
                << "Отчество: " << b.middle_name << "\n"
                << "Пол: " << b.gender << "\n"
                << "Национальность: " << b.nationality << "\n"
                << "Рост: " << b.height << "\n"
                << "Вес: " << b.weight << "\n"
                << "Дата рождения: " << b.birth_date << "\n"
                << "Телефон: " << b.phone_number << "\n"
                << "Адрес:\n"
                << "  Почтовый индекс: " << b.address.postal_index << "\n"
                << "  Страна: " << b.address.country << "\n"
                << "  Область: " << b.address.region << "\n"
                << "  Район: " << b.address.district << "\n"
                << "  Город: " << b.address.city << "\n"
                << "  Улица: " << b.address.street << "\n"
                << "  Дом: " << b.address.house_number << "\n"
                << "  Квартира: " << b.address.apartment_number << "\n\n";
        }
    }
}

static void var5() {

    // Создаем файл с данными
    const string filename_in = "buyers.txt";
    createSampleFile(filename_in);

    // Просмотр содержимого файла
    viewFile(filename_in);

    // Обработка файла и вывод покупателей из Ставрополя в новый файл
    const string filename_out = "sotovypokupatel.txt";
    processFile(filename_in, filename_out);

    cout << "Обработка завершена. Результаты сохранены в '" << filename_out << "'\n";
}