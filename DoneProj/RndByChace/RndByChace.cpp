#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>


using namespace std;

bool fartuna(int chance);
int rnd(int min, int max);
bool isNumber(const string& str);


int main()
{

    system("cls"); 


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // цвета

    SetConsoleTextAttribute(hConsole, 3); // ставим голубой цвет

    cout << "If u want exit write \"exit\" or \"e\"" << endl; 

    SetConsoleTextAttribute(hConsole, 7); // ставим обычный цвет


    string text = "";
    while (true)
    {
        cout << "%:";
        cin >> text;

        if(text == "stop" || text == "s" || text == "exit"  || text == "e") // чел хочет выйти
        {
            break;
        }
        else if (isNumber(text)) // если в тексте только цыфры
        {
            if(fartuna(stoi(text))) // запуск основной программы
            {
                cout << "U win";
            }
            else
            {
                cout << "U lose";
            }
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);

            cout << "Pls enter number" << endl;

            SetConsoleTextAttribute(hConsole, 7);
        }

        getch(); // pause без текста
        system("cls"); // очистить консоль
    }
    

    cout << "\n";
    system("pause");
    return 0;
}


bool fartuna(int chance)
{
    if(chance >= rnd(1,100))
    {
        return true;
    }
    else
    {
        return false;
    }
}


int rnd(int min, int max)
{

    int num = min + rand() % (max - min + 1);

    return num;
}


bool isNumber(const string& str)
{
    for (char const &c : str) 
    {
        if (std::isdigit(c) == 0) 
            return false;
    }
    return true;
}