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

    cout << "\n";
    system("pause");
    return 0;
}