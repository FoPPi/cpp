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


//обявление
int rnd(int min, int max);
bool sortByVal(const pair<int, int> &a, const pair<int, int> &b);
void mind(int counte);
bool isNumber(const string& str);

int main()
{
    srand(time(NULL)); // чтоб рандом работал

    system("cls"); // очистить консоль

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // цвета

    SetConsoleTextAttribute(hConsole, 3); // ставим голубой цвет

    cout << "If u want exit write \"exit\" or \"e\"" << endl; 

    SetConsoleTextAttribute(hConsole, 7); // ставим обычный цвет


    string text = "";
    while (true)
    {
        cout << "Count:";
        cin >> text;

        if(text == "stop" || text == "s" || text == "exit"  || text == "e") // чел хочет выйти
        {
            break;
        }
        else if (isNumber(text)) // если в тексте только цыфры
        {
            mind(stoi(text)); // запуск основной программы
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


void mind(int count)
{

    int* arr{ new int[count]}; // массив с количеством элементов count
    map<int, int> identNumCount; // dict с ключом int и значением int


    // рандомно заполняем ячейки в arr
    for (int i = 0; i < count; i++) 
    {
        arr[i] = rnd(0, 12); // Присваиваем рандомные значение от 0 и до 12 для определённого элемента массива
        cout << arr[i] << " ";
    }

    // подсчёт количества уникальных чисел 
    for (int i = 0; i < count; i++) 
    {
        if (identNumCount.count(arr[i]) > 0) // если такое число встречалось, то добавляем + 1 в dict
        {
            identNumCount[arr[i]]++;
        }
        else  // если такое число не встречалось, то создаём новую ячейку со значением 1
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


    // вывод значений
    cout << "num\t" << "count\t" << endl;
    for (auto element : vec)
    {
        cout << element.first << "\t" << element.second << "\t |" <<  round((double)element.second / count * 100) << "%" << endl;
    }
}


// генерируем случайное число в рамках min и max
int rnd(int min, int max)
{

    int num = min + rand() % (max - min + 1);

    return num;
}

// сортировка по значению 
bool sortByVal(const pair<int, int> &a, const pair<int, int> &b) 
{ 
    return (a.second > b.second);
} 

// если в тексте только цифры
bool isNumber(const string& str)
{
    for (char const &c : str) 
    {
        if (std::isdigit(c) == 0) 
            return false;
    }
    return true;
}


