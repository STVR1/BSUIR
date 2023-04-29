#include<iostream>

using namespace std;

// The regular function

bool reg_func(char* string) {
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] != string[strlen(string) - i - 1]) {
			cout << "This string is false" << endl;
			return false;
		}
		if (i == strlen(string) - 1 && string[i] == string[strlen(string) - i - 1]) {
			cout << "This string is true" << endl;
			return true;
		}
	}
}

// The recursive function

bool rec_func(char* string, int start, int end) {
	if (string[start] == string[end] && start == strlen(string) - 1) {
		cout << "This string is true" << endl;
		return true;
	}
	else if (string[start] == string[end]) rec_func(string, start += 1, end -= 1);
	else {
		cout << "This string is false" << endl;
		return false;
	}
}

// The main function to complete two methods and compare them

int main() {
	char string[256];
	cout << "Input your string" << endl;
	cin.getline(string, 256);
	int method_1=reg_func(string);
	int method_2=rec_func(string, 0, strlen(string) - 1);
	if (method_1 == method_2) cout << "Both variants are equal" << endl;
	else cout << "Both variants aren't equal" << endl;
	return 0;
}