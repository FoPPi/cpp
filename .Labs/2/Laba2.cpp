#include <iostream>
#include <string>
#include <list>
#include <math.h>

using namespace std;


list<string> spit(string s, string delimiter);

int main()
{
    system("cls"); 

    //-------------------
    // 1
    cout << "#1" << endl;

    string text1;

    cout << "Enter the numbers, separated by a space" << endl;
    cout << "Numbers: ";
    getline(cin, text1);

    list<string> nums1 = spit(text1, " ");

    int max = stoi(nums1.front());
    for(string val : nums1){
        if(stoi(val) > max){
            max = stoi(val);
        }
    }

    cout << "Max: " << max << endl; 

    cout << "\n";
    system("pause");
    system("cls");



    //-------------------
    // 2
    cout << "#2" << endl;

    string text2;

    cout << "Enter the numbers, separated by a space" << endl;
    cout << "Numbers: ";
    getline(cin, text2);

    list<string> nums2 = spit(text2, " ");

    nums2.sort();
    auto med = next(nums2.begin(), nums2.size() / 2);
    cout << "Medium: " << *med;

    cout << "\n";
    system("pause");
    system("cls");



    //-------------------
    // 3
    cout << "#3" << endl;

    int price = 0;
    cout << "Product price: ";
    cin >> price;

    int tax = 0;
    if(price > 0) {
        if(price < 1000)
            tax = price * 2 / 100;
        else if(price >= 1000 && price < 10000)
            tax = price * 3 / 100;
        else if (price >= 10000)
            tax = price * 5 / 100;
    }

    cout << "Tax: " << tax;

    cout << "\n";
    system("pause");
    system("cls");



    //-------------------
    // 4
    cout << "#4" << endl;

    int x = 0;
    cout << "Enter x: ";
    cin >> x;

    if(x > 0)
        cout << "y = " << 6 * x - 9;
    else if (x < 0)
        cout << "y = " << 2 * abs(x) - 1;
    else
        cout << "y = " << 0;

    cout << "\n";
    system("pause");
    system("cls");



    //-------------------
    // 5
    cout << "#5" << endl;

    int a = 0, b = 0, c = 0;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter c: ";
    cin >> c;

    if(a + b > c)
        cout << "true";
    else
        cout << "false";

    return 0;
}



list<string> spit(string s, string delimiter){
    
    list<string> words;
    
    auto start = 0U;
    auto end = s.find(delimiter);
    while (end != string::npos)
    {
        words.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }

    words.push_back(s.substr(start, end));

    return words;
}
