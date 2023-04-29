#include<iostream>
#include<string>
#include<regex>
using namespace std;

// The function to check the element

int check_element() {
	string N;
	regex check("^([1-9]+[0-9]*)|([0]{1})$");
	cout << "Input your number" << endl;
	getline(cin, N);
	while (!regex_match(N, check)) {
		cout << "Error. Input your number correctly" << endl;
		getline(cin, N);
	}
	return stoi(N);
}

// The main function

int main() {
	int N = check_element(), counter = 0;
	bool ping = false;
	char number[256], c[1];
	char* needed_string = NULL;
	sprintf_s(number, "%d", N);
	for (int i = 0; i < strlen(number); i++) {
		c[0] = number[i];
		int element = atoi(c);
		if (element % 3 == 0 && element!=0) {
			if (ping == true) {
				needed_string[counter] = element+'0';
			}
			counter++;
		}
		if (ping == false && i == strlen(number) - 1) {
			if (counter != 0) needed_string = new char[counter];
			else break;
			i = -1;
			counter = 0;
			ping = true;
		}
	}
	if (needed_string != NULL) {
		cout << "Your string: ";
		for (int i = 0; i < counter; i++) {
			cout << needed_string[i] << " ";
		}
		delete[] needed_string;
	}
	else cout << "Didn't find certain digits" << endl;
	return 0;
}