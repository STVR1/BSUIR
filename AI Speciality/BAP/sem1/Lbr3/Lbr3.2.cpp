#include<iostream>
#include<cmath>
#include<string>
#include<regex>
#include<sstream> 
using namespace std;
int factorial(int);
float check1(char);
int main() {
	//Set variables
    char fo;
	float a, b, h, n, x, y, s, sum, difference;
	int k, k1, n1;
	a = check1('a');
	b = check1('b');
	h = check1('h');
	n = check1('n');
	//Calculate y, sum, difference
	cout << "__________________________________________________________" << endl;
	cout << "Number" <<"\t" << "x" << "\t" << "Y(x)" << "\t" << "S(x)" << "\t" << "|Y(x)-S(x)|"  << endl;
	for (k1 = 1, x = a; x <= b; k1++, x += h) {
		y = sin(x);
		for (k = 0, sum = 0; k <= n - 1; k++) {
			n1 = 2 * k + 1;
			s = pow(-1, k) * pow(x, 2 * k + 1) / factorial(n1);
			sum += s;
		}
		difference = fabs(y - sum);
		cout << k1  << "." << "\t"  << x << "\t"  << y << "\t"  << sum << "\t"  << difference  << endl;
	}
	cout << "__________________________________________________________" << endl;
	return 0;
}
int factorial(int n1) {
	if (n1 == 0) return 1;
	if (n1 == 1) return 1;
	return n1 * factorial(n1 - 1);
}
float check1(char fo) {
	string foo;
	regex b1("^[-]?[0-9]+[.]?[0-9]*$");
	regex b2("^[-]?[0-9]+[.]{1}$");
	cout << "Enter " << fo << ":\n";
	getline(cin, foo);
	while (!regex_match(foo, b1) || regex_match(foo, b2)) {
		cout << "Error. Enter " << fo << " again\n";
		getline(cin, foo);
	}
	return stof(foo);
}