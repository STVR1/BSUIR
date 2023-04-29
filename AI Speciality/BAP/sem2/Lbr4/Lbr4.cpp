#include<iostream>
#include<string>
#include<regex>

using namespace std;

/*********************************************************************/

						//ALL TOOLS FOR LIST

/*********************************************************************/

struct List {
	int n = 0;
	List* next = NULL, * prev = NULL;
};

List* push_end(List* begin, List* end, int& num) {
	List* field = new List;
	field->n = num;
	if (begin == NULL) return field;
	else {
		field->prev = end;
		end->next = field;
		return field;
	}
}

List* push_begin(List* begin, List* end, int& num) {
	List* field = new List;
	field->n = num;
	if (begin == NULL) return field;
	else {
		field->next = begin;
		begin->prev = field;
		return field;
	}
}

List* pop(List* begin) {
	List* field = begin->next;
	delete begin;
	return field;
}

void show_begin(List* begin) {
	List* field = begin;
	while (field != NULL) {
		cout << field->n << endl;
		field = field->next;
	}
}

void show_end(List* end) {
	List* field = end;
	while (field != NULL) {
		cout << field->n << endl;
		field = field->prev;
	}
}

/*********************************************************************/

					   //ALL FUNCTIONS FOR APLICATION

/*********************************************************************/

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
	regex check("^([-][1-9]{1}[0-9]*)|([0]{1})$");
	getline(cin, num);
	while (!regex_match(num, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, num);
	}
	return stoi(num);
}

// The function to fill my list

List* fill(List* begin, List* end, int size, int& choice_where, int& choice_method) {
	int num = 0;
	if (choice_where == 1) {
		for (int i = 0; i < size; i++) {
			if (choice_method == 1) {
				num = rand() % 101 + (-50);
				begin = push_begin(begin, end, num);
			}
			else {
				cout << "Input your number (" << size - i << " left):" << endl;
				num = check_num();
				begin = push_begin(begin, end, num);
			}
		}
		return begin;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (choice_method == 1) {
				num = rand() % 101 + (-50);
				end = push_end(begin, end, num);
			}
			else {
				cout << "Input your number (" << size - i << " left):" << endl;
				num = check_num();
				end = push_end(begin, end, num);
			}
		}
		return end;
	}
}

// The function to sort the list

void sort(List* begin) {
	List* field_1 = begin, * field_2 = NULL;
	for (field_1; field_1 != NULL; field_1 = field_1->next) {
		for (field_2 = field_1->next; field_2 != NULL; field_2 = field_2->next) {
			if (field_1->n > field_2->n) swap(field_1->n, field_2->n);
		}
	}
}

// The function to divide list into two (one with positive and other with negative integers)

void task(List* begin) {

	List* field = begin;
	bool list1 = false, list2 = false;
	sort(field);
	while (field != NULL) {
		if (field->n < 0) {
			if (list1 == false) {
				cout << "*****Your first list*****" << endl;
				list1 = true;
			}
			cout << field->n << endl;
		}
		else if (field->n > 0) {
			if (list2 == false) {
				cout << "*****Your second list*****" << endl;
				list2 = true;
			}
			cout << field->n << endl;
		}
		field = field->next;
	}
	if (list1 == false) cout << "Your first list is empty" << endl;
	if (list2 == false) cout << "Your second list is empty" << endl;
	cout << endl << "*****TASK COMPLETED*****" << endl;
}

/*********************************************************************/

int main() {
	srand(time(NULL));
	List* begin = NULL, * end = NULL;
	do {
		switch (choice_operation()) {
		case 1: {
			int size = define_size();
			int choice_where = choice_mod("Begin (1) or End (2)");
			int choice_method = choice_mod("Randomly (1) or Manually (2)");
			int num = 0;
			if (choice_where == 1) {
				if (begin == NULL) {
					if (choice_method == 1) num = rand() % 101 + (-50);
					else {
						cout << "Input your number (" << size << " left):";
						num = check_num();
						cout << endl;
					}
					begin = end = push_begin(begin, end, num);
					begin = fill(begin, end, size - 1, choice_where, choice_method);
				}
				else begin = fill(begin, end, size, choice_where, choice_method);
			}
			else {
				if (begin == NULL) {
					if (choice_method == 1) num = rand() % 101 + (-50);
					else {
						cout << "Input your number (" << size << " left):";
						num = check_num();
						cout << endl;
					}
					begin = end = push_end(begin, end, num);
					end = fill(begin, end, size - 1, choice_where, choice_method);
				}
				else end = fill(begin, end, size, choice_where, choice_method);
			}
			cout << "*****SUCCESSFULLY ADDED*****" << endl;
			break;
		}
		case 2: {
			if (begin != NULL) {
				cout << endl << "*****YOUR LIST*****" << endl << endl;
				show_begin(begin);
				cout << endl;
			}
			else cout << "Your list isn't created" << endl;
			break;
		}
		case 3: {
			if (begin != NULL) {
				cout << endl << "*****YOUR LIST*****" << endl << endl;
				show_end(end);
				cout << endl;
			}
			else cout << "Your list isn't created" << endl;
			break;
		}
		case 4: {
			if (begin != NULL) task(begin);
			else cout << "Your list isn't created" << endl;
			break;
		}
		}
	} while (choice_mod("Do you want to continue: yes (1) or not (2)?") == 1);
	while (begin != NULL) begin = pop(begin);
	return 0;
}