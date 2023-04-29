#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<string>
#include<regex>
using namespace std;
double check(char);
int main() {
	char type;
	double t,a,c,x,y,z;
	x = check('x');
	do {
		y = check('y');
		z = check('z');
		a = 0.5 + pow(sin(y), 2);
		c = 3 - pow(z, 2) / 5;
	} while (a == 0 || c == 0);
	t = ((2 * cos(x - M_PI / 6))/a)*(1+(pow(z,2)/c));
		cout <<"The meaning of t: "<< t << endl;
	return 0;
}
double check(char type) {
	string foo;
	regex b("^[-]?[0-9]+[.]?[0-9]*$");
	regex b1("^[-]?[0-9]+[.]{1}$");
	do {
		cout << "Enter the meaning of " << type << " in radians\n";
		getline(cin, foo);
	} while (!regex_match(foo,b) || regex_match(foo,b1));
	return stod(foo);
}