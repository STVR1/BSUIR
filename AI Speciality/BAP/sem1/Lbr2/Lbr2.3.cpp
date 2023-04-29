#include<iostream>
#include<cmath>
#include<string>
#include<regex>
using namespace std;
double functionmax(double, double, double);
double functionmin(double, double);
double check(char);
int main() {
	char type;
	double x, y, z, m;
	do {
		x = check('x');
		y = check('y');
		z = check('z');
		m = functionmax(x, y, z) / functionmin(x, y) + 5;
	} while (functionmin(x, y) == 0);
	cout<<"Result: " << m << endl;
	return 0;
}
double functionmax(double x, double z, double y){
	if (x<z && y<z) {
		return z;
	}
	else if (x < y && z< y) {
		return y;
	}
	else if (y < x && z < x) {
		return x;
	}
	else {
		return  0;
	}
}
double functionmin(double x, double y){
	if (x < y) {
		return  x;
	}
	else if (y < x) {
		return y;
	}
	else {
		return 0;
	}
}
double check(char type) {
	string foo;
	regex b("^[-]?[0-9]+[.]?[0-9]*$");
	regex b1("^[-]?[0-9]+[.]{1}$");
	do {
		cout << "Enter the meaning of " << type << "\n";
		getline(cin, foo);
	} while (!regex_match(foo, b) || regex_match(foo, b1));
	return stod(foo);
}