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
    string gender; // ���
    string nationality;
    double height; // ����
    double weight; // ���
    string birth_date; // ���� ��������
    string phone_number;
    Address address;
    string credit_card_number;
    string bank_account;
};

// ������� ��� �������� ����� � ������������� �������
static void createSampleFile(const string& filename) {
    ofstream ofs(filename);
    if (!ofs) {
        cerr << "�� ������� ������� ���� ��� ������.\n";
        return;
    }

    // ��������� ���������� �������
    ofs << "������;����;��������;�������;�������;180;80;1985-05-20;89261234567;"
        << "123456,������,�������������� ����,��������� �����,����������,������,12,34\n";

    ofs << "�������;�����;�������������;�������;�������;165;60;1990-08-15;89261234568;"
        << "654321,������,������������� ����,��������� �����,���������,����������,45,67\n";

    ofs << "�������;�������;��������;�������;�������;175;75;1980-12-01;89261234569;"
        << "111222,������,�������������� ����,��������� �����,����������,���������,23,56\n";

    ofs.close();
}

// ������� ��� �������� ������ � ��������� Buyer
static Buyer parseLine(const string& line) {
    Buyer b;

    // ��������� �� ����� � �������
    stringstream ss(line);

    // ��������������� ������� ��� ����������
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
        // ���� � ��� - ����������� � double
        string height_str, weight_str;

        GET_NEXT_FIELD(height_str);
        b.height = stod(height_str);

        GET_NEXT_FIELD(weight_str);
        b.weight = stod(weight_str);
    }

    GET_NEXT_FIELD(b.birth_date);
    GET_NEXT_FIELD(b.phone_number);

    // �����: �������� ������ � ��������� ���� ����� ������� ������ ������
    string address_line;

    GET_NEXT_FIELD(address_line);

    // ������ ��������� ����� �� �������
    stringstream addr_ss(address_line);

    vector<string> addr_fields;

    while (getline(addr_ss, field_str, ',')) {
        addr_fields.push_back(field_str);
    }

    // �������� ���������� ����� ������
    if (addr_fields.size() >= 8) {
        b.address.postal_index = addr_fields[0];
        b.address.country = addr_fields[1];
        b.address.region = addr_fields[2];
        b.address.district = addr_fields[3];
        b.address.city = addr_fields[4];
        b.address.street = addr_fields[5];

        // ��� � �������� - ��������� ��� ����
        b.address.house_number = addr_fields[6];
        b.address.apartment_number = addr_fields[7];
    }

    GET_NEXT_FIELD(b.credit_card_number);
    GET_NEXT_FIELD(b.bank_account);

    return b;

#undef GET_NEXT_FIELD
}


// ������� ��� ��������� ����������� �����
// ������� ��� ��������� ����������� ����� � ���� �������
static void viewFile(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "�� ������� ������� ���� ��� ������.\n";
        return;
    }

    // ��������� �������
    cout << "+---------------+---------------+---------------+--------------+----------------+-------------+-------------+-------------+\n";
    cout << "| �������       | ���           | ��������      | ���          | �������������� | ���� (��)   | ��� (��)    | ���� ����.  |\n";
    cout << "+---------------+---------------+---------------+--------------+----------------+-------------+-------------+-------------+\n";

    string line;
    while (getline(ifs, line)) {
        Buyer b = parseLine(line);

        // ����������� �����, ����� ������� ���� ������� �������� �� 14 ��������
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


// ������� ��� ��������� ����� � ������ ����������� �� ������ ����������
static void processFile(const string& input_filename,
    const string& output_filename) {

    ifstream ifs(input_filename);
    if (!ifs) {
        cerr << "�� ������� ������� ������� ����.\n";
        return;
    }

    ofstream ofs(output_filename);
    if (!ofs) {
        cerr << "�� ������� ������� �������� ����.\n";
        return;
    }

    ofs << "���������� �� ������ ����������:\n";

    string line;
    while (getline(ifs, line)) {
        Buyer b = parseLine(line);

        if (b.address.city == "����������") {
            // ���������� ���������� � ����� ���������� � ����
            ofs << "�������: " << b.last_name << "\n"
                << "���: " << b.first_name << "\n"
                << "��������: " << b.middle_name << "\n"
                << "���: " << b.gender << "\n"
                << "��������������: " << b.nationality << "\n"
                << "����: " << b.height << "\n"
                << "���: " << b.weight << "\n"
                << "���� ��������: " << b.birth_date << "\n"
                << "�������: " << b.phone_number << "\n"
                << "�����:\n"
                << "  �������� ������: " << b.address.postal_index << "\n"
                << "  ������: " << b.address.country << "\n"
                << "  �������: " << b.address.region << "\n"
                << "  �����: " << b.address.district << "\n"
                << "  �����: " << b.address.city << "\n"
                << "  �����: " << b.address.street << "\n"
                << "  ���: " << b.address.house_number << "\n"
                << "  ��������: " << b.address.apartment_number << "\n\n";
        }
    }
}

static void var5() {

    // ������� ���� � �������
    const string filename_in = "buyers.txt";
    createSampleFile(filename_in);

    // �������� ����������� �����
    viewFile(filename_in);

    // ��������� ����� � ����� ����������� �� ���������� � ����� ����
    const string filename_out = "sotovypokupatel.txt";
    processFile(filename_in, filename_out);

    cout << "��������� ���������. ���������� ��������� � '" << filename_out << "'\n";
}