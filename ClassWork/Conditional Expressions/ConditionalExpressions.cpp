#include <iostream>

using namespace std;


int main()
{

    system("cls"); 

    int a = 0;
    int b = 0;
    int c = -9;


    int arr[3] {a, b, c};
    int count = 0;

    for(int i = 0; i < 3; i++){
        if(arr[i] == 0){
            count++;
        }
    }

    cout << count;

    // > >= < <= == != !

    int n = 4;
    bool isOdd = n % 2;
    if (isOdd)
        cout << "isOdd" << endl;
        cout << n << endl;

    
    if (isOdd)
    { 
        cout << "isOdd" << endl;
        cout << n << endl;
    }
    else{
        cout << "even" << endl;
    }
    

    

    int a;
    a = 4;//cin >> a;

    int b;
    b = 85; //cin >> b;

    // 2. Знайти максимальне число.
    int max = a;
    bool res = (a > b);
    if (a > b) 
    { 
        max = a;
    }
    cout << max;


    n = 3;
    switch (n)
    {
    case 1:
        cout << "One";
        break;
    case 2:
        cout << "Two";
        break;
    case 3:
        cout << "Tree";
        break;
    case 4:
        cout << "Four";
        break;
    
    default:
        cout << "Error";
        break;
    }

    cin >> n;
    if(n > 0){
        cout << "positive";
    }
    else if (n < 0)
    {
        cout << "negative";
    }
    else{
        cout << "zero";
    }

    cout << "\n";
    system("pause");
    return 0;
}