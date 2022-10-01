#include <iostream>
#include <time.h>
#include <map> // dict
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;


int rnd(int min, int max);
bool sortByVal(const pair<int, int> &a, const pair<int, int> &b);
void minde(int counte);
bool isNumber(const string& str);

int main()
{
    srand(time(NULL));
    //I LOVE U

    system("cls"); //очистить консоль

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //цвета

    SetConsoleTextAttribute(hConsole, 3); // ставим голубой цвет

    cout << "If u want exit write \"exit\" or \"e\"" << endl; 

    SetConsoleTextAttribute(hConsole, 7); // ставим обычный цвет


    string text = "";
    while (true)
    {
        cout << "Count:";
        cin >> text;

        if(text == "stop" || text == "s" || text == "exit"  || text == "e") //чел хочет выйти
        {
            break;
        }
        else if (isNumber(text)) // если в тексте только цыфры
        {
            minde(stoi(text));
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);

            cout << "Pls enter number" << endl;

            SetConsoleTextAttribute(hConsole, 7);
        }

        getch(); //pause без текста
        system("cls"); //очистить консоль
    }
    cout << "\n";
    system("pause");
    return 0;
}


void minde(int count)
{

    int* arr{ new int[count]};
    map<int, int> identNumCount;


    for (int i = 0; i < count; i++)
    {
        arr[i] = rnd(0, 12);
        cout << arr[i] << " ";
    }

    for (int i = 0; i < count; i++) 
    {
        if (identNumCount.count(arr[i]) > 0)
        {
            identNumCount[arr[i]]++;
        }
        else
        {
            identNumCount.insert({ arr[i], 1 });
        }
    }

    cout << "\n";
    cout << "\n";

    vector<pair<int, int>> vec;

    // copy key-value pairs from the map to the vector
    map<int, int> :: iterator it2;
    for (it2=identNumCount.begin(); it2!=identNumCount.end(); it2++) 
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }

    // sort the vector by increasing order of its pair's second value
    sort(vec.begin(), vec.end(), sortByVal); 

    cout << "num\t" << "count\t" << endl;
    for (auto element : vec)
    {
        cout << element.first << "\t" << element.second << "\t |" <<  round((double)element.second / count * 100) << "%" << endl;
    }
}

int rnd(int min, int max)
{

    int num = min + rand() % (max - min + 1);

    return num;
}

bool sortByVal(const pair<int, int> &a, const pair<int, int> &b) 
{ 
    return (a.second > b.second);
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


