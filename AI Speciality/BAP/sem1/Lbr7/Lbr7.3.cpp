#include<iostream>
#include<string>
#include<regex>
#include<fstream>
using namespace std;

// The function to check the path

string check(); 

// The function to read string with decipher

void rffunc(string);

// The function to save string with cipher

void wffunc(string);

// The main function

int main() {
	string path;
	char choice1;
	char choice2;
	do {
		path=check();
		do {
			cout << "Choose the number of operation, which you want to make\n";
			cout << "1. Write\n";
			cout << "2. Read\n";
			cin >> choice1;
		} while (choice1 != '1' && choice1 != '2');
		if (choice1 == '1') {
			wffunc(path);
		}
		else {
			rffunc(path);
		}
		cout << "Do you want to make one more operation? Press y to continue or other key to exit\n";
		cin >> choice2;
	} while (choice2=='y');
	return 0;
}

void wffunc(string path) {
	ofstream file(path);
	if (file.is_open()) {
		char checkstrS[] = "abcdefghijklmnopqrstuvwxyz";
		char checkstrB[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		bool ping = false;
		do {
			cin.clear();
			cin.ignore();
			char string1[256];
			cout << "Input string into this file (only english letters from ""A-Z or a-z"")\n";
			cin.getline(string1, 256);
			for (int i = 0; i < strlen(string1); i++) {
				for (int j = 0; j < strlen(checkstrS); j++) {
					if (string1[i] == checkstrS[j] || string1[i] == checkstrB[j]) {
						ping = true;
						break;
					}
					else {
						ping = false;
					}
				}
			}
			int size = strlen(string1);
			char* newstring = new char[size];
			if (ping == true) {
				for (int i = 0; i < strlen(string1); i++) {
					for (int j = 0; j < strlen(checkstrS); j++) {
						if (string1[i] == checkstrS[strlen(checkstrS) - 1]) {
							newstring[i] = checkstrS[0];
							break;
						}
						else if (string1[i] == checkstrB[strlen(checkstrB) - 1]) {
							newstring[i] = checkstrB[0];
							break;
						}
						else if (string1[i] == checkstrS[j]) {
							newstring[i] = checkstrS[j + 1];
							break;
						}
						else if (string1[i] == checkstrB[j]) {
							newstring[i] = checkstrB[j + 1];
							break;
						}
						else {
							continue;
						}
					}
					file << newstring[i];
				}
				cout << "Successfully saved\n";
				delete[] newstring;
				file.close();
			}
		} while (ping == false);
	}
	else {
	cout << "Can't open this file [" << path << "]\n";
	}
}

void rffunc(string path) {
	ifstream file(path);
	if (file.is_open()) {
		char ch;
		char checkstrS[] = "abcdefghijklmnopqrstuvwxyz";
		char checkstrB[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		while (file.get(ch)) {
			for (int j = 0; j < strlen(checkstrS); j++) {
				if (ch == checkstrS[0]) {
					ch = checkstrS[strlen(checkstrS)];
					break;
				}
				else if (ch == checkstrB[0]) {
					ch = checkstrB[strlen(checkstrB)];
					break;
				}
				else if (ch == checkstrS[j]) {
					ch = checkstrS[j - 1];
					break;
				}
				else if (ch == checkstrB[j]) {
					ch = checkstrB[j - 1];
					break;
				}
				else {
					continue;
				}
			}
			cout << ch;
		}
		cout << "\n";
		file.close();
	}
	else {
		cout << "Can't open this file [" << path << "]\n";
	}
}

string check() {
	string pathcheck;
	regex checking("^([A-Za-z0-9[:space:]]+[:]{1}){1}(([\\\\]{1}[A-Za-z0-9[:space:]]+)*([\\\\]{1}[A-Za-z0-9[:space:]]+(.txt){1}){1}){1}$");
	do {
		cout << "Input the path for txt file\n";
		getline(cin, pathcheck);
	} while (!regex_match(pathcheck, checking));
	return pathcheck;
}