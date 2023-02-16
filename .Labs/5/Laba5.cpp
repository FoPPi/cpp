#include <iostream>
#include <ctime>

using namespace std;

void Task1(int a, int b);
int rnd(int min, int max);
void Task2(int size, int min, int max);
void Task3(int size, int min, int max);
void Task4(int size, int min, int max);

int main()
{
    system("cls"); //system("cls");
    srand(time(NULL));

    // Вариант 12 

    // ЛР-5
    
    // Розділ І
    // Вариант 2 (так как их там 10)
    Task1(5, 0);
    cout << "--------------------------" << endl;

    // Розділ ІІ
    // Вариант 12
    Task2(8, 0, 1);
    cout << "--------------------------" << endl;

    // Розділ ІІІ
    // Вариант 1 (так как их там 11)
    Task3(8, 0, 1);
    cout << "--------------------------" << endl;

    // Розділ IV
    // Вариант 12
    Task4(5, 0, 9);

    cout << "\n";
    cin.ignore().get(); //system("pause");
    system("clear"); //system("cls");

    return 0;
}

void Task1(int a, int b){
    // Ввести значення 2-х цілих змінних а та b. Створити два вказівники на ці змінні. За допомогою вказівника
    // збільшити значення змінної а в 2 рази якщо а > b, інакше b зменшити у 2 рази.

    int *ia = &a;
    int *ib = &b;

    if (*ia > *ib)
    {
        *ia *= 2;
    }
    else{
        *ib /= 2;
    }

} 

void Task2(int size, int min, int max){
    // Створити динамічні масиви, використовуючи вказівники. У якому з двох даних масивів р(n) та q(n)
    // більше ненульових елементів елементи?
    int* arrP{ new int[size]};
    int* arrQ{ new int[size]};

    int NZp = 0, NZq = 0;

    for (int i = 0; i < size; i++)
    {
        arrP[i] = rnd(min, max);
        if(arrP[i] != 0){
            NZp++;
        }

        arrQ[i] = rnd(min, max);
        if(arrQ[i] != 0){
            NZq++;
        }
        
    }
    cout << endl;
    
    cout << "ArrP: ";
    for (int i = 0; i < size; i++)
    {
        cout << arrP[i] << " ";
    }
    cout << endl;

    cout << "ArrQ: ";
    for (int i = 0; i < size; i++)
    {
        cout << arrQ[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "ArrP count: " << NZp << endl;
    cout << "ArrQ count: " << NZq << endl;

    cout << endl;
    if (NZp > NZq)
    {
        cout << "ArrP more" << endl;
    }
    else if (NZp < NZq)
    {
        cout << "ArrQ more" << endl;
    }
    else{
        cout << "ArrP = ArrQ" << endl;
    }
    
    delete[] arrP;
    delete[] arrQ;

}

void Task3(int size, int min, int max){
    // Створити динамічні масиви, використовуючи вказівники. Дано масив b(n). Переписати в масив C додатні
    // елементи масиву b(n), збільшивши їх на 5 (зі стисненням, без порожніх елементів всередині).

    int* arr{ new int[size]};

    cout << "Arr: ";
    for (int i = 0; i < size; i++)
    {
        arr[i] = rnd(min, max);
        cout << arr[i] << " ";
    }
    cout << endl;

    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > 0){
            count++;
        }
    }
    
    int* arr2{ new int[count]};
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > 0){
            arr2[count] = arr[i] + 5;
            count++;
        }
    }
    
    cout << "Arr 2: ";
    for (int i = 0; i < count; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] arr2;

}

void Task4(int size, int min, int max){
    // У квадратній матриці порядку n знайти добуток елементів стовпчика, в якому розташований
    // максимальний елемент матриці (передбачається, що такий елемент лише один).

    int rows = size, cols = size;
    int** matrix = new int*[rows];
    if (rows)
    {
        matrix[0] = new int[rows * cols];
        for (int i = 1; i < rows; ++i)
            matrix[i] = matrix[0] + i * cols;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rnd(min, max);
            cout << matrix[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    int maxNum = matrix[0][0];
    int maxCol = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (maxNum < matrix[i][j])
            {
                maxNum = matrix[i][j];
                maxCol = j;
            }
            
        }
        
    }

    int dobutoc = 1;
    for (int i = 0; i < rows; i++)
    {
        dobutoc *= matrix[i][maxCol];
    }
    
    cout << "Dobutoc " << maxCol + 1 << " = " << dobutoc << endl;
    
}

int rnd(int min, int max)
{

    int num = min + rand() % (max - min + 1);

    return num;
}
