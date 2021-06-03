#include <iostream>
#include "ModulesKrivda.h"
#include <windows.h>

using namespace std;

int main()
{
    cout << "Krivda Oleksiy. CNTU 2021. (c)" << endl;
    int length = 0;
    char awtd;
    setlocale(LC_ALL, "Ukr");
    while(1){
        cout<<"Застосунок для виконання функцiї s_calculation та функцiй для виконання задач 9.1, 9.2 та 9.3\n"
            <<"Для виклику s_calculation введiть \'e\'\n"
            <<"Для виклику функцiї задачi 9.1 введiть \'r\'\n"
            <<"Для виклику функцiї задачi 9.2 введiть \'f\'\n"
            <<"Для виклику функцiї задачi 9.3 введiть \'t\'\n"
            <<"Для виходу з програми введiть \'g\', \'G\' або \'o\'\n"
            <<">>";
        cin>>awtd;
        switch(awtd){
            case 'e':{
                int x, y, z;
                float S;
                char a, b;
                int result;
                cout << "Введiть значення x: ";
                cin >> x;
                cout << "Введiть значення z: ";
                cin >> z;
                do {
                    cout << "Введiть значення y: ";
                    cin >> y;
                    if (y==0){
                        cout << "y не повинен дорiвнювати нулю.";
                    }
                } while(y==0);
                cout << "Введiть значення a: ";
                cin >> a;
                cout << "Введiть значення b: ";
                cin >> b;
                cout << "a + 5 >= b: " << boolalpha << (a + 5 >= b) << endl;
                cout << "Результат роботи s_calculation: " << s_calculation(x, y, z) << endl;
                break;
            }
            case 'r':{
                int money, years, perc, rlsal;
                cout << "Уведiть заробiтню плату: ";
                cin >> money;
                cout << "Уведiть стаж роботи: ";
                cin >> years;
                do{
                    if(money < 0){
                        cout << "Некоректно введене значення, заробiтня плата не може бути вiд'ємною" << endl;
                        cout << "Уведiть заробiтню плату: ";
                        cin >> money;
                    }
                    if(years < 0){
                        cout << "Некоректно введене значення, стаж роботи не може бути вiд'ємним" << endl;
                        cout << "Уведiть стаж роботи: ";
                        cin >> years;
                    }
                }while((money < 0) || (years < 0));
                salary( &money, &years, &perc, &rlsal);
                cout<<"Розмiр надбавки: "<<perc<<"% Сума до виплати: "<<rlsal<<endl;
                break;
            }
            case 'f':{
                cout << "\nВведiть довжину обхвату голови у сантиметрах(53-62): ";
                cin >> length;
                do{
                    if(length < 53 || length > 62){
                        cout << "Некоректно введене значення, обхвату голови не може бути бiльшим за 62 та меншим за 53";
                        cout << "\nВведiть довжину обхвату голови у сантиметрах(53-62): ";
                        cin >> length;
                    }
                }while (length < 53 || length > 62);
                std::string s = std::to_string(length);
                cout << "\nРозмiр шолому = " << Helmetsize(s) << endl << endl;
                break;
            }
            case 't':{
                    int n = 0;
                    cout << "\nВведiть цiле число вiд 0 до 40008050: ";
                    cin >> n;
                do{
                    if(n < 0 || n > 40008050){
                        cout << "Некоректно введенi данi, N має бути не бiльше нiж 40008050 та меншим нiж 0" << endl;
                        cout << "\nВведiть цiле число вiд 0 до 40008050: ";
                        cin >> n;
                    }
                }while (n < 0 || n > 40008050);
                if((n>>15)&1){
                    cout << "Кiлькiсть двiйкових нулiв = " << BinD15(n) << endl << endl;
                }else{
                    cout << "Кiлькiсть двiйкових одиниць = " << BinD15(n) << endl << endl;
                }
                break;
            }
   case 'g':{
                system("pause");
                exit(0);
            }
            case 'G':{
                system("pause");
                exit(0);
            }
            case 'o':{
                system("pause");
                exit(0);
            }
            default:{
                cout<<"\aНевiрне значення!"<<endl;
            }
        }
        cout<<endl;
    }
}

