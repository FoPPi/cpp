#include <iostream>
#include <time.h>

using namespace std;

int rnd(int min, int max);

int main()
{   
    srand(time(NULL));

    system("cls"); //system("cls");

    int rows = 2, cols = 6;
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
            matrix[i][j] = rnd(0,9);
        }
        
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }



    // Дана матриця розмірності MxN. Знайти суму найбільших значень елементів її рядків;

    // for (int i = 0; i < rows; i++)
    // {
    //     int sum = 0;
    //     int max = matrix[i][0];
    //     for (int j = 1; j < cols; j++)
    //     {
    //         if(matrix[i][j] > max){
    //             max = matrix[i][j];
    //         }
    //     }
    //     for (int k = 0; k < cols; k++)
    //     {
    //         if(max == matrix[i][k]){
    //             sum += matrix[i][k];
    //         }
    //     }
        
    //     cout << i+1 << ") Sum of max: " << sum << endl;
    // }



    // У двовимірному масиву NxM непарні елементи збільшити вдвічі, а парні - зменшити вдвічі. Нулі замінити числом 100.

    
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         if(matrix[i][j] == 0){
    //             matrix[i][j] = 100;
    //         }
    //         else if (matrix[i][j] % 2 == 0)
    //         {
    //             matrix[i][j] /= 2;
    //         }
    //         else if (matrix[i][j] % 2 != 0)
    //         {
    //             matrix[i][j] *=2;
    //         }
    //     }
    // }

    for (int i = 0; i < cols; i++)
    {
        int count = 0;
        for (int j = 0; j < rows; j++)
        {
            if (matrix[j][i] % 2 != 0) {
                break;
            }
            else{
                count++;
            }
        }
        if(count == rows){
            cout << i + 1 << " col" << " true" << endl;
        }
        else
        {
            cout << i + 1 << " col" << " false" << endl;
        }
        
    }
    

    // cout << "\n";
    // cin.ignore().get(); //system("pause");
    // system("clear"); //system("cls");

    return 0;
}


int rnd(int min, int max)
{

    int num = min + rand() % (max - min + 1);

    return num;
}
