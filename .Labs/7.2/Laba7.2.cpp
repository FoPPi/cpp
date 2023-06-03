#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <time.h>

using namespace std;

int rnd(int min, int max);
void Task1(int arr[], int arrSize, int& min, int& max);
void Task2(int arr[], int arrSize, int& countUnique);
void Task3(int num, int& countEven, int& countOdd);
void Task4(string& text);
int Task5(int num, int maxDigit = 0);
void Task6(string& text);

int main() {

    srand(time(NULL));

    int arrSize = 6;

    int* arr{ new int[arrSize]};

    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = rnd(0,9);
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    int min, max = -1;
    Task1(arr, arrSize, min, max);
    cout << "Min: " << min << " | " << "Max: " << max << endl;

    int countUnique = -1;
    Task2(arr, arrSize, countUnique);
    cout << "Count of unique nums: " << countUnique << endl;

    

    string text =  "Test of I lOvE u";
    Task4(text);
    cout << text << endl;


    return 0;
}

int rnd(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Описати функцію, яка знаходить найбільше та найменше число у масиві.
// Функція повинна використовувати параметри за посиланням для повернення
// результатів.
void Task1(int arr[], int arrSize, int& min, int& max){
    min = max = arr[0];
    for(int i = 1; i < arrSize; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if (arr[i] < min){
            min = arr[i];
        }
    }
}

// Описати функцію, яка підраховує кількість унікальних елементів у масиві.
void Task2(int arr[], int arrSize, int& countUnique){
    countUnique = 0;
    for (int i = 0; i < arrSize; i++) {
        bool unique = true;
        for (int j = 0; j < arrSize; j++)
        {
            if (arr[i] == arr[j] && i != j) {
                unique = false;
                break;
            }
        }
        if(unique){
            countUnique++;
        }
    }
}

// Описати функцію, яка використовує статичну змінну для підрахунку кількості
// парних та непарних чисел, переданих їй протягом всіх викликів та,
// використовувати параметри за посиланням, повертає кількість парних і
// непарних чисел, які було передано у функції за час усіх викликів

void Task3(int num, int& countEven, int& countOdd){
    static int s_countEven, s_countOdd = 0;

    if (num % 2 == 0) {
        s_countEven++;
        countEven = s_countEven;
    } else {
        s_countOdd++;
        countOdd = s_countOdd;
    }
}

// Описати функцію, яка приймає рядок та замінює всі голосні літери на наступну
// голосну літеру в алфавіті

string to_lower(const string& s)
{
    string result(s);
    transform(s.begin(), s.end(), result.begin(), [](unsigned char c) { return tolower(c); });
    return result;
}

void Task4(string& text){
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    string loverText = to_lower(text);

    for (int i = 0; i < 5; i++)
    {
        if(loverText.find(vowels[i]) && vowels[i] != 'u'){
            for (int j = 0; j < loverText.length(); j++)
            {
                if(loverText[j] == vowels[i]){
                    if(loverText[j] != text[j]){
                        text.replace(j, 1, 1, toupper(vowels[i+1]));
                    }
                    else{
                        text.replace(j, 1, 1, vowels[i+1]);
                    }
                }
            }
            
        }
    }
}


// Описати рекурсивну функцію для пошуку максимальної цифри у десятковому
// записі числа.

int Task5(int num, int maxDigit = 0){
    if (num == 0) {
        return maxDigit;
    }
    int digit = num % 10;
    if (digit > maxDigit) {
        maxDigit = digit;
    }
    return Task5(num / 10, maxDigit);
}

// Описати рекурсивну функцію для реверсу кожного слова у рядку.
// Наприклад, “this is test string” → відповідь “siht si tset gnirts”

void Task6(string& text){
    int start = 0;
    for (int end = 0; end < text.length(); end++) {
        if (text[end] == ' ') {
            reverse(text.begin() + start, text.begin() + end);
            start = end + 1;
        }
    }
    reverse(text.begin() + start, text.end());
}