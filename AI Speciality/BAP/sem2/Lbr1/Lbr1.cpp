#include<iostream>
#include<cmath>
#include<string>
#include<regex>

using namespace std;

//The regular function

int method_1(int& N, int i) {
	int x = 1, extra = 0, number = 0, n = N;
	while (i > 0) {
		extra = n % i;
		n = n / i;
		if (x == 1) number = extra;
		else number = x * extra + number;
		x *= 10;
		if (fabs(n) < i) {
			number = n * x + number;
			break;
		}
	}
	return number;
}

//The recursive function

int method_2(int extra, int n, int i, int x, int number) {
	if (fabs(n) < i) {
		return 10 * x * n + number;
	}
	else {
		x *= 10;
		method_2(n % i, n / i, i, x, x * (n % i) + number);
	}
}

//The function to show the result

void showing(int& N) {
	cout << "System" << "\t" << "Reg" << "\t" << "Rec" << "\t" << "Comparison" << endl;
	cout << "10" << "\t" << N << "\t" << N << "\t" << "Equal" << endl;
	for (int i = 9; i > 1; i--) {
		int x = 1;
		int num_reg = method_1(N, i);
		int num_rec = method_2(N % i, N / i, i, x, N % i);
		if (num_rec == num_reg) cout << i << "\t" << num_reg << "\t" << num_rec << "\t" << "Equal" << endl;
		else cout << i << "\t" << num_reg << "\t" << num_rec << "\t" << "Different" << endl;
	}
}

//The function to check our number

int check_1() {
	string N;
	regex check("^([-]?[1-9]+[0-9]*){1}$");
	cout << "Input the number" << endl;
	getline(cin, N);
	while (!regex_match(N, check)) {
		cout << "Error. Input the correct number" << endl;
		getline(cin, N);
	}
	return stoi(N);
}

//The main function to make task

int main() {
	int N = check_1();
	showing(N);
	return 0;
}