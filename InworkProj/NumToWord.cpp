#include <iostream>
#include <string>

using namespace std;


string convertNumberToWord(long number);
bool isNumber(const string& str);

int main()
{
    system("cls"); //system("cls");


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
            cout << convertNumberToWord(stoi(text)) << endl;
        }
        else
        {
            cout << "Pls enter number" << endl;
        }

        cin.ignore().get(); //system("pause");
        system("cls"); //system("cls");
    }

    cout << "\n";
    cin.ignore().get(); //system("pause");
    system("cls"); //system("cls");

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

// Вам нужно использовать функцию для преобразования числа в строку. Затем, Вы 
// можете разбить число на отдельные цифры и использовать соответствующие слова 
// для каждой цифры. Вы можете создать массив строк, где каждый элемент массива
// соответствует соответствующей цифре, и использовать его для получения слова для
// каждой цифры. Также Вам необходимо реализовать логику для обработки сотен, тысяч 
// и миллионов.

string convertNumberToWord(long number) {
    string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string teens[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    string result = "";
    


    return result;
}