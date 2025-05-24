#include "var10.cpp"

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
    case 5:
        var5();
        break;
    case 6:
        var6();
        break;
    case 7:
        var7();
        break;
    case 8:
        var8();
        break;
    case 9:
        var9();
        break;
    case 10:
        var10();
        break;
    default:
        cout << "Вы выбрали неверный вариант, введите еще раз.\n";
        main();
        break;
    }
    system("pause");
}