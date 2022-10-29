#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void Task1(), Task2(), Task3(), Task4(), Task5a(), Task5b();

int* strToTime(string s, string delimiter);

int main()
{
    system("cls"); 


    Task1();

    Task2();

    Task3();

    Task4();

    // [WARNING] взято из инета
    Task5a();

    Task5b();


    return 0;
}

// Запропонуйте користувачеві ввести число R — радіус круга. Обчисліть та виведіть на екран площу круга
void Task1(){
    cout << "#1" << endl;
    cout << "Radius: ";
    int num1 = 0;
    cin >> num1;

    cout << "S: " << 3.141 * pow(num1, 2) << endl;

    cout << "\n";
    system("pause");
    system("cls");
}


// Петро, Сергій і Катерина купляли канцелярські товари. Разом вони заплатили S грн. 
// Скільки оплатила кожна дитина, якщо відомо, що Петро і Сергій оплатили однакову 
// суму, а Катерина — вдвічі більшу (від Петра або Сергія)?
void Task2(){
    cout << "#2" << endl;
    
    int petroSpent = 0, sergiySpent = 0, katerinaSpent = 0;
    int Sum = 8;

    cout << "Sum: " << Sum << endl;

    petroSpent = Sum / 2 / 2;
    sergiySpent = petroSpent;
    katerinaSpent = Sum/2;

    cout << "Petr: " << petroSpent << endl <<
            "Serg: " << sergiySpent << endl <<
            "Katya: " << katerinaSpent << endl;

    cout << "\n";
    system("pause");
    system("cls");
}


// Дано значення двох моментів часу однієї доби: кількість годин, хвилин та секунд 
// кожного із них. Відомо, що другий момент часу настав не раніше першого. Визначте 
// скільки секунд пройшло між двома моментами часу.
void Task3(){
    a:cout << "#3" << endl;

    cout << "The output should be similar to:" << endl << "hh:mm:ss" << endl;
    
    string sDate1 = "";
    cout << "Date 1: ";
    cin >>  sDate1;
    int* arrDate1 = strToTime(sDate1, ":");

    string sDate2 = "";
    cout << "Date 2: ";
    cin >>  sDate2;
    int* arrDate2 = strToTime(sDate2, ":");

    int seconds = 0;

    if((arrDate2[0] <= 23 && arrDate1[0] <= 23 && 
        arrDate2[1] <= 59 && arrDate1[1] <= 59 && 
        arrDate2[2] <= 59 && arrDate1[2] <= 59)&& 
       (arrDate2[0] >  00 && arrDate1[0] >  00 && 
        arrDate2[1] >  00 && arrDate1[1] >  00 && 
        arrDate2[2] >  00 && arrDate1[2] >  00)  )
    {
        if(arrDate2[0] > arrDate1[0] || 
          (arrDate2[0] == arrDate1[0] && arrDate2[1] > arrDate1[1]) || 
          (arrDate2[0] == arrDate1[0] && arrDate2[1] == arrDate1[1] && arrDate2[2] > arrDate1[2]))
        {
            seconds = (arrDate2[0] - arrDate1[0]) * 3600 + (arrDate2[1] - arrDate1[1]) * 60 + (arrDate2[2] - arrDate1[2]);
        }
    }
    else
    {
        cout << "Error!" << endl;
        system("pause");
        system("cls");
        goto a;
    }

    

    cout << "Seconds: " << seconds << endl;

    cout << "\n";
    system("pause");
    system("cls");

}


// Дано додатне тризначне число N. Знайдіть кількість парних цифр числа.
void Task4(){
    cout << "#4" << endl;

    string num4 = "";
    cout << "Enter number: ";
    cin >> num4;
    int count = 0;
    for(int i = 0; i < num4.length(); i++){
        if( num4[i] % 2 == 0){
            count++;
        }
    }
    cout << "Count: " << count << endl;

    cout << "\n";
    system("pause");
    system("cls");
}


// Напишіть програму для обчислення наступних виразів за формулою: 
// a) 𝐹 = Ax^3 + Bx^2 + Cx + D 
// b) F = tg(a) − |b − 3a + (2 / 3√a+4) 
void Task5a(){
    const double PI = 3.1415926535897932384626433832795;
    double a5,b5,c5,d,p,q,s,f,x1,x2,x3,x2i,x3i;

    cout << "#5a" << endl;

    m:cout << "Enter the coefficients of the cubic equation Ax^3+Bx^2+Cx+D" << endl;
    cout << "A= ";
    cin >> a5;

    cout << "B= ";
    cin >> b5;
    
    cout << "C= ";
    cin >> c5;

    cout << "D= ";
    cin >> d;

    if (a5==0)
    {
        cout << "Error!" << endl;
        goto m;
    }
    else
    {
        p=((3.*a5*c5-b5*b5)/(3.*a5*a5));
        q=((2.*b5*b5-9.*a5*b5*c5+27.*a5*a5*d));
        s=(((q*q)/4.)+(p*p*p)/27.);
        if (q < 0)
        {
            f=(atan(pow(-s,0.5)/(-q/2)));
        }
        else if (q > 0)
        {
            f=(atan(pow(-s,0.5)/(-q/2))+PI);
        }
        else
        {
            f=(PI/2);
        }
        if (s < 0)
        {
            x1=(2.*pow((-p/3.),0.5)*cos(f/3.)-b5/3.*a5);
            x2=(2.*pow((-p/3.),0.5)*cos(f/3.+(2.*PI)/3.)-b5/3.*a5);
            x3=(2.*pow((-p/3.),0.5)*cos(f/3.+(2.*PI)/3.)-b5/3.*a5);
        }
        else if (s > 0)
        {
        x1=(pow(-q/2.+pow(s,0.5),1./3.)+pow(-q/2.-(pow(s,0.5)),1./3.)-b5/(3.*a5));
            x2=(-0.5*(pow(-q/2.+pow(s,0.5),1./3.)+pow(-q/2.-(pow(s,0.5)),1./3.)-b5/(3.*a5)));
            x2i=((pow(3.,0.5)/2.)*(pow(-q/2.+(pow(s,0.5)),1./3.)-pow(-q/2.-(pow(s,0.5)),1./3.)));
            x3=(-0.5*(pow(-q/2+pow(s,0.5),1/3)+pow(-q/2-(pow(s,0.5)),1/3)-b5/(3*a5)));
            x3i=((pow(3.,0.5)/2.)*(pow(-q/2.+(pow(s,0.5)),1./3.)-pow(-q/2.-(pow(s,0.5)),1./3.)));
        }
        else
        {
            x1=(2.*pow(-q/2.,1./3.)-b5/(3.*a5));
            x2=(-1.*pow(-q/2.,1./3.)-b5/(3.*a5));
            x3=(-1.*pow(-q/2.,1./3.)-b5/(3.*a5));
        }
        cout << "Х1= " << x1 << endl;
        if (s > 0)
        {
            cout << "X2= " << x2 << "+" << x2i << "i" << endl;
            cout << "X3= " << x3 << "-" << x3i << "i" << endl;
        }
        else
        {
        cout << "X2= " << x2 << endl;
        cout << "X3= " << x3 << endl;
        }
    }
    cout << "\n";
    system("pause");
    system("cls");
}

void Task5b(){
    cout << "#5b" << endl;

    double a = 0 , b = 0, c = 0;
    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter c: ";
    cin >> c;


    cout << "F = " << tan(a) - abs(b - 3 * a + 2 / cbrt(a + 4));

    cout << "\n";
    system("pause");
    system("cls");
}



int* strToTime(string s, string delimiter){
    
    int* arr{ new int[3]}; 
    int i = 0;
    
    auto start = 0U;
    auto end = s.find(delimiter);
    while (end != string::npos)
    {
        arr[i] = stoi(s.substr(start, end - start));
        i++;
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }

    arr[i] = stoi(s.substr(start, end));

    return arr;
}