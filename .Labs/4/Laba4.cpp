#include <iostream>
#include <ctime>

using namespace std;

void Task1(int size, int min, int max);
int rnd(int min, int max);
void Task2(int arr[]);

int main()
{
    system("cls"); //system("cls");
    srand(time(NULL));

    // Вариант 12 

    // ЛР-4
    Task1(5, 0, 10);

    // Індивідуальна робота 1
    int arr[6] = {5, 2, 8, 0, 3, 5};
    Task2(arr);

    cout << "\n";
    cin.ignore().get(); //system("pause");
    system("clear"); //system("cls");

    return 0;
}

void Task1(int size, int min, int max){
    // Дано масив розміру N. Знайти суму елементів масиву,
    // що перевищують число 5.

    int* arr{ new int[size]};
    int sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = rnd(min, max);
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 5)
        {
            sum += arr[i];
        }
        
    }
    cout << "Sum: " << sum << endl;
}

int rnd(int min, int max)
{

    int num = min + rand() % (max - min + 1);

    return num;
}

void Task2(int arr[])
{
    // Дана послідовність чисел, серед яких є один нуль. Вивести всі числа включно до нуля.

    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] == 0){
            break;
        }
        
        cout << arr[i] << " ";

    }
    cout << endl;
    
}
