#include<iostream>
#include<cmath>
#include<string>
#include<regex>
using namespace std;
float check1(char);
int factorial(int);
float yfunc(float);
void ysdfunc(int, float, int,  int, int);
int main() {
	char fo;
	int k = 0, k1, n1 = 0;
	float a, b, h, n,x;
	a = check1('a');
	b= check1('b');
	h= check1('h');
	n= check1('n');
	while (n < 1) {
		n = check1('n');
	}
	cout << "__________________________________________________________" << endl;
	cout << "Number"<<"\t" << "x" << "\t" << "Y(x)" << "\t" << "S(x)" << "\t" << "|Y(x)-S(x)|" << "\t" << "Amount of actions" << endl;
	for (k1 = 1, x = a; x <= b; k1++, x += h) {
		ysdfunc(k, x, n1, n, k1);
	}
	cout << "__________________________________________________________" << endl;
	return 0;
}
int factorial(int n1) {
	if (n1 == 0) return 1;
	if (n1 == 1) return 1;
	return n1 * factorial(n1 - 1);
}
void ysdfunc(int k, float x, int n1,  int n, int k1) {
	float s = 0, sum = 0, difference = 0;
	for (k = 0, sum = 0; k <= n - 1; k++) {
		n1 = 2 * k + 1;
		s = pow(-1, k) * pow(x, 2 * k + 1) / factorial(n1);
		sum += s;
		difference = fabs(yfunc(x) - sum);
		if (difference < 0.0001) {
			break;
		}
	}
	cout << k1 << "." << "\t" << x <<"\t" << yfunc(x) << "\t" << sum << "\t" << difference << "\t" << k + 1 << endl;
}
float yfunc(float x) {
	return sin(x);
}
float check1(char fo) {
	string foo;
	regex b1("^[-]?[0-9]+[.]?[0-9]*$");
	regex b2("^[-]?[0-9]+[.]{1}$");
	cout << "Enter "<<fo<<":\n";
	getline(cin, foo);
	while (!regex_match(foo, b1) || regex_match(foo, b2)) {
		cout << "Error. Enter "<<fo<<" again\n";
		getline(cin, foo);
	}
	return stof(foo);
}