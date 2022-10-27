#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int* strToTime(string s, string delimiter);

int main()
{
    system("cls"); 


    //-------------------
    //1
    cout << "#1" << endl;
    cout << "Radius: ";
    int num1 = 0;
    cin >> num1;

    cout << "S: " << 3.141 * pow(num1, 2) << endl;

    cout << "\n";
    system("pause");
    system("cls");




    //-------------------
    //2
    cout << "#2" << endl;
    
    int petroSpent = 0, sergiySpent = 0, katerinaSpent = 0;
    int Sum = 8;

    cout << "Sum: " << Sum << endl;

    petroSpent = Sum / 2 / 2;
    sergiySpent = petroSpent;
    katerinaSpent = Sum/2;

    cout << "Petr: " << petroSpent << endl <<
            "Serg: " << sergiySpent << endl <<
            "Katya: " << katerinaSpent << endl;

    cout << "\n";
    system("pause");
    system("cls");




    //-------------------
    //3
    cout << "#3" << endl;

    cout << "The output should be similar to:" << endl << "hh:mm:ss" << endl;
    
    string sDate1 = "";
    cout << "Date 1: ";
    cin >>  sDate1;
    int* arrDate1 = strToTime(sDate1, ":");

    string sDate2 = "";
    cout << "Date 2: ";
    cin >>  sDate2;
    int* arrDate2 = strToTime(sDate2, ":");

    int seconds = 0;

    seconds = (arrDate2[0] - arrDate1[0]) * 3600 + (arrDate2[1] - arrDate1[1]) * 60 + (arrDate2[2] - arrDate1[2]);

    cout << "Seconds: " << seconds << endl;

    cout << "\n";
    system("pause");
    system("cls");




    //-------------------
    //4
    cout << "#4" << endl;

    string num4 = "";
    cout << "Enter number: ";
    cin >> num4;
    int count = 0;
    for(int i = 0; i < num4.length(); i++){
        if( num4[i] % 2 == 0){
            count++;
        }
    }
    cout << "Count: " << count << endl;

    cout << "\n";
    system("pause");
    system("cls");




    //-------------------
    //5 b
    cout << "#5b" << endl;

    double a = 0 , b = 0, c = 0;
    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter c: ";
    cin >> c;


    cout << "F = " << tan(a) - abs(b - 3 * a + 2 / cbrt(a + 4));

    cout << "\n";
    system("pause");
    system("cls");

    return 0;
}


int* strToTime(string s, string delimiter){
    
    size_t pos = 0;
    int* arr{ new int[3]}; 
    int i = 0;
    
    auto start = 0U;
    auto end = s.find(delimiter);
    while (end != string::npos)
    {
        arr[i] = stoi(s.substr(start, end - start));
        i++;
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }

    arr[i] = stoi(s.substr(start, end));

    return arr;
}