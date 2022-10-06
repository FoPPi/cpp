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
    string Path = "example.txt"; // задаём путь файла
    cout << TakeAllWordsMoreThen3(Path);

    cout << "\n";
    system("pause");
    return 0;
}


string TakeAllWordsMoreThen3(string Path)
{

    string text = "";
    ifstream file (Path);

    list<string> Words; // создаём листу
    string delimiter = " "; // ставим то по чём будем сплитовать
    while ( getline (file, text) ) // читаем строку и записываем её в стрингу
    {
        size_t pos = 0;
        string token;
        while ((pos = text.find(delimiter)) != string::npos) // npos is a static member constant value with the greatest possible value for an element of type size_t.
        {
            token = text.substr(0, pos); // обрезаем стрингу до слова
            
            if(token.length() > 3) // если длина слова больше 3
                Words.push_back(token); // то добавляем её в листу

            text.erase(0, pos + delimiter.length()); // убираем слово с delimiter
        }
        if(text.length() > 3) // проверка последнего слова
                Words.push_back(text);
    }
    file.close(); // закрываем файл

    string edittext= "";

    for (string word : Words) // запихиваем все элементы листы в стрингу 
    {
        edittext += word + " ";
    }
    

    return edittext;

}