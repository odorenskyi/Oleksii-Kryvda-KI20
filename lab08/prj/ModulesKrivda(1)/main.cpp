#include <iostream>
#include <math.h>

using namespace std;

float s_calculation(float x, float y, float z){

	float S, PI = 3.14, e = 2.71828;

	S = (sqrt(abs(pow(z, 2) * 0.5 * y))) + ((PI * x + pow(e, abs(y))) / y);

	return S;
}
