#include "var4.cpp"

int main()
{
    system("chcp 1251 > nul");
    int ct;
    cout << "Введите номер нужной программы: ";
    cin >> ct;
    switch (ct)
    {
    case 1:
        var1();
        break;
    case 2:
        var2();
        break;
    case 3:
        var3();
        break;
    case 4:
        var4();
        break;
    default:
        cout << "Вы выбрали неверный вариант, введите еще раз.\n";
        main();
        break;
    }
    system("pause");
}