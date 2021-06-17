#include <iostream>
#include <fstream>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include <codecvt>
#include <ctime>
#include <bitset>
#include <cmath>
#include <locale>
#include "ModulesKrivda.h"

using namespace std;

int checkXYZ(int num){
    wcout << L": ";

    if(!(wcin >> num)){
        wcin.clear();
        while (wcin.get() != '\n');
        wcout << L"Ви ввели символ, введіть число." << endl;
        checkXYZ(num);
    }
    return num;
}

int main()
{
    setlocale(LC_ALL,"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    ifstream inputFile;
    wifstream inFILE;
    wofstream inputFileWrite;
    wchar_t inputName[100] = L"";
    char outputName[] = "output.txt";
    wchar_t Key[2] = L"";
    wchar_t D[2] = L"D";
    wchar_t F[2] = L"F";
    int vowelNum = 0;
    char inputWord[50];
    wcout << L"Даний застосунок виконує операцiї над файлами, використовуючи функцiї:      " << endl;
    wcout << L" * Пошук слова та кількість символів у файлі - Z" << endl;
    wcout << L" * Кількість цифр у файлі та час дозапису інформації - X" << endl;
    wcout << L" * Результат s_calculation та число b у двійковому коді - C " << endl;
    wcout << L" * Вихід з програми - E" << endl;
    wcout << L"Введiть назву та розширення вхiдного файлу(Ви створюєте вхiдний файл самостiйно через файловий менеджер у тецi з програмою): ";
    wcin.getline(inputName, 50);

    char ch_inputName[50] = "";
    wcstombs(ch_inputName, inputName, sizeof(ch_inputName));

    while(true){
        if(access(ch_inputName, 0) != -1){


            break;
        }
        else{
            wcout << L"Файл не знайдено. Можливе невiрно введенне iм'я або вiдсутнiсть файлу у тецi програми." << endl;
            wcin.getline(inputName, 50);
            wcstombs(ch_inputName, inputName, sizeof(ch_inputName));
        }
    }
    wcout << L"Введiть до файлу (через блокнот) слово, пiсля введення напишiть в консоль ключ \"D\"(отримання доступу до функцiй): ";
    wcin.getline(Key, 2);



    while(!wcsstr(D, Key) && !wcsstr(F, Key)){
        wcout << L"Ви ввели невiрний ключ, спробуйте ще раз: ";
        wcin >> Key;
    }
    if(wcsstr(F, Key)){
        wcout << L"Застосунок завершиться пiсля натиснення Enter" << endl;
        system("pause");
        return 0;
    } else if(wcsstr(D, Key)){
        wcout << L"Ключi для виклику функцiй: " << endl;
        wcout << L" * Пошук слова та кількість символів у файлі - Z" << endl;
        wcout << L" * Кількість цифр у файлі та час дозапису інформації - X" << endl;
        wcout << L" * Результат s_calculation та число b у двійковому коді - C " << endl;
        wcout << L" * Вихід з програми - E" << endl;


        while(true){
            wchar_t fKey;
            float S = 0;
            wcout << L"Введiть ключ для: ";
            wcin >> fKey;

            if(fKey == 'E')
                return 0;

            switch(fKey)
            {
                case 'Z':
                 f_searchword(ch_inputName, outputName, &vowelNum);
                 first_funct();
                 wcout << L"Введiть назву вхідного файлу з розширенням txt ";
                    wcout << L"Робота с файлами була завершена, результати виконання f_searchword можна побачити у вихiдному файлi." << endl;
                    break;
                case 'X':
                    second_funct();

                    wcout << L"Робота с файлами була завершена, результати виконання second_funct можна побачити у вихiдному файлi." << endl;
                    break;
                case 'C':
                    f_resofscalc(outputName);
                    wcout << L"Робота с файлами була завершена, результати виконання f_resofscalc можна побачити у вихiдному файлi." << endl;
                    break;
                default:
                    wcout << L"Невiрно введений ключ" << endl;
                    break;


            }
        }
    }

    return 0;
}
