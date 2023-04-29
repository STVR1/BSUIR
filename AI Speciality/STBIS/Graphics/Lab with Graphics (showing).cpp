#include<iostream>
#include<string>
#include<regex>
#include<vector>

using namespace std;

typedef vector<pair<int, int>> Graphic;

// The class Set to work with Graphics

class Set {

private:

	Graphic set_1;

	Graphic set_2;

	Graphic universe;

public:

	// The function to fill the Graphic

	void fill(int which, int power) {
		Graphic buf;
		buf.resize(power);
		string element, element_pair;
		int pos = 0;
		regex check("^([1-9]{1}[0-9]*){1}([[:space:]]){1}([1-9]{1}[0-9]*){1}$");
		bool check_repeat = true;
		do {
			for (int i = 0; i < power; i++) {
				do {
					cout << "Input your cartesion [" << i + 1 << "] (pair through space): ";
					getline(cin, element);
					cout << endl;
				} while (!regex_match(element, check));
				for (int i = 0; i < element.size(); i++) {
					if (element[i] == ' ') {
						pos = i;
						break;
					}
				}
				buf[i].first = stoi(element.substr(0,pos));
				buf[i].second = stoi(element.substr(pos + 1,element.size()-pos-1));
			}
			check_repeat = true;
			for (int i = 0; i < buf.size(); i++) {
				for (int j = 0; j < buf.size(); j++) {
					if (i != j && buf[i] == buf[j]) {
						check_repeat = false;
						i = buf.size();
						break;
					}
				}
			}
		} while (check_repeat == false);
		if (which == 1) set_1 = buf;
		else set_2 = buf;
		buf.resize(0);
		if (universe.empty()) {
			for (int i = 0; i < 50; i++) {
				for (int j = 0; j < 50; j++) {
					universe.push_back(make_pair(i + 1, j + 1));
				}
			}
		}
	}

	// The function to show a certain Graphic

	void show(int which) {
		Graphic buf;
		if (which == 1) buf = set_1;
		else if (which == 2) buf = set_2;
		if (!buf.empty()) {
			cout << "*****Your Graphic*****" << endl;
			for (int i = 0; i < buf.size(); i++) {
				cout << "<" << buf[i].first << ", " << buf[i].second << "> ";
			}
			cout << "}" << endl;
		}
	}

	// The function to return status of Graphic, if it is created

	bool status(int which){
		if (which == 1) {
			if (!set_1.empty()) return true;
			else return false;
		}
		else {
			if (!set_2.empty()) return true;
			else return false;
		}
	}

	// The function to make an operation UNIT

	void unit() {
		cout << "The result of unit: { ";
		for (int i = 0; i <set_1.size(); i++) cout << "<" << set_1[i].first << ", " << set_1[i].second << "> ";
		for (int i = 0; i < set_2.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (set_2[i] == set_1[j]) break;
				if(j==set_1.size()-1) cout << "<" << set_2[i].first << ", " << set_2[i].second << "> ";
			}
		}
		cout << "}" << endl;
	}

	// The function to make an operation Crossing

	void crossing() {
		bool nothing = true;
		cout << "The result of crossing: ";
		for (int i = 0; i < set_1.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (set_1[i]==set_2[j]) {
					if (nothing == true) cout << "{ ";
					cout << "<" << set_1[i].first << ", " << set_1[i].second << "> ";
					nothing = false;
				}
			}
		}
		if (nothing == true) cout << "Empty graphic" << endl;
		else cout << "}" << endl;
	}

	// The function to make an operation COMPLEMENT FOR THE FIRST GRAPHIC

	void complement_1() {
		bool nothing = true;
		cout << "The result of complement for the first set: ";
		for (int i = 0; i < universe.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (universe[i] == set_1[j]) break;
				if (j == set_1.size() - 1) {
					if (nothing == true) cout << "{ ";
					cout << "<" << universe[i].first <<", " << universe[i].second << ">";
					nothing = false;
				}
			}
		}
		if (nothing == true) cout << "Empty graphic" << endl;
		else cout << "}" << endl;
	}

	// The function to make an operation COMPLEMENT FOR THE SECOND GRAPHIC

	void complement_2() {
		bool nothing = true;
		cout << "The result of complement for the second set: ";
		for (int i = 0; i < universe.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (universe[i] == set_2[j]) break;
				if (j == set_2.size() - 1) {
					if (nothing == true) cout << "{";
					cout << "<" << universe[i].first << ", " << universe[i].second << "> ";
					nothing = false;
				}
			}
		}
		if (nothing == true) cout << "Empty graphic" << endl;
		else cout << "}" << endl;
	}

	// The function to male an operation DIFFERENCE BETWEEN THE FIRST AND THE SECOND GRAPHICS

	void difference_12() {
		bool nothing = true;
		cout << "The result of difference between the first and the second sets: ";
		for (int i = 0; i < set_1.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (set_1[i] == set_2[j]) break;
				if (j == set_2.size() - 1) {
					if (nothing == true) cout << "{";
					cout << "<" << set_1[i].first << ", " << set_1[i].second << "> ";	
					nothing = false;
				}
			}
		}
		if (nothing == true) cout << "Empty graphic" << endl;
		else cout << "}" << endl;
	}

	// The function to make an operation DIFFERENCE BETWEEN THE SECOND AND THE FIRST GRAPHICS

	void difference_21() {
		bool nothing = true;
		cout << "The result of difference between the second and the first sets: ";
		for (int i = 0; i < set_2.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (set_2[i] == set_1[j]) break;
				if (j == set_1.size() - 1) {
					if (nothing == true) cout << "{";
					cout << "<" << set_2[i].first << ", " << set_2[i].second << "> ";
					nothing = false;
				}
			}
		}
		if (nothing == true) cout << "Empty graphic" << endl;
		else cout << "}" << endl;
	}

	// The function to make an operation SYMMETRICAL DIFFERENCE BETWEEN THE GRAPHICS

	void sym_difference() {
		bool nothing = true;
		cout << "The result of symmetrical difference: ";
		for (int i = 0; i < set_1.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (set_1[i] == set_2[j])break;
				if (j == set_2.size() - 1) {
					if (nothing == true) cout << "{";
					cout << "<" << set_1[i].first << ", " << set_1[i].second << "> ";
					nothing = false;
				}
			}
		}
		for (int i = 0; i < set_2.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (set_2[i] == set_1[j])break;
				if (j == set_1.size() - 1) {
					if (nothing == true) cout << "{";
					cout << "<" << set_2[i].first << ", " << set_2[i].second << "> ";
					nothing = false;
				}
			}
		}
		if (nothing == true) cout << "Empty Graphic" << endl;
		else cout << "}" << endl;
	}

	// The function to make an operation INVERSION FOR THE FIRST GRAPHIC 

	void inversion_1() {
		cout << "The result of inversion for the first set: { ";
		for (int i = 0; i < set_1.size(); i++) cout << "<" << set_1[i].second << ", " << set_1[i].first << "> ";
		cout << "}" << endl;
	}

	// The function to make an operation INVERSION FOR THE SECOND GRAPHIC

	void inversion_2() {
		cout << "The result of inversion for the second set: { ";
		for (int i = 0; i < set_2.size(); i++) cout << "<" << set_2[i].second << ", " << set_2[i].first << "> ";
		cout << "}" << endl;
	}
	
	// The function to make an operation COMPOSITION BETWEEN THE FIRST AND THE SECOND GRAPHICS 

	void composition_12() {
		bool nothing = true;
		Graphic composition;
		cout << "The result of composition between the first and the second graphics: ";
		for (int i = 0; i < set_1.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (set_1[i].second == set_2[j].first) {
					bool check_repeat = true;
					for (int k = 0; k < composition.size(); k++) {
						if (composition[k].first == set_1[i].first && composition[k].second == set_2[j].second) {
							check_repeat = false;
							k = composition.size();
							break;
						}
					}
					if (check_repeat == true) {
						if (nothing == true) cout << "{";
						composition.push_back(make_pair(set_1[i].first, set_2[j].second));
						cout << "<" << set_1[i].first << ", " << set_2[j].second << "> ";
						nothing = false;
					}
				}
			}
		}
		if (nothing == true) cout << "Empty graphic" << endl;
		else cout << "}" << endl;
	}

	// The function to make an operation COMPOSITION BETWEEN THE SECOND AND THE FIRST GRAPHICS

	void composition_21() {
		bool nothing = true;
		Graphic composition;
		cout << "The result of composition between the first and the second graphics: ";
		for (int i = 0; i < set_2.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (set_2[i].second == set_1[j].first) {
					bool check_repeat = true;
					for (int k = 0; k < composition.size(); k++) {
						if (composition[k].first == set_2[i].first && composition[k].second == set_1[j].second) {
							check_repeat = false;
							k = composition.size();
							break;
						}
					}
					if (check_repeat == true) {
						if (nothing == true) cout << "{";
						composition.push_back(make_pair(set_2[i].first, set_1[j].second));
						cout << "<" << set_2[i].first << ", " << set_1[j].second << "> ";
						nothing = false;
					}
				}
			}
		}
		if (nothing == true) cout << "Empty graphic" << endl;
		else cout << "}" << endl;
	}

};

// The class Check to check input, when we define certain variables

class Check {
	
public:

	// The function to define the power of Graphic

	int check_size(string name) {
		string power;
		regex check("^[1-9]{1}[0-9]*$");
		do {
			cout << "Enter the size of the " << name << " Graphic\n";
			getline(cin, power);
		} while (!regex_match(power, check));
		return stoi(power);
	}

	// The function to define the choice of operation

	int check_operation() {
		string option;
		regex check("^([1-9]{1})|([1]{1}[0-2]{1})$");
		getline(cin, option);
		while (!regex_match(option, check)) {
			cout << "Input option again" <<endl;
			getline(cin, option);
		}
		return stoi(option);
	}

	// The function to end work with program, if an user wants it.

	int check_end(string type) {
		string choice;
		regex check("^[1-2]{1}$");
		cout << ""<<type<<": yes (1) or not (2)?" << endl;
		getline(cin, choice);
		while (!regex_match(choice, check)) {
			cout << "Input option again" << endl;
			getline(cin, choice);
		}
		return stoi(choice);
	}

	// The function to define the choice, if an user wants to change his Graphic

	int check_change() {
		string choice;
		regex check("^[1-4]{1}$");
		do {
			cout << "1. Change the first Graphic\n";
			cout << "2. Change the second Graphic\n";
			cout << "3. Change both Graphics\n";
			cout << "4. Do not change\n";
			getline(cin, choice);
		} while (!regex_match(choice, check));
		return stoi(choice);
	}

};

int main() {
	Set test;
	Check var;
	int power=0;
	do {
		if (test.status(1) == false && test.status(2) == false) {
			power = var.check_size("first");
			test.fill(1, power);
			test.show(1);
			power = var.check_size("second");
			test.fill(2, power);
			test.show(1);
		}
		else {
			switch (var.check_change()) {
			case 1: {
				power = var.check_size("first");
				test.fill(1, power);
				test.show(1);
				break;
			}
			case 2: {
				power = var.check_size("second");
				test.fill(2, power);
				test.show(2);
				break;
			}
			case 3: {
				power = var.check_size("first");
				test.fill(1, power);
				test.show(1);
				power = var.check_size("second");
				test.fill(2, power);
				test.show(2);
				break;
			}
			default: break;
			}
		}
		do {
			cout << "1. Operation unit\n";
			cout << "2. Operation crossing\n";
			cout << "3. Operation complement for the first graphic\n";
			cout << "4. Operation complement for the second graphic\n";
			cout << "5. Operation difference between the first and the second graphics\n";
			cout << "6. Operation difference between the second and the first graphics\n";
			cout << "7. Operation symmetrical difference\n";
			cout << "8. Inversion for the first graphic\n";
			cout << "9. Inversion for the second graphic\n";
			cout << "10. Composition between the first and the second graphics\n";
			cout << "11. Composition between the second and the first graphics\n";
			cout << "12. All operations in row\n";
			switch (var.check_operation()) {
			case 1: {
				test.unit();
				break;
			}
			case 2: {
				test.crossing();
				break;
			}
			case 3: {
				test.complement_1();
				break;
			}
			case 4: {
				test.complement_2();
				break;
			}
			case 5: {
				test.difference_12();
				break;
			}
			case 6: {
				test.difference_21();
				break;
			}
			case 7: {
				test.sym_difference();
				break;
			}
			case 8: {
				test.inversion_1();
				break;
			}
			case 9: {
				test.inversion_2();
				break;
			}
			case 10: {
				test.composition_12();
				break;
			}
			case 11: {
				test.composition_21();
				break;
			}
			case 12: {
				test.unit();

				test.crossing();

				test.complement_1();

				test.complement_2();

				test.difference_12();

				test.difference_21();

				test.sym_difference();

				test.inversion_1();

				test.inversion_2();

				test.composition_12();

				test.composition_21();

				break;
			}
			}
		} while (var.check_end("Do you want to finish work with operations") == 2);
	}while (var.check_end("Do you want to end work with program") == 2);
	return 0;
}