#include<iostream>
#include<string>
#include<regex>

using namespace std;

// The class List with all needed methods

template<typename info>

class List {

private:

	struct list {
		info n=0;
		list* prev = NULL;
		list* next = NULL;

	};

	list* begin = NULL, *end = NULL;

public:

	// The method to push back the new element of the list

	void push_back(info n) {
		list* field = new list;
		field->n = n;
		if (begin == NULL) begin = end = field;
		else {
			field->prev = end;
			end->next = field;
			end = field;
		}
	}

	// The method to push front the new element of the list

	void push_front(info n) {
		list* field = new list;
		field->n = n;
		if (begin == NULL) begin = end = field;
		else {
			field->next = begin;
			begin->prev = field;
			begin = field;
		}
	}

	// The method to sort the elements (info) in the list

	void sort() {
		list* field_1 = begin, * field_2 = NULL;
		for (field_1; field_1 != NULL; field_1 = field_1->next) {
			for (field_2 = field_1->next; field_2 != NULL; field_2 = field_2->next) {
				if (field_1->n > field_2->n)swap(field_1->n, field_2->n);
			}
		}
	}

	// The method to show the list from beginning

	void show_begin() {
		list* field = begin;
		while (field != NULL) {
			cout << field->n << endl;
			field = field->next;
		}
	}

	// The method to show the list from ending

	void show_end() {
		list* field = end;
		while (field != NULL) {
			cout << field->n << endl;
			field = field->prev;
		}
	}

	// The method to pop back the element in the list

	void pop_back() {
		if (end == NULL) return;
		list* field = end->prev;
		if (field != NULL) field->next = NULL;
		else begin = NULL;
		delete end;
		end = field;
	}

	// The method to pop front the element in the list

	void pop_front() {
		if (begin == NULL) return;
		list* field = begin->next;
		if (field != NULL) field->prev = NULL;
		else end = NULL;
		delete begin;
		begin = field;
	}

	// The method to return the size of the list

	int size() {
		list* field = begin;
		int size = 0;
		while (begin != NULL) {
			size++;
			field = field->next;
		}
		return size;
	}

	// The method to return the iterator on the beginning of the list

	auto get_begin() {
		return begin;
	}

	// The method to return the iterator on the ending of the list

	auto get_end() {
		return end;
	}

	// The method to define, if the list is empty

	bool empty() {
		if (begin == NULL) return true;
		else return false;
	}

};

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

List<int> fill(List<int> list, int& size, int& choice_where, int& choice_method) {
	int num = 0;
	if (choice_where == 1) {
		for (int i = 0; i < size; i++) {
			if (choice_method == 1) {
				num = rand() % 101 + (-50);
				list.push_front(num);
			}
			else {
				cout << "Input your number (" << size - i << " left):" << endl;
				num = check_num();
				list.push_front(num);
			}
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			if (choice_method == 1) {
				num = rand() % 101 + (-50);
				list.push_back(num);
			}
			else {
				cout << "Input your number (" << size - i << " left):" << endl;
				num = check_num();
				list.push_back(num);
			}
		}
	}
	return list;
}

// The function to divide list into two (one with positive and other with negative integers)

void task(List<int> list) {
	list.sort();
	auto field = list.get_begin();
	bool list1 = false, list2 = false;
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
	List<int> list;
	do {
		switch (choice_operation()) {
		case 1: {
			int size = define_size();
			int choice_where = choice_mod("Begin (1) or End (2)");
			int choice_method = choice_mod("Randomly (1) or Manually (2)");
			int num = 0;
			if (choice_where == 1) {

					if (choice_method == 1) num = rand() % 101 + (-50);
					else {
						cout << "Input your number (" << size << " left):";
						num = check_num();
						cout << endl;
					}
					list=fill(list,size,  choice_where, choice_method);
			}
			else {
					if (choice_method == 1) num = rand() % 101 + (-50);
					else {
						cout << "Input your number (" << size << " left):";
						num = check_num();
						cout << endl;
					}
					list=fill(list, size, choice_where, choice_method);
			}
			cout << "*****SUCCESSFULLY ADDED*****" << endl;
			break;
		}
		case 2: {
			if (!list.empty()) {
				cout << endl << "*****YOUR LIST*****" << endl << endl;
				list.show_begin();
				cout << endl;
			}
			else cout << "Your list isn't created" << endl;
			break;
		}
		case 3: {
			if (!list.empty()) {
				cout << endl << "*****YOUR LIST*****" << endl << endl;
				list.show_end();
				cout << endl;
			}
			else cout << "Your list isn't created" << endl;
			break;
		}
		case 4: {
			if (!list.empty()) task(list);
			else cout << "Your list isn't created" << endl;
			break;
		}
		}
	} while (choice_mod("Do you want to continue: yes (1) or not (2)?") == 1);
	while (!list.empty()) list.pop_back();
	return 0;
}