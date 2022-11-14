#include <iostream>
#include <string>
#include <list>
#include <map>

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
    
    string text = "";

    list<int> listNums = spitnum(num);

    switch (listNums.size())
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
        case 0:
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


void mind(list<int> listNums){
    map<int, string> numbers0_9 {
                                 {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
                                 {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
                                 {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"},
                                };
    string numbers_hundred_billion[] = {"hundred", "thousand", "million", "billion"};


    
    for (auto num : listNums){
        int numLenght = to_string(num).length();

        if()

    }

}