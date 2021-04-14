#include <iostream>
#include <ModulesKrivda.h>
#include <windows.h>
#include <locale.h>
#include <stdio.h>

using namespace std;

int main()
{
    cout << "Krivda Oleksiy. CNTU 2021. (c)" << endl;
    setlocale(LC_ALL, "Ukr");

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
    cout << "У десятковiй системi x  = " << dec << x << endl;
    cout << "У шiстнадцятковiй  системi x = " << hex << x << endl;
    cout << "У десятковiй системi y = " << dec << y << endl;
    cout << "У шiстнадцятковiй  системi y= " << hex << y << endl;
    cout << "У десятковiй системi z = " << dec << z << endl;
    cout << "У шiстнадцятковiй  системi z = " << hex << z << endl;
    S = s_calculation(x, y, z);
    cout << "\n S = " << s_calculation(x, y, z) << endl;
    system("pause");
    return 0;
}
