#include <iostream>

using namespace std;

int main()
{
    int a = 7;
    int b = 3;

    cout << "Start Numbers" << endl;
    cout << "a: " << a << "\t" << "b: " << b << endl;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << endl;
    cout << "Revers Numbers" << endl;
    cout << "a: " << a << "\t" << "b: " << b << endl;

    cin.get();
    return 0;
}