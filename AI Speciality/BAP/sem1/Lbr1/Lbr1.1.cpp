#include<iostream>
#include<cmath>
#include<string>
#include<regex>
using namespace std;
int main()
{
	double z1, z2;
	const double PI = 3.145926;
	string a;
	regex b("^[-]?[0-9]+[.]?[0-9]?$");
	regex b1("^[-]?[0-9]+[.]{1}$");
	cout << "Enter the meaning in radians\n";
	getline(cin, a);
	while (!regex_match(a, b) || regex_match(a,b1)) {
		cout << "Error! Enter the meaning again!!!\n";
		getline(cin, a);
	}
	double c = stod(a);
	z1 = 2 * pow(sin(3 * PI - 2 * c), 2) * pow(cos(5 * PI + 2 * c), 2);
	z2 = 1. / 4 - 1. / 4 * sin(5. / 2 * PI - 8 * c);
	cout << "Result of z1: " << z1 << endl;
	cout << "Result of z2: " << z2 << endl;
	return 0;
}