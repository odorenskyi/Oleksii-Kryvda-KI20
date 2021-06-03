#include "ModulesKrivda.h"
#include <iostream>
#include <math.h>
#include <string>
#include <clocale>
#include <stdlib.h>

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
//Alonzomerにごきょりょくいただきありがとうごdざいます
