#include<iostream>
#include<string>
#include<regex>
#include<ctime>

using namespace std;

// The function to check the meaning of size (rows and columns)

int check_size(string parameter) {
	string size;
	regex check("^[1-9]+[0-9]*$");
	cout << "Input the number of " << parameter << "" << endl;
	getline(cin, size);
	while (!regex_match(size, check)) {
		cout << "Error. Input the correct meaning of " << parameter << "" << endl;
		getline(cin, size);
	}
	return stoi(size);
}

// The function to check and to define the choice of mod to fill the array

int choice_mod() {
	string choice;
	regex check ("^[1-2]{1}$");
	cout << "Choose the mod to fill your array: manually (1) or randomly (2)" << endl;
	getline(cin, choice);
	while (!regex_match(choice, check)) {
		cout << "Error. Input your choice again" << endl;
		getline(cin, choice);
	}
	return stoi(choice);
}

// The function to check and to define the element 

int element_check() {
	string element;
	regex check("^([-]?[1-9]+[0-9]*)|([0]{1})$");
	getline(cin, element);
	while (!regex_match(element, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, element);
	}
	return stoi(element);
}

// The function to fill the array 

void fill(int** array, int& n, int& m) {
	if (choice_mod() == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << "Input the element [" << i << "][" << j << "]: ";
				array[i][j] = element_check();
				cout << endl;
			}
		}
	}
	else {
		int parameter=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				array[i][j] = rand()% 21 -10;
				
			}
		}
	}
}

// The function to show the array

void show(int** array, int& n, int& m) {
	cout << "Your array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "|"<<"\t";
		for (int j = 0; j < m; j++) {
			cout << array[i][j] << "\t";
		}
		cout << "|"<<endl;
	}
}

// The function to delete the array

void delete_array(int** array, int& n, int& m) {
	for (int i = 0; i < n; i++) {
		delete array[i];
	}
	delete[] array;
}

// The function to complete task (find rows with all 0 elements)

void task(int** array, int& n, int& m) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (array[i][j] != 0) break;
			if (j == m - 1 && array[i][j] == 0) counter++;
		}
	}
	cout << "The number of certain rows: " << counter << endl;
}

// The main function

int main() {
	srand(time(NULL));
	int n = check_size("rows");
	int m = check_size("columns");
	int** array = new int* [n];
	for (int i = 0; i < n; i++) {
		array[i] = new int[m];
	}
	fill(array, n, m);
	show(array, n, m);
	task(array, n, m);
	delete_array(array, n, m);
	return 0;
}