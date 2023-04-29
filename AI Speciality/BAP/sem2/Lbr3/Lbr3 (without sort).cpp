#include<iostream>
#include<string>
#include<regex>
#include<ctime>
#include<stack>

using namespace std;

// The function to choose one variant of two

int choice_mod(string inf) {
	string choice;
	regex check("^[1-2]{1}$");
	cout << "" << inf << "" << endl;
	getline(cin, choice);
	while (!regex_match(choice, check)) {
		cout << "Error. Input it again" << endl;
	}
	return stoi(choice);
}

// The function to define the size of the list

int define_size() {
	string size;
	regex check("^[1-9]{1}[0-9]*$");
	cout << "Input the size" << endl;
	getline(cin, size);
	while (!regex_match(size, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, size);
	}
	return stoi(size);
}

// The function to check inputed number

int check_number() {
	string number;
	regex check("^([-]?[1-9]{1}[0-9]*)|([0]{1})$");
	getline(cin, number);
	while (!regex_match(number, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, number);
	}
	return stoi(number);
}

// The function to fill the list

void fill(stack<int>& list) {
	int size = define_size();
	if (choice_mod("Randomly (1) or manually (2)") == 1) {
		for (int i = 0; i < size; i++) {
			list.push(rand() % 101 + (-50));
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "Input your number " << i + 1 << ":";
			int number = check_number();
			list.push(number);
		}
	}
}

// The function to show the list

void show(stack<int>& list) {
	auto a = list._Get_container();
	if (!a.empty()) {
		for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
	}
	else cout << "Nothing" << endl;
}

// The function to divide the list into two

void task(stack<int>& list) {
	stack<int> list_1, list_2;
	while (!list.empty()) {
		if (list.top() < 0) list_1.push(list.top());
		else if (list.top() > 0) list_2.push(list.top());
		list.pop();
	}
	cout <<endl<< "Your list 1 (negative):" << endl<<endl;
	show(list_1);
	cout << endl << "Your list 2(positive):" << endl<<endl;
	show(list_2);
}

int main() {
	srand(time(NULL));
	stack<int> list;
	fill(list);
	cout << endl << "Your list:" << endl << endl;
	show(list);
	task(list);
	return 0;
}