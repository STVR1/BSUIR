#include<iostream>
#include<string>
#include<regex>
#include<ctime>
using namespace std;

// The class MyStack with needed methods

template<typename info>

class MyStack {
	
private:

	struct OBJ {
		info n=0;
		OBJ* next = NULL;
	};
	OBJ* top=NULL;

public:

	// The method to push 

	void push(info num) {
		OBJ* field = new OBJ;
		field->n = num;
		field->next = top;
		top = field;
	}

	// The method to pop 

	void pop() {
		OBJ* field = top->next;
		delete top;
		top = field;
	}

	// The method to get an iterator

	auto get() {
		return top;
	}

	// The method to sort the list by address 

	void sort_address() {
		OBJ* t = NULL, * t1, * r;
		if (top->next->next == NULL) return;
		do {
			for (t1 = top; t1->next->next != t; t1 = t1->next)
				if (t1->next->n > t1->next->next->n) {
					r = t1->next->next;
					t1->next->next = r->next;
					r->next = t1->next;
					t1->next = r;
				}
			t = t1->next;
		} while (top->next->next != t);
	}

	// The method to sort the list by swapping info

	void sort_info() {
		OBJ* field_1 = top;
		OBJ* field_2 = NULL;
		for (field_1; field_1 != NULL; field_1 = field_1->next) {
			field_2 = field_1->next;
			for (field_2; field_2 != NULL; field_2 = field_2->next) {
				if (field_1->n > field_2->n) swap(field_1->n, field_2->n);
			}
		}
	}

	// The method to define, if stack is empty

	bool empty() {
		if (top == NULL) return true;
		else return false;
	}

};

/*********************************************************************/

				 // ALL FUNCTIONS TO COMPLETE MY TASK                       

/*********************************************************************/

// The function to choose one variant from two

int choice_mod(string inf) {
	string choice;
	regex check("^[1-2]{1}$");
	cout << "" << inf << "" << endl;
	getline(cin, choice);
	while (!regex_match(choice, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, choice);
	}
	return stoi(choice);
}

// The function to define the size of the list

int choice_size() {
	string size;
	regex check("^[1-9]{1}[0-9]*$");
	cout << "Input the size of your list" << endl;
	getline(cin, size);
	while (!regex_match(size, check)) {
		cout << "Error. Input the size correctly" << endl;
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
		cout << "Input it correctly" << endl;
		getline(cin, number);
	}
	return stoi(number);
}

// The function to fill the list

MyStack<int> fill(MyStack<int> top) {
	int num = 0;
	if (choice_mod("Choose the mod to fill your list : randomly from - 50 to 50 (1) or manually(2)") == 1) {
		int size = choice_size();
		for (int i = 0; i < size; i++) {
			num = rand() % 101 + (-50);
			top.push(num);
		}
	}
	else {
		int size = choice_size();
		for (int i = 0; i < size; i++) {
			cout << "Input your number " << i + 1 << ":";
			num = check_number();
			cout << endl;
			top.push(num);
		}
	}
	return top;
}

void show(MyStack<int> top) {
	auto c = top.get();
	if (c == NULL) cout << "true";
	while (c != NULL) {
		cout << c->n << endl;
		c = c->next;
	}
}

// The function to divide the list into two (one with positive numbers and other with negative)

void task(MyStack<int> test, int& choice_sort) {
	auto field = test.get();
	bool list1 = false, list2 = false;
	while (field != NULL) {
		if (field->n < 0) {
			if (list1 == false) {
				cout << "Your first list" << endl;
				list1 = true;
			}
			cout << field->n << endl;
		}
		else if (field->n > 0) {
			if (list2 == false) {
				cout << "Your second list" << endl;
				list2 = true;
			}
			cout << field->n << endl;
		}

		field = field->next;
	}
	if (list1 == false) cout << "Your first list is empty" << endl;
	if (list2 == false) cout << "Your second list is empty" << endl;
}

/*********************************************************************/

int main() {

	srand(time(NULL));

	// Create my list

	MyStack<int> top;
	top=fill(top);
	show(top);

	// Sort my list

	int choice_sort = choice_mod("Choose the method to sort: address (1) or info (2)");
	if (choice_sort == 1) {
		int n = 0;
		top.push(n);
		top.sort_address();
		top.pop();
	}
	else top.sort_info();
	cout << endl;
	show(top);

	// Divide my list according to task

	task(top, choice_sort);

	// Delete my list

	while (!top.empty()) top.pop();

	return 0;
}