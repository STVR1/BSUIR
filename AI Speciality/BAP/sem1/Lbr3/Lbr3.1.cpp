#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double a, h = 0.4, y, min= 2 * sin(-M_PI) / pow(1 - (-M_PI), 2), max= 2 * sin(M_PI) / pow(1 - (M_PI),2);
	int k = 1;
	cout << "Number" << "\t"  << "Meaning of a" << "\t"  << "Meaning of y" << endl;
	cout << "__________________________________" << endl;
	for (a=-M_PI, k; a < M_PI; a+=h,k++) {
		y = 2 * sin(a) / pow(1 - (a), 2);
		if (min > y) { min = y; }
		if (max < y) { max = y; }
		cout <<k<<"."<<"\t" << a << "\t" << y << endl;
	}
	cout << "__________________________________"<<endl;
	cout <<"Min:"<< min << endl;
	cout <<"Max:"<< max << endl;
	return 0;
}