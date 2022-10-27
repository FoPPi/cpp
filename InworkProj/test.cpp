#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int* strToDate(string s, string delimiter);

int main()
{
    system("cls"); 

    //1
    cout << "#1" << endl;
    cout << "Radius: ";
    int num = 0;
    cin >> num;

    cout << "S: " << 3.141 * pow(num, 2) << endl;

    cout << "\n";
    system("pause");
    system("cls");

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

    //3
    cout << "#3" << endl;

    cout << "The output should be similar to:" << endl << "23 59 59" << endl;
    
    string sDate1 = "";
    cout << "Date 1: ";
    cin >>  sDate1;
    int* arrDate1 = strToDate(sDate1, " ");

    string sDate2 = "";
    cout << "Date 2: ";
    cin >>  sDate2;
    int* arrDate2 = strToDate(sDate2, " ");

    int seconds = 0;
    if(arrDate1[0] <= arrDate2[0] && arrDate1[1] <= arrDate2[1]){
        seconds = (arrDate2[0] - arrDate1[0]) * 3600 + (arrDate2[1] - arrDate1[1]) * 60 + (arrDate2[2] - arrDate1[2]);
    }

    cout << "Seconds: " << seconds << endl;

    cout << "\n";
    system("pause");
    system("cls");

    return 0;
}


int* strToDate(string s, string delimiter){
    
    size_t pos = 0;
    int* arr{ new int[3]}; 
    int i = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        arr[i] = stoi(s.substr(0, pos));
        i++;
        s.erase(0, pos + delimiter.length());
    }

    return arr;
}