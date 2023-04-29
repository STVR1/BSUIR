#include<iostream>
#include<string>
#include<regex>
#include<ctime>
using namespace std;

/*********************************************************************/

                      //ALL TOOLS FOR STACK

/*********************************************************************/

struct NUMBER {
	int num = 0;
};

struct OBJ {
	NUMBER n;
	OBJ* next=NULL;
};

OBJ* push(OBJ* top, NUMBER n) {
	OBJ* field = new OBJ;
	field->n = n;
	field->next = top;
	return field;
}

OBJ* pop(OBJ* top) {
	OBJ* field = top->next;
	delete top;
	return field;
}

void show(OBJ* top) {
	OBJ* c = top;
	while (c != NULL) {
		cout << c->n.num << endl;
		c = c->next;
	}
}

/*********************************************************************/

                 // ALL FUNCTIONS TO COMPLETE MY TASK                       

/*********************************************************************/

// The function to choose one variant from two

int choice_mod(string inf) {
	string choice;
	regex check("^[1-2]{1}$");
	cout << ""<<inf<<"" << endl;
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

OBJ* fill(OBJ* top) {
	NUMBER n;
	if (choice_mod("Choose the mod to fill your list : randomly from - 50 to 50 (1) or manually(2)") == 1) {
		int size = choice_size();
		for (int i = 0; i < size; i++) {
			n.num = rand() % 101 + (-50);
			top = push(top, n);
		}
	}
	else {
		int size = choice_size();
		for (int i = 0; i < size; i++) {
			cout << "Input your number " << i + 1 << ":";
			n.num = check_number();
			cout << endl;
			top = push(top, n);
		}
	}
	return top;
}

// The function to sort the list by address 

void sort_address(OBJ* top) {
	OBJ *t=NULL, *t1, *r;
	if (top->next->next == NULL) return;
	do {
		for (t1 = top; t1->next->next != t; t1 = t1->next)
			if (t1->next->n.num > t1->next->next->n.num) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while (top->next->next != t);
}

// The function to sort the list by swapping info

void sort_info(OBJ* top) {
	OBJ* field_1 = top;
	OBJ* field_2 = NULL;
	for (field_1; field_1 != NULL; field_1 = field_1->next) {
		field_2 = field_1->next;
		for (field_2; field_2 != NULL; field_2 = field_2->next) {
			if (field_1->n.num > field_2->n.num) swap(field_1->n.num, field_2->n.num);
		}
	}
}

// The function to divide the list into two (one with positive numbers and other with negative)

void task(OBJ* top, int& choice_sort) {
	OBJ* field = top;
	bool list1 = false, list2 = false;

	while (field != NULL) {
		if (field->n.num < 0) {
			if (list1 == false) {
				cout << "Your first list" << endl;
				list1 = true;
			}
			cout << field->n.num << endl;
		}
		else if (field->n.num > 0) {
			if (list2 == false) {
				cout << "Your second list" << endl;
				list2 = true;
			}
			cout << field->n.num << endl;
		}

		field = field->next;
	}
	if (list1 == false) cout << "Your first list is empty" << endl;
	if (list2 == false) cout << "Your second list is empty" << endl;
}

/*********************************************************************/

int main() {

	srand(time(NULL));
	OBJ* top = NULL, *list_1=NULL, *list_2=NULL;

	// Create my list

	top = fill(top);    
	show(top);

	// Sort my list

	int choice_sort = choice_mod("Choose the method to sort: address (1) or info (2)");

	if (choice_sort == 1) {
		NUMBER n;
		n.num = 0;
		top = push(top, n);
		sort_address(top);
		top = pop(top);
	}
	else sort_info(top);
	
	cout << endl;
    show(top);

	// Divide my list according to task

	task(top, choice_sort);

	// Delete my list

	while (top != NULL) top=pop(top);
	
	return 0;
}