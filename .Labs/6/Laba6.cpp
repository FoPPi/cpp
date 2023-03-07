#include <iostream>
#include <string>
#include <cstring>
#include <regex>

using namespace std;

void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();

int main() {
    Task1();

    Task2();

    Task3();

    Task4();

    Task5();

    Task6();
}

void Task1(){
    // Запропонуйте користувачеві ввести рядок із клавіатури, а також символ X.
    // Дізнайтеся, скільки разів введений символ X зустрічається у рядку

    cout << "Enter a text: ";
    string text = "";
    getline(cin, text);
    cout << "Enter a letter to find in text: ";
    string find = "";
    getline(cin, find);

    int count = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if(text[i] == find[0]){
            count++;
        }
    }

    cout << count << endl;
    
}

void Task2(){
    // Запропонуйте користувачеві ввести рядок із клавіатури (не менше двох слів) та
    // виведіть на екран тільки перше слово (тобто текст до першого пробіла). 

    string text;
    getline(cin, text);

    if(text.find(" ") != string::npos){
        string firstWord = text.substr(0, text.find(' '));

        cout << firstWord << endl;
    }
    else{
        cout << "NOU SPACESS!!" << endl;
    }
}

void Task3(){
    // Запропонуйте користувачеві ввести рядок із клавіатури (не менше двох слів).
    // Модифікуйте рядок таким чином, щоб кожне окреме слово починалося із великої
    // літери.

    string text;
    cout << "Enter text: ";
    getline(cin, text); // зчитування рядка з пробілами

    // замінюємо першу літеру кожного слова на велику
    for (int i = 0; i < text.length(); i++) {
        if (i == 0 || text[i - 1] == ' ') {
            text[i] = toupper(text[i]);
        }
    }

    cout << "Changed text: " << text << endl;
}

void Task4(){
    // Задано два символьних масиви str1 та str2. Знайдіть перший символ рядка 1, який
    // не входить в рядок 2

    char str1[100], str2[100];
    bool found = false;
    
    cout << "Enter string 1: ";
    cin.getline(str1, 100);
    
    cout << "Enter string 2: ";
    cin.getline(str2, 100);
    
    for (int i = 0; i < strlen(str1); i++) {
        if (strchr(str2, str1[i]) == NULL) {
            cout << "First character in string 1 that is not in string 2 is: " << str1[i] << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "All characters in string 1 are in string 2." << endl;
    }
}

void Task5(){
    string text;
    getline(cin,text);

    text.insert(text.length(), " " + text.substr(0, text.find(' ')));
    text.replace(0, text.find(' ') + 1, "");
    
    cout << text;
}

void Task6(){
    string password;
    getline(cin, password);

    std::regex lower("[a-z]");
    std::regex upper("[A-Z]");
    std::regex special("[!#$%&()*+]");
    std::regex digit("[0-9]");
    std::regex length(".{8,}");

    int count = 0;
    if (std::regex_search(password, lower)) count++;
    if (std::regex_search(password, upper)) count++;
    if (std::regex_search(password, special)) count++;
    if (std::regex_search(password, digit)) count++;
    if (std::regex_search(password, length)) count++;

  cout << "Your password strength score is: " << count << endl;

}
