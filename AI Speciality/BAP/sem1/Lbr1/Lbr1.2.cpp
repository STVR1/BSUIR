#include<iostream>
#include<cmath>
#include<string>
#include<regex>
using namespace std;
int main() {
	double c, y, z1, z2;
	string a;
	regex b("^[-]?[0-9]+[.]?[0-9]*$");
	regex b1("^[-]?[0-9]+[.]{1}$");
	do {
		do {
			cout << "Enter the meaning of alpha in radians\n";
			getline(cin, a);
		} while (!regex_match(a, b) || regex_match(a, b1));
		c = stod(a);
		y = cos(c) + 1 - 2 * pow(sin(2 * c), 2);
	} while (y == 0);
	z1 = (sin(2 * c) + sin(5 * c) - sin(3 * c)) / y;
	z2 = 2 * sin(c);
	cout << "z1: " << z1 << endl;
	cout << "z1: " << z2 << endl;
	return 0;
}