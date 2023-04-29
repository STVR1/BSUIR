#include<iostream>
#include<cmath>
#include<string>
#include<regex>
#include<sstream> 
using namespace std;
int factorial(int);
float yfunc(float);
float sfunc(int, float, int, int);
float dfunc(int, float, int, int);
float check(char);
void Out_Rez(int, int, float, int, int, float, float, float);
int main() {
	//Set variables which I need for checking and calculating
	char fo;
	float a, b, h, x, n;
	int k = 0, n1 = 0;
	//Check variables and set them meanings
	a = check('a');
	x = a;
	b = check('b');
	h = check('h');
	n = check('n');
	int key;
	//Main cycle
	do {
		//Choose operation
		string key1;
		regex b4("[1-3]{1}");
		regex b6("[1-2]{1}");
		do {
			cout << "Choose the number of function, which you want to calculate:" << endl;
			cout << "1. Y(x)=sin(x)" << endl;
			cout << "2. S(x)=(k=0)Z(n) (-1)^k * x^(2k+1):(2k+1)!" << endl;
			cout << "3. |Y(x)-S(x)|" << endl;
			getline(cin, key1);
		} while (!regex_match(key1, b4));
		stringstream s2;
		s2 << key1;
		s2 >> key;
		Out_Rez(key, k, x, n1, n, a, b, h);
		//Cycle for choosing: continue the program or exit from it (choice of user)
		do {
			cout << "Do you want to make one more operation? Enter 1 if yes and enter 2 to exit\n";
			getline(cin, key1);
		} while (!regex_match(key1, b6));
		key = stoi(key1);
	} while (key == 1);
	return 0;
}
//Function to calculate factorial  
int factorial(int n1) {
	if (n1 == 0) return 1;
	if (n1 == 1) return 1;
	return n1 * factorial(n1 - 1);
}
//Function to calculate meaning of y=sin(x)
float yfunc(float x) {
	return sin(x);
}
//Function to calculate sum
float sfunc(int k, float x, int n1, int n) {
	float s = 0, sum = 0;
	for (k = 0, sum = 0; k <= n - 1; k++) {
		yfunc(x);
		n1 = 2 * k + 1;
		s = pow(-1, k) * pow(x, 2 * k + 1) / factorial(n1);
		sum += s;
	}
	return sum;
}
//Function for calculating difference
float dfunc(int k, float x, int n1, int n) {
	float  difference = 0;
	difference = fabs(yfunc(x) - sfunc(k, x, n1, n));
	return difference;
}
//Function to check variables
float check(char fo) {
	string foo;
	float foo1 = 0;
	regex b1("^[-]?[0-9]+[.]?[0-9]*$");
	regex b2("^[-]?[0-9]+[.]{1}$");
	do {
		cout << "Enter a valid number " << fo << ":\n";
		getline(cin, foo);
	} while (!regex_match(foo, b1) || regex_match(foo, b2));
	stringstream s;
	s << foo;
	s >> foo1;
	return foo1;
}
//Function for choosing the certain function by user
void Out_Rez(int key, int k, float x, int n1, int n, float a, float b, float h) {
	int k1 = 1;
	switch (key) {
	case 1: {
		cout << "Number" << "\t" << "x" << "\t" << "Y(x)" << "\t" << endl;
		for (k1 = 1, x = a; x <= b; k1++, x += h) {
		cout << k1 << "." << "\t" << x << "\t" << yfunc(x) << "\t" << endl;
		}
		break;
	}
	case 2: {
		cout << "Number" << "\t" << "x" << "\t" << "Y(x)" << "\t" << "S(x)" << "\t" << endl;
		for (k1 = 1, x = a; x <= b; k1++, x += h) {
		cout << k1 << "." << "\t" << x << "\t" << yfunc(x) << "\t" << sfunc(k, x, n1, n) << "\t" << endl;
		}
		break;
	}
	case 3: {
		cout << "Number" << "\t" << "x" << "\t" << "Y(x)" << "\t" << "S(x)" << "\t" << "|Y(x)-S(x)|" << "\t" << endl;
		for (k1 = 1, x = a; x <= b; k1++, x += h) {
		cout << k1 << "." << "\t" << x << "\t" << yfunc(x) << "\t" << sfunc(k, x, n1, n) << "\t" << dfunc(k, x, n1, n) << "\t" << endl;
		}
		break;
	}
	}
}