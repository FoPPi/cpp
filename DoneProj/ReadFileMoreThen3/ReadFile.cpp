#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;


string TakeAllWordsMoreThen3(string Path);

int main()
{
    system("cls");

    //Извлечь из текстового файла f все строки, длина которых меньше 3. Результат записать в файл g.
    string Path = "example.txt";
    cout << TakeAllWordsMoreThen3(Path);

    cout << "\n";
    system("pause");
    return 0;
}


string TakeAllWordsMoreThen3(string Path)
{

    string text = "";
    ifstream file (Path);

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