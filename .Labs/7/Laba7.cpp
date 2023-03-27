#include <iostream>
#include <string>

using namespace std;

struct Country{
    string name;
    string capital;
    double square_territory;
    int number_population;
    double GDP;
};

struct Countries{
    Country countryArr[100];
    int count;
};

Country InputCountry(){

    Country country;
    string line;

    cout << "Country" << endl;

    cout << "Name:";
    getline(cin,country.name);

    cout << "Capital:";
    getline(cin,country.capital);

    cout << "Square territory:";
    getline(cin,line);
    country.square_territory = stof(line);

    cout << "Number population:";
    getline(cin,line);
    country.number_population = stoi(line);

    cout << "GDP:";
    getline(cin,line);
    country.GDP = stod(line);

    return country;
}

Countries InputCountries(){

    Countries countries;

    string line;
    cout << "Count of countries:";
    getline(cin,line);
    countries.count = stoi(line);

    //countries.countryArr[countries.count];
    for (int i = 0; i < countries.count; i++)
    {
        countries.countryArr[i] = InputCountry();
    }

    return countries;
}

void OutputCountry(Country country){
    cout << "Name:" << country.name << endl;
    cout << "Capital:" << country.capital << endl;
    cout << "Square territory:" << country.square_territory << endl;
    cout << "Number population:" << country.number_population << endl;
    cout << "GDP:" << country.GDP << endl;
    cout << endl;
}

void Task1(int minGDP, Countries countries){
    
    for (auto countriy : countries.countryArr)
    {
        if (countriy.GDP >= minGDP)
        {
            OutputCountry(countriy);
        }
        
    }
    
}

void Task2(Countries countries){
    double AVG = 0;
    for (auto countriy : countries.countryArr)
    {
        AVG += countriy.square_territory;
    }
    AVG /= countries.count;

    cout << "AVG: " << AVG << endl;
    cout << endl;

    for (auto countriy : countries.countryArr)
    {
        if (countriy.square_territory < AVG)
        {
            cout << countriy.name << endl;
            cout << countriy.capital << endl;
            cout << endl;
        }
    }
}

int main() {
    
    //можно юзать это, но мне лень вводить каждый раз
    //Countries countries = InputCountries();

    Countries countries;
    countries.count = 5;
    countries.countryArr[0] = {"Ukraine", "Kyiv", 603.7, 42'434'000, 150.4};
    countries.countryArr[1] = {"United States", "Washington D.C.", 9'147, 328'915'700, 21'439.5};
    countries.countryArr[2] = {"Germany", "Berlin", 357.4, 83'149'300, 4'327.1};
    countries.countryArr[3] = {"Japan", "Tokyo", 377.9, 126'529'100, 5'152.6};
    countries.countryArr[4] = {"Australia", "Canberra", 7'692, 24'992'400, 1'379.2};

    // int min = 0;
    // cin >> min;
    // Task1(min, countries);
    cout << "Task1" << endl;
    Task1(5000, countries);

    // у меня тут в конце происходит спам толи \n толи пробелами, но факт в том что я хз почему так 
    cout << "Task2" << endl;
    Task2(countries);

    return 0;
}
