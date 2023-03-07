#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "This is  a     string   with   multiple     spaces.";

    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == ' ' && str[i] == str[i + 1])
        {
            str.erase(i+1,1);
            i--;
        }
    }
    cout << str << endl;

    return 0;
}
