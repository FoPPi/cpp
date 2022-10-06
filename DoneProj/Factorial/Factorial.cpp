#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;


long double Factorial(int num);
bool isNumber(const string& str);

int main()
{
    system("cls"); //очистить консоль

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //цвета

    SetConsoleTextAttribute(hConsole, 3); // ставим голубой цвет

    cout << "If u want exit write \"exit\" or \"e\"" << endl; 

    SetConsoleTextAttribute(hConsole, 7); // ставим обычный цвет


    string text = "";
    while (true)
    {
        cout << "Number:";
        cin >> text;

        if(text == "stop" || text == "s" || text == "exit"  || text == "e") // чел хочет выйти
        {
            break;
        }
        else if (isNumber(text)) // если в тексте только цифры
        {
            if(stod(text) < 0)
            {
                cout << "inf" << endl;
            }
            else
            {
                cout << Factorial(stoi(text)) << endl;
            }
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);

            cout << "Pls enter number" << endl;

            SetConsoleTextAttribute(hConsole, 7);
        }

        getch(); //wait без текста
        system("cls"); //очистить консоль
    }

    system("pause"); //wait с текстом
    return 0;
}

//считаем факториал
long double Factorial(int num)
{
    long double fac = 1;
    while (num > 1)
    {
        fac *= num--;
    }
    
    return fac;
}


//проверяем наличия букв
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0 && c != '-') return false;
    }
    return true;
}



