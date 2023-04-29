#include<iostream>
#include<string>
#include<regex>
#include<ctime>

using namespace std;

// The function to check the size 

int check_size() {
	string size;
	regex check("^[1-9]+[0-9]*$");
	cout << "Input the number of rows (columns)" << endl;
	getline(cin, size);
	while (!regex_match(size, check)) {
		cout << "Error. Input the correct number of rows (columns)" << endl;
		getline(cin, size);
	}
	return stoi(size);
}

// The function to check and define the choice of mod to fill the array

int choice_mod() {
	string choice;
	regex check("^[1-2]{1}$");
	cout << "Choose the mod to fill: manually (1) or randomly (2)" << endl;
	getline(cin, choice);
	while (!regex_match(choice, check)) {
		cout << "Error. Input the correct choice" << endl;
		getline(cin, choice);
	}
	return stoi(choice);
}

// The function to check the element 

int check_element() {
	string element;
	regex check("^([-]{1}[1-9]+[0-9]*)|([0]{1})$");
	getline(cin, element);
	while (!regex_match(element, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, element);
	}
	return stoi(element);
}

// The function to check the meaning of N (power)

int check_N() {
	string N;
	regex check("^([1-9]+[0-9]*)|([0]{1})$");
	cout << "Input the power" << endl;
	getline(cin, N);
	while (!regex_match(N, check)) {
		cout << "Error. Input it correctly" << endl;
		getline(cin, N);
	}
	return stoi(N);
}

// The function to fill the array

void fill(int** array, int& n) {
	if (choice_mod() == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << "Input the element [" << i << "][" << j << "]: ";
				array[i][j] = check_element();
				cout << endl;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				array[i][j] = rand() % 21 - 10;
			}
		}
	}
}

// The function to show the array

void show(int** array, int& n) {
	cout << "Your array:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "|" << "\t";
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << "|" << endl;
	}
}

// The function to delete the array

void delete_array(int** array, int& n) {
	for (int i = 0; i < n; i++) {
		delete[] array[i];
	}
	delete[] array;
}

// The function to complete task (array multiplication)

void task(int** array, int** result, int& n, int& N) {
	int new_element = 0;
	int** extra = new int* [n];
	for (int i = 0; i < n; i++) {
		extra[i] = new int[n];
	}
	if (N == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) result[i][j] = 1;
				else result[i][j] = 0;
			}
		}
	}
	else if (N == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				result[i][j] = array[i][j];
			}
		}
	}
	else if (N > 1) {
		for (int k = 1; k < N; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (k == 1) {
						for (int p = 0; p < n; p++) {
							new_element = array[i][p] * array[p][j] + new_element;
							if (p == n - 1) {
								extra[i][j] = new_element;
								new_element = 0;
							}
						}
					}
					else {
						for (int p = 0; p < n; p++) {
							new_element = extra[i][p] * array[p][j] + new_element;
							if (p == n - 1) {
								result[i][j] = new_element;
								new_element = 0;
							}
						}
					}
				}
			}
			if (N == 2) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						result[i][j] = extra[i][j];
					}
				}
			}
			else if (k > 1 && k != N - 1) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						extra[i][j] = result[i][j];
					}
				}
			}
		}
	}
	delete_array(extra, n);
}

// The main function

int main() {
	srand(time(NULL));
	int n=check_size();
	int** array = new int* [n];
	for (int i = 0; i < n; i++) {
		array[i] = new int[n];
	}
	int** result = new int* [n];
	for (int i = 0; i < n; i++) {
		result[i] = new int[n];
	}
	fill(array, n);
	show(array, n);
	int N = check_N();
	task(array, result, n, N);
	show(result, n);
	delete_array(array, n);
	delete_array(result, n);
	return 0;
}