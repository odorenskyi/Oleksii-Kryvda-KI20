#include <iostream>
#include <cmath>
#include "ModulesKrivda.h"
#include <stdio.h>

using namespace std;

int main()
{
    float x[10] = {1, 6, 3, 2, 123, 25, 5, 32, 8, 54};
    float y[10] = {4, 2, 8, 9, 4, 32, 6, 66 ,12, 7};
    float z[10] = {3, 9, 5, 12, 34, 4, 1, 13, 10, 4};
	float PI = 3.14, e = 2.71828;
	float res = 0;
    for(int i = 0; i < 10; i++){
        res = (sqrt(abs(pow(z[i], 2) * 0.5 * y[i]))) + ((PI * x[i] + pow(e, abs(y[i]))) / y[i]);
        if(s_calculation(x[i], y[i], z[i]) == res){
            cout << "Test case#" << i+1 << " passed  " <<  endl;
        }
        else{
            cout << "Test case#" << i+1 << " failed  " << res << endl;
        }
    }
    getchar();
    return 0;
}
