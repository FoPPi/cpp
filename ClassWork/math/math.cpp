#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    system("cls"); 

    double a = 4;
    double b = 2;
    // 1
    double pluspow = sqrt(pow(a, 2) + pow(b, 2));
    cout << "1: " << pluspow << endl;

    // 2
    pluspow = pow(a + b, 1.0 / 7);
    cout << "2: " << pluspow << endl;

    // 3
    pluspow = cbrt(pow(a, 12) + pow(b, 4));
    cout << "3: " << pluspow << endl;



    cout << "\n";
    system("pause");
    return 0;
}