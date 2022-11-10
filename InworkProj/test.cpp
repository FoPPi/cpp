#include <iostream>
#include <string>
#include <list>
using namespace std;


string NumToText(long num);
bool isNumber(const string& str);
list<int> spitnum(long num);

int main()
{
    system("clear"); //system("cls");


    cout << "If u want exit write \"exit\" or \"e\"" << endl; 

    string text = "";
    while (true)
    {
        cout << "Number:";
        cin >> text;

        if(text == "stop" || text == "s" || text == "exit"  || text == "e") // чел хочет выйти
        {
            cout << "Bye" << endl;
            break;
        }
        else if (isNumber(text)) // если в тексте только цифры
        {
            cout << NumToText(stoi(text)) << endl;
        }
        else
        {
            cout << "Pls enter number" << endl;
        }

        cin.ignore().get(); //system("pause");
        system("clear"); //system("cls");
    }

    cout << "\n";
    cin.ignore().get(); //system("pause");
    system("clear"); //system("cls");

    return 0;
}

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}



// https://www.dcode.fr/writing-number-letters

string NumToText(long num){

    //73456 | seventy-three thousand four hundred fifty-six
    string numbers0_9[]   = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string numbers10_19[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string numbers20_90[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string numbers_hundred_billion[] = {"hundred", "thousand", "million", "billion"};
    string text = "";

    list<int> listNums = spitnum(num);

    switch (to_string(num).length() / 3)
    {
        case 4:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 1:
            /* code */
            break;
        default:
            /* code */
            break;
    }

    return text;
}


list<int> spitnum(long num){

    list<int> numsBy3;
    
    string str = to_string(num);

    int start = 0;
    for (int i = str.length() - 3; i >= 0; i-=3)
    {
        numsBy3.push_front(stoi(str.substr(i, 3)));
        start = i;
    }
    if(start != 0)
        numsBy3.push_front(stoi(str.substr(0, start)));



    return numsBy3;
}