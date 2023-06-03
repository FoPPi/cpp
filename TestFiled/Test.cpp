#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;


void Zadanie1()
{
    ofstream outFile("Out.txt");
    if (outFile) 
    {
        ifstream file("In.txt");
        if (!file) {
            return;
        }

        string line;
        int count = 0;
        while (getline(file, line)) {
            if (line.empty()) {
                count++;
            }
        }

        file.close();

        if (count > 0) 
        {
            outFile << "У початковому файлі " << count << " порожніх рядків" << endl;
        } else 
        {
            outFile << "У початковому файлі немає порожніх рядків" <<endl;
        }
        outFile.close();
    }
    else
    {
        cout << "Помилка запису до файлу " << endl;
    }
}

struct Medication
{
    string name;
    string expiration_date;
    double price;
};

void Zadanie2()
{
    vector<Medication> medications = 
    {
        {"Ліки 1", "30.05.2023", 10.5},
        {"Ліки 2", "15.06.2023", 15.75},
        {"Ліки 3", "31.12.2022", 8.99},
        {"Ліки 4", "10.04.2023", 12.0},
        {"Ліки 5", "01.06.2023", 9.5}
    };

    string dateStr = "";
    cout << "введіть дату у вигляді дд.мм.рррр: ";
    cin >> dateStr;
    int dayCur = stoi(dateStr.substr(0, 2));
    int monthCur = stoi(dateStr.substr(3, 2));
    int yearCur = stoi(dateStr.substr(6, 4));

    cout << "Медикаменти, термін придатності яких закінчується у поточному році:" << endl;
    for (const Medication& medication : medications) 
    {
        string expirationDate = medication.expiration_date;
        int year = stoi(expirationDate.substr(6, 4));

        if (year == yearCur) 
        {
            cout << "Назва ліків: " << medication.name << endl;
            cout << "Дата кінцевого терміну придатності: " << medication.expiration_date << endl;
            cout << "Ціна: " << medication.price << endl;
            cout << endl;
        }
    }

    cout << "Медикаменти, термін придатності яких закінчується в межах 30-ти днів:" << endl;
    for (const Medication& medication : medications) 
    {
        string expirationDate = medication.expiration_date;
        int day = stoi(expirationDate.substr(0, 2));
        int month = stoi(expirationDate.substr(3, 2));
        int year = stoi(expirationDate.substr(6, 4));

        if (year == yearCur && month == monthCur && day <= dayCur + 30) 
        {
            cout << "Назва ліків: " << medication.name << endl;
            cout << "Дата кінцевого терміну придатності: " << medication.expiration_date << endl;
            cout << "Ціна: " << medication.price << endl;
            cout << endl;
        }
    }

}

int main() 
{
    Zadanie1();

    Zadanie2();

    return 0;
}