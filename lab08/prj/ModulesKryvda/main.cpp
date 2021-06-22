#include "ModulesKrivda.h"
#include <iostream>
#include <math.h>
#include <string>
#include <clocale>
#include <stdlib.h>
#include <fstream>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <clocale>
#include <cstdlib>
#include <sstream>
#include <codecvt>
#include <ctime>
#include <bitset>
#include <cmath>

using namespace std;

float s_calculation(float x, float y, float z){

	float S, PI = 3.14, e = 2.71828;

	S = (sqrt(abs(pow(z, 2) * 0.5 * y))) + ((PI * x + pow(e, abs(y))) / y);

	return S;
}

void salary(int *money, int *years, int *perc, int *rlsal){
    if(((*years)>=2)&&((*years)<=5)){
        (*perc)=5;
    }else if(((*years)>=5)&&((*years)<=10)){
        (*perc)=10;
    }else if((*years)>10){
        (*perc)=25;
    }
    (*rlsal)= (*money) + (((*money) * (*perc)) / 100);
}


std::string  Helmetsize(std::string length){
    std::string sizesh;
    int d = atoi(length.c_str());
    if (d == 53 || d == 54){
        sizesh = "XS";
        return sizesh;
    }
    if (d == 55 || d == 56){
        sizesh = "S";
        return sizesh;
    }
    if (d == 57 || d == 58){
        sizesh = "M";
        return sizesh;
    }
    if (d == 59 || d == 60){
        sizesh = "L";
        return sizesh;
    }
    if (d == 61 || d == 62){
        sizesh = "XL";
        return sizesh;
    }
    if(d > 62 || d < 53){
        sizesh = "E";
        return sizesh;
    }
}

int BinD15(int N){
    int result = 0;
    bool flag = false;
    for (int n=sizeof(int)*8-1; n>-1; n--)  {
        if((N>>n)&1)
            if(!flag) {
                flag = true;
            }
        if (flag){
            if((N>>15)&1){
                result += ((N>>n)&1)? 0 : 1;
            }else{
                result += ((N>>n)&1)? 1 : 0;
            }
        }
    }
    return result;
}

int input_symbol(char *exist_file)
{
    setlocale(LC_ALL,"Ukr");

    wifstream stream;
    wofstream output;
    wstring word;
    wifstream inputfile;
    wstring number;
    if (inputfile.good())
        {
        int number = 0;
        inputfile >> number;

        }



    stream.open(exist_file);
    if(stream.is_open())
    {
       stream.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
       getline(stream, number);
       stream.close();

       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << number << L"\nКількість символів у файлі: " << number.length();
       output.close();
    }
    else
    {
       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << number << L"\nКількість символів у файлі: " << number.length();
       output.close();
    }
    wcout << L"Файл був успiшно оброблений. Завершення виконання функцiї input_time." << endl;
    return 1;
}
int input_time(char *exist_file)
{
    setlocale(LC_ALL,"Ukr");

    wifstream stream;
    wofstream output;
    wstring word;
    wifstream inputfile;
    wstring number;
    if (inputfile.good())
        {
        int number = 0;
        inputfile >> number;

        }


    time_t cur_date = time(0);

    stream.open(exist_file);
    if(stream.is_open())
    {
       stream.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
       getline(stream, number);
       int i=0, count=0;
           string s;
           cout << "String:\n";
           getline(cin, s);

           while (number[i])
               {
               if (isdigit(number[i])) count++;
               i++;
               }



       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << count << L"\nКількість цифр у файлі: " << L"\nДата:" << ctime(&cur_date);
       output.close();
    }
    else
    {
       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << number << L"\nКількість цифр у файлі: " << number.length() << L"\nДата:" << ctime(&cur_date);
       output.close();
    }
    wcout << L"Файл був успiшно оброблений. Завершення виконання функцiї input_time." << endl;
    return 1;
}
void second_funct()
{
    setlocale(LC_ALL,"Ukr");
    wchar_t input_file[100];
    char conv[100];

    wcout << L"Введiть назву вхiдного файлу з розширенням .txt" << endl;
    wcin >> input_file;
    const wchar_t * flag = input_file;
    wcstombs(conv, flag, sizeof(conv));

    input_time(conv);
}
    double calculations_s(double x, double y, double z)
{
    double s = M_PI*x+pow(M_E,abs(y))-sqrt(abs(pow(z,2)-y)) ;
    return s;
}
int dec2bin(int num)
{
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}
int f_resofscalc(char *outputName, int x, int y, int z, float *S, int *binNum){
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wofstream outputFile;
    int bitSize = 0;

    outputFile.open(outputName, ios::app);
    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

    *binNum = dec2bin(*binNum);
    *S = calculations_s(x, y, z);

    outputFile << L"Результат виконання s_calculation: " << *S << endl
               << L"Число B у двійковій системі числення: " << *binNum;

    outputFile.close();

    return 0;
}

//int f_resofscalc(char *outputName){
//    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
//    _setmode(_fileno(stdout), _O_U8TEXT);
//    _setmode(_fileno(stdin), _O_U8TEXT);
//
//    wofstream outputFile;


//    outputFile.open(outputName, ios::app);
//    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
//    int x, y, z, b;
//    float S;
//    int result;
//   cout << "Введiть значення x: ";
//    cin >> x;
//    cout << "Введiть значення z: ";
//    cin >> z;
//    do {
//        cout << "Введiть значення y: ";
//        cin >> y;
//        if (y==0){
//                cout << "y не повинен дорiвнювати нулю.";
//        }
//    } while(y==0);
//    cout << "Введiть значення b: ";
//    cin >> b;

//        outputFile << L"Результат виконання s_calculation: " << s_calculation(x, y, z) << endl
//               << L"Число B у двійковій системі числення: " << bitset<32>(b);

//    outputFile.close();

//    return 0;
//}
void first_funct()
{
    setlocale(LC_ALL,"Ukr");
    wchar_t input_file[100];
    char conv[100],conv1[100], conv2[100];

    wcout << L"Введiть назву вхiдного файлу з розширенням .txt" << endl;
    wcin >> input_file;
    const wchar_t * flag = input_file;
    wcstombs(conv, flag, sizeof(conv));

    input_symbol(conv);

}
int f_searchword(char *inputName, char *outputName, int *vowelNum){

    setlocale(LC_ALL,"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
    wifstream inputFile;
    wofstream outputFile;
     wstring number;
     wifstream stream;
     wofstream output;
    wchar_t wstr[50] = L"";
    *vowelNum = 0;
    int vows = 0;
    wchar_t vowelSounds[] = L"АаЕеЄєиІіЇїУуЮюЯяОо";
    wchar_t words[250] = {L"Модуль,модульчик,студент,студентка,програміст,програмістка."};


    inputFile.open(inputName);
    inputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    inputFile.getline(wstr, 50);
    inputFile.close();

    for(int i = 0; i < wcslen(wstr); i++){
        for(int j = 0; j < wcslen(vowelSounds); j++)
            if(wstr[i] == vowelSounds[j]) vows++;
    }
    *vowelNum = vows;
    cout << "Krivda Oleksiy. CNTU 2021. (c)" << endl;

    outputFile.open(outputName);
    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    outputFile.clear();
    outputFile << L"Krivda Oleksiy. CNTU 2021. (c)" << endl;
    bool Marker = 0;
    int testRes = 0;
    if(wcsstr(words, wstr)){
           outputFile << L"Cлово " << wstr << L" присутнє в задачі." << endl;

           outputFile << number << L"\nКількість символів містяться в вхідному файлі ";

           testRes = 1;
       }
       else{
           outputFile << L"Cлово " << wstr << L" відсутнє в задачі" << endl;
           outputFile << number << L"\nКількість символів містяться в вхідному файлі ";
           testRes = 2;
       }

       outputFile.close();

       return testRes;
   }
//Alonzomerにごきょりょくいただきありがとうごdざいます
