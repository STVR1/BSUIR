#include<iostream>

using namespace std;

// The function to complete task (count the amount of elements 'a' and count the amount of elements in string)

void task(char* string) {
	int counter_size = 0, counter_a = 0;
	for (int i = 0; string[i] != '\0'; i++) {
		counter_size++;
		if (string[i] == 'a') counter_a++;
	}
	cout << "The size of your string: " << counter_size << endl;
	cout << "The number of elements 'a': " << counter_a << endl;
}

// The main function

int main() {
	char string[256];
	cout << "Input your string" << endl;
	cin.getline(string, 256);
	task(string);
	return 0;
}