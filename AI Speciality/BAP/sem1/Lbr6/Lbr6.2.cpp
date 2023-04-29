#include<iostream>
using namespace std;
int main() {
	char string[256];
	int limit1 = 1;
	int limit0 = 1;
	int x1 = 0;
	int x0 = 0;
	cout << "Enter only 1 or 0\n";
	cin.getline(string, 256);
	int len = strlen(string);
	for (int i = 0; i < len; i++) {
		if (string[i] != '1' && string[i] != '0') {
			string[255];
			cout << "Error. Your string has other elements. You must enter only 1 or 0. Enter it again\n";
			cin.getline(string, 256);
		}
	}
	len = strlen(string);
	for (int i = 0; i < len; i++) {
		if (i > 0) {
			if (string[i] == '1' && string[i - 1] == '1') {
				limit1++;
			}
			else {
				limit1 = 1;
			}
			if (string[i] == '0' && string[i - 1] == '0') {
				limit0++;
			}
			else {
				limit0 = 1;
			}
			if (limit1 == 5) {
				x1++;
				limit1 = 1;
			}
			if (limit0 == 5) {
				x0++;
				limit0 = 1;
			}
		}
	}
	cout << "The amount of groups with the element 1\n";
	cout << x1 << endl;
	cout << "The amount of groups with the element 0\n";
	cout << x0 << endl;
	cout << "The amount of groups with the elements 1 and 0\n";
	cout << x1 + x0 << endl;
	return 0;
}