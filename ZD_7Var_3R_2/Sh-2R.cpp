
#include <iostream>
#include<math.h>
#include<cmath>
#include<string.h>
#include<fstream>
#include<Windows.h>
#include<string>
using namespace std;

void condition(int b)
{
    if (b == 1)
        cout << "Записать метод, возвращающий число вхождений подстроки в строку." << "\n" << "Строка и подстрока являются неизменяемыми параметрами метода" << "\n" << "\n";
}

bool ask1()
{
    int d;
    cout << "Вывести строку?" << "\n";
    cout << "1 - да" << "\n";
    cout << "любое число - нет" << "\n";
    cin >> d;
    cout << "\n";
    if (d == 1)
        return true;
    else
        return false;
}

int ask2()
{
    int d;
    cout << "Выберите способ ввода подстроки: " << "\n";
    cout << "1 - вводом из файла" << "\n";
    cout << "2 - вводом с клавиатуры" << "\n";
    cin >> d;
    cout << "\n";
    switch (d)
    {
    case 1:
    {
        return 1;
        break;
    }
    case 2:
    {
        return 2;
        break;
    }
    default:
    {
        return 0;
        break;
    }
    }
}

void output(string str, bool c)
{
    if (c == true)
        cout << str << "\n"<<"\n";
}

int maxinp(string pstr)
{
    return pstr.length();
}

string strcom(string str, int min, int max)
{
    string s;
    for (int cnt = min; cnt < max; cnt++)
    {
        s = s + str[cnt];
    }
    return s;
}

void task(string str, string pstr, int min, int max)
{
    int count = 0;
    for (int cnt = 0; cnt <= str.length()-pstr.length(); cnt++)
    {
        if (strcom(str, min, max) == pstr)
        {
            count = count + 1;
        }
        min = min + 1;
        max = max + 1;
    }
    cout << "Количество вхождений подстроки в строку: " << count << "\n"<<"\n";
}

int main()
{
    while (1)
    {
        setlocale(LC_ALL, "Russian");
        const int len = 10;
        char a[len];
        char a0[2] = "0";
        cout << "Выберите действие: " << "\n" << "любой символ - решить задачу" << "\n" << "0 - выход" << "\n";
        cin >> a;
        cout << "\n";
        if (strncmp(a, a0, 1) == 0)
            break;
        else
        {
            while (1)
            {
                SetConsoleCP(1251);
                SetConsoleOutputCP(1251);
                int b;
                cout << "Вывести условие?" << "\n";
                cout << "1 - да" << "\n";
                cout << "любое число - нет" << "\n";
                cin >> b;
                cout << "\n";
                condition(b);
                ifstream File("./File/file1.txt");
                if (File)
                {
                    int con1, con2;
                    bool c;
                    int min = 0;
                    int max=0;
                    int d;
                    string str1;
                    string str2;
                    string fstr1;
                    string fstr2;
                    string pstr1;
                    string pstr2;
                    File >> str1;
                    File >> str2;
                    File >> fstr1;
                    File >> pstr1;
                    File.close();
                    cout << "Вывести пример 1?" << "\n";
                    cout << "любое число - да" << "\n";
                    cout << "0 - нет" << "\n";
                    cin >> con1;
                    cout << "\n";
                    if (con1 != 0)
                    {
                        cout << "Пример 1:" << "\n";
                        c = ask1();
                        output(str1, c);
                        d = ask2();
                        if (d != 1 && d != 2)
                        {
                            cout << "Введено некорректное значение!" << "\n";
                            break;
                        }
                        if (d == 2)
                        {
                            cout << "Введите подстроку: ";
                            cin >> fstr2;
                            cout << "\n";
                        }
                        switch (d)
                        {
                        case 1:
                        {
                            cout<<"Подстрока: "<< fstr1 << "\n"<<"\n";
                            max = maxinp(fstr1);
                            task(str1, fstr1, min, max);
                        }
                        case 2:
                        {
                            int f;
                            if (fstr2.length() == 0)
                            {
                                cout << "Ввести подстроку с клавиатуры?" << "\n";
                                cout << "любое число - да" << "\n";
                                cout << "0 - нет" << "\n";
                                cin >> f;
                                cout << "\n";
                            }
                            else
                                f = 0;
                            if (f != 0)
                            {
                                cout << "Введите подстроку: ";
                                cin >> fstr2;
                                cout << "\n";
                                max = maxinp(fstr2);
                                task(str1, fstr2, min, max);
                            }
                            else
                            {
                                max = maxinp(fstr2);
                                task(str1, fstr2, min, max);
                            }
                            break;
                        }
                        }
                    }
                    cout << "Вывести пример 2?" << "\n";
                    cout << "любое число - да" << "\n";
                    cout << "0 - нет" << "\n";
                    cin >> con2;
                    cout << "\n";
                    if (con2 != 0)
                    {
                        cout << "Пример 2:" << "\n";
                        c = ask1();
                        output(str2, c);
                        d = ask2();
                        if (d != 1 && d != 2)
                        {
                            cout << "Введено некорректное значение!" << "\n";
                            break;
                        }
                        if (d == 2)
                        {
                            cout << "Введите подстроку: ";
                            cin >> pstr2;
                            cout << "\n";
                        }
                        switch (d)
                        {
                        case 1:
                        {
                            cout<<"Подстрока: "<< pstr1 << "\n"<<"\n";
                            max = maxinp(pstr1);
                            task(str2, pstr1, min, max);
                        }
                        case 2:
                        {
                            int g;
                            if (pstr2.length() == 0)
                            {
                                cout << "Ввести подстроку с клавиатуры?" << "\n";
                                cout << "любое число - да" << "\n";
                                cout << "0 - нет" << "\n";
                                cin >> g;
                                cout << "\n";
                            }
                            else
                                g = 0;
                            if (g != 0)
                            {
                                cout << "Введите подстроку: ";
                                cin >> pstr2;
                                cout << "\n";
                                max = maxinp(pstr2);
                                task(str2, pstr2, min, max);
                            }
                            else
                            {
                                max = maxinp(pstr2);
                                task(str2, pstr2, min, max);
                            }
                            break;
                        }
                        }
                    }
                    int e;
                    cout << "Ввести пример самостоятельно?" << "\n";
                    cout << "любое число - да" << "\n";
                    cout << "0 - нет" << "\n";
                    cin >> e;
                    cout << "\n";
                    if (e != 0)
                    {
                        cout << "Пример пользователя:" << "\n";
                        string str3;
                        string pstr;
                        cout << "Введите строку: ";
                        cin >> str3;
                        cout << "\n";
                        cout << "Введите подстроку: ";
                        cin >> pstr;
                        cout << "\n"<<"\n";
                        max = maxinp(pstr);
                        task(str3, pstr, min, max);
                    }
                    break;
                }
                else
                {
                    cout << "Файл не найден!" << "\n";
                    break;
                }
                break;
            }
        }
    }
}