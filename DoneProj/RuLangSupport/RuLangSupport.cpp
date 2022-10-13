#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <time.h>
//поддержка русского языка
#include <io.h>
#include <fcntl.h>

using namespace std;

int rnd(int min, int max);
int ArrayGen();

int main()
{
    system("cls"); 

    srand(time(NULL));

    // для поддержки
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    // пишем wcout и L(для рУССКОГО языка) потому-что просто cout не работает  
    wcout << L"Задание:\nСоздать массив типа int на 10 элементов и заполнить его случайными числами от 7 до 14. \nПосле заполнения перезаписать все числа, которые больше  десяти:  от хранимого значение отнять 10. \nНапример  в  ячейке хранится число 12: 12 – 10 = 2. \nЗаписать в эту ячейку 2" << endl;
    wcout << "\n";

    ArrayGen();

    wcout << "\n";
    system("pause");
    return 0;
}

int ArrayGen()
{
    int arr[10];

    for(int i = 0; i < 10; i++)
    {
        arr[i] = rnd(7,14);
        wcout << arr[i] << "\t";
    }
    wcout << "\n";
    for (auto ele : arr)
    {
        if(ele > 10){
            ele -= 10;
        }
        wcout << ele << "\t";
    }
    return 0;
}


int rnd(int min, int max)
{

    int num = min + rand() % (max - min + 1);

    return num;
}