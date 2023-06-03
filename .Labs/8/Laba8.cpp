#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

//lib https://github.com/nlohmann/json
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

void Task1();
inline bool fileExists (const string& name);
void Task2();

int main() {

    system("cls");

    // Карманний М
    // Вариант 12

    cout << "---Task1---" << endl;

    Task1();

    cout << "\n";
    system("pause");
    system("cls");

    cout << "---Task2---" << endl;

    Task2();

    cout << "\n";
    system("pause");
    system("cls");


    cout << "\nEnd\n";
    system("pause");
    return 0;
}


// У початковому текстовому файлі "In.txt" визначити кількість символів, які не є пробілом (знак
// кінця рядка не враховувати!). Результат записати в текстовий файл "Out.txt". Якщо початкового
// файлу не існує, то записати в результатуючий файл повідомлення про помилку.
void Task1(){

    string text = "";

    if(!fileExists("In.txt")){
        cout << "File is missing" << endl;
        string answer;
        cout << "Create file? (y/n) "; 
        cin >> answer;

        if(answer != "y"){ return;}

        ofstream autoFile ("In.txt");

        autoFile << "I love mama \n and papa";
        autoFile.close();
    }

    ifstream file ("In.txt");
    
    int counter = 0;
    while ( getline (file, text) )
    {
        for (int i = 0; i < text.length(); i++)
        {
            if(text[i] != ' ' && text[i] != '\n'){
                counter++;
            }
        }
        
    }
    file.close();


    ofstream outfile ("Out.txt");

    outfile << counter;

    outfile.close();

    cout << "Done!\nCheck files" << endl;
}
inline bool fileExists (const string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}



// Список співробітників підприємства:
// табельний номер, прізвище, посада, дата
// народження, дата прийому на роботу

// Вивести відомості про співробітників,
// які пропрацювали понад
// десять років на підприємстві
void Task2(){
    ifstream file("employees.json");
    json employeesJSON = json::parse(file);

    auto t = time(nullptr);
    auto dateNow = *localtime(&t);


    for (const auto& employee : employeesJSON) {
        string hireDateStr = employee["HireDate"];
        istringstream iss(hireDateStr);
        tm dateHire = {};
        iss >> get_time(&dateHire, "%d.%m.%Y");

        int yearsDiff = dateNow.tm_year - dateHire.tm_year;


        if (yearsDiff > 10) {
            cout << "Lastname: " << employee["LastName"].get<string>() << endl;
            cout << "Position: " << employee["Position"].get<string>() << endl;
            cout << "Date of birth: " << employee["DateOfBirth"].get<string>() << endl;
            cout << "Hire time: " << yearsDiff << endl;
            cout << "\n";
        }
    }

}