#include<iostream>
#include<list>
#include<string>
#include<regex>

using namespace std;

// The function to choose the option between two

int choice_mod(string info) {
	string choice;
	regex check("^[1-2]{1}$");
	cout << "" << info << "" << endl;
	getline(cin, choice);
	while (!regex_match(choice, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, choice);
	}
	return stoi(choice);
}

// The function to choose the operation

int choice_operation() {
	string choice;
	regex check("^[1-4]{1}$");
	cout << "1. Adding" << endl;
	cout << "2. Show from the begin" << endl;
	cout << "3. Show from the end" << endl;
	cout << "4. Divide into two lists" << endl;
	getline(cin, choice);
	while (!regex_match(choice, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, choice);
	}
	return stoi(choice);
}

// The function to define the size of the list (Adding option)

int define_size() {
	string size;
	regex check("^[1-9]{1}[0-9]*$");
	cout << "Input the size of your list" << endl;
	getline(cin, size);
	while (!regex_match(size, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, size);
	}
	return stoi(size);
}

// The function to check inputed number (Manually option)

int check_num() {
	string num;
	regex check("^([-]?[1-9]{1}[0-9]*)|([0]{1})$");
	getline(cin, num);
	while (!regex_match(num, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, num);
	}
	return stoi(num);
}

// The function to fill the list

void fill(list<int>& info) {
	int num=0,
		size = define_size(),
		choice_where = choice_mod("Begin (1) or end (2)"),
		choice_method = choice_mod("Randomly (1) or manually (2)");
	for (int i=0; i<size; i++) {
		if (choice_where == 1) {
			if (choice_method == 1) {
				num = rand() % 101 + (-51);
				info.push_front(num);
			}
			else {
				cout << "Input your number ("<<size-i<<" left):";
				num = check_num();
				cout << endl;
				info.push_front(num);
			}
		}
		else {
			if (choice_method == 1) {
				num = rand() % 101 + (-51);
				info.push_back(num);
			}
			else {
				cout << "Input your number (" << size - i << " left):";
				num = check_num();
				cout << endl;
				info.push_back(num);
			}
		}
	}
}

// The function to show the list from the beginning

void show_begin(list<int>& info) {
	for (auto i = info.begin(); i != info.end(); i++) {
		cout << *i << endl;
	}
}

// The function to show the list from the end

void show_end(list<int>& info) {
	list<int>:: reverse_iterator it=info.rbegin();
	for (it; it != info.rend(); it++) {
		cout << *it << endl;
	}
}

// The function to divide the list into two (one with negative and other with positive)

void task(list<int>& info) {
	list<int> list_1, list_2;
	for (auto i = info.begin(); i != info.end(); i++) {
		if (*i < 0) {
			list_1.push_back(*i);
		}
		else if (*i > 0) {
			list_2.push_back(*i);
		}
	}
	if (!list_1.empty()) {
		cout << endl << "*****YOUR FIRST LIST*****" << endl << endl;
		show_begin(list_1);
		cout << endl;
	}
	else cout << "You first list is empty" << endl;
	if (!list_2.empty()) {
		cout << endl << "*****YOUR SECOND LIST*****" << endl << endl;
		show_begin(list_2);
		cout << endl;
	}
	else cout << "You second list is empty" << endl;

}

int main() {
	list<int> info;
	do {
		switch (choice_operation()) {
		case 1: {
			fill(info);
			break;
		}
		case 2: {
			if (!info.empty()) {
				cout << endl << "*****Your list*****" << endl << endl;
				show_begin(info);
				cout << endl;
			}
			else cout << "Your list isn't created" << endl;
			break;
		}
		case 3: {
			if (!info.empty()) {
				cout << endl << "*****Your list*****" << endl << endl;
				show_end(info);
				cout << endl;
			}
			else cout << "Your list isn't created" << endl;
			break;
		}
		case 4: {
			if (!info.empty()) {
				task(info);
			}
			else cout << "Your list isn't created" << endl;
			break;
		}
		}
	} while (choice_mod("Do you want to continue your work: yes (1) or not (2)?") == 1);
	return 0;
}