#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;


string ReadFile();

int main()
{
    system("cls");

    cout << ReadFile();

    cout << "\n";
    system("pause");
    return 0;
}

string ReadFile()
{

    string text = "";
    ifstream file ("example.txt");

    list<string> Words;
    string delimiter = " ";
    while ( getline (file, text) )
    {
        size_t pos = 0;
        string token;
        while ((pos = text.find(delimiter)) != string::npos)
        {
            token = text.substr(0, pos);
            
            if(token.length() > 3)
                Words.push_back(token);

            text.erase(0, pos + delimiter.length());
        }
        if(text.length() > 3)
                Words.push_back(text);
    }
    file.close();

    string edittext= "";

    for (string word : Words)
    {
        edittext += word + " ";
    }
    

    return edittext;

}