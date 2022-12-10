#include <iostream>
#include <cmath>

using namespace std;

bool Task1();
double Task2(int n, int i, double x);
long double Factorial(int num);

int main()
{
    system("cls"); //system("cls");

    // Вариант 12 
    cout << Task1() << endl;

    cout << Task2(6, 2, 8.25) << endl;

    cout << "\n";
    cin.ignore().get(); //system("pause");
    system("clear"); //system("cls");

    return 0;
}

bool Task1(){
    int num = 0, counter = 0;

    do{
        cin >> num;
        if(num % 3 == 0 && num % 5 == 0){
            counter++;
        }
    }while (num != 0);
    

    if (counter >= 2){
        return true;
    }
    else{
        return false;
    }
    
}



double Task2(int n, int i, double x)
{
    double P = 1;
    for (;i <= n; i++)
    {
        P *= (cos(0.6 * i + Factorial(i))) / (sqrt(i - 1) + sin(x + i));
    }
    return P;
}

long double Factorial(int num)
{
    long double fac = 1;
    while (num > 1)
    {
        fac *= num--;
    }
    
    return fac;
}
