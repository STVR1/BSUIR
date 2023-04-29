#include<iostream>
#include<string>
#include<regex>
#include<vector>

using namespace std;

typedef vector<pair<int, int>> Graphic;

// The class Set to work with Graphics

class Set {

private:

	Graphic set_1; //1

	Graphic set_2; //2

	Graphic set_unit; //3

	Graphic set_crossing; //4

	Graphic set_complement_1; //5

	Graphic set_complement_2; //6

	Graphic universe; //7

	Graphic set_difference_12; //8
	
	Graphic set_difference_21; //9

	Graphic set_sym_difference; //10

	Graphic set_inversion_1; //11

	Graphic set_inversion_2; //12

	Graphic set_composition_12; //13

	Graphic set_composition_21; //14

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
		if (which == 1) {
			cout << "Your first Graphic: ";
			set_1 = buf;
		}
		else if (which == 2) {
			cout << "Your second Graphic: ";
			set_2 = buf;
		}
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
		switch (which) {
		case 1: {
			buf = set_1;
			break;
		}
		case 2: {
			buf = set_2;
			break;
		}
		case 3: {
			buf = set_unit;
			break;
		}
		case 4: {
			buf = set_crossing;
			break;
		}
		case 5: {
			buf = set_complement_1;
			break;
		}
		case 6: {
			buf = set_complement_2;
			break;
		}
		case 7: {
			buf = universe;
			break;
		}
		case 8: {
			buf = set_difference_12;
			break;
		}
		case 9: {
			buf = set_difference_21;
			break;
		}
		case 10: {
			buf = set_sym_difference;
			break;
		}
		case 11: {
			buf = set_inversion_1;
			break;
		}
		case 12: {
			buf = set_inversion_2;
			break;
		}
		case 13: {
			buf = set_composition_12;
			break;
		}
		case 14: {
			buf = set_composition_21;
			break;
		}
		}
		if (buf.empty()) cout << "Empty Graphic" << endl;
		else {
			cout << "{ ";
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
		if (!set_unit.empty()) set_unit.resize(0);
		cout << "The result of unit: ";
		for (int i = 0; i <set_1.size(); i++) set_unit.push_back(set_1[i]);
		for (int i = 0; i < set_2.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (set_2[i] == set_1[j]) break;
				if(j==set_1.size()-1) set_unit.push_back(set_2[i]);
			}
		}
	}

	// The function to make an operation Crossing

	void crossing() {
		if (!set_crossing.empty()) set_crossing.resize(0);
		cout << "The result of crossing: ";
		for (int i = 0; i < set_1.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (set_1[i]==set_2[j]) set_crossing.push_back(set_1[i]);
			}
		}
	}

	// The function to make an operation COMPLEMENT FOR THE FIRST GRAPHIC

	void complement_1() {
		if (!set_complement_1.empty()) set_complement_1.resize(0);
		cout << "The result of complement for the first set: ";
		for (int i = 0; i < universe.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (universe[i] == set_1[j]) break;
				if (j == set_1.size() - 1) set_complement_1.push_back(universe[i]);
			}
		}
	}

	// The function to make an operation COMPLEMENT FOR THE SECOND GRAPHIC

	void complement_2() {
		if (!set_complement_2.empty()) set_complement_2.resize(0);
		cout << "The result of complement for the second set: ";
		for (int i = 0; i < universe.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (universe[i] == set_2[j]) break;
				if (j == set_2.size() - 1) set_complement_2.push_back(universe[i]);
			}
		}
	}

	// The function to male an operation DIFFERENCE BETWEEN THE FIRST AND THE SECOND GRAPHICS

	void difference_12() {
		if (!set_difference_12.empty()) set_difference_12.resize(0);
		cout << "The result of difference between the first and the second sets: ";
		for (int i = 0; i < set_1.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (set_1[i] == set_2[j]) break;
				if (j == set_2.size() - 1) set_difference_12.push_back(set_1[i]);
			}
		}
	}

	// The function to make an operation DIFFERENCE BETWEEN THE SECOND AND THE FIRST GRAPHICS

	void difference_21() {
		if (!set_difference_21.empty()) set_difference_21.resize(0);
		cout << "The result of difference between the second and the first sets: ";
		for (int i = 0; i < set_2.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (set_2[i] == set_1[j]) break;
				if (j == set_1.size() - 1) set_difference_21.push_back(set_2[i]);
			}
		}
	}

	// The function to make an operation SYMMETRICAL DIFFERENCE BETWEEN THE GRAPHICS

	void sym_difference() {
		if (!set_sym_difference.empty()) set_sym_difference.resize(0);
		cout << "The result of symmetrical difference: ";
		for (int i = 0; i < set_1.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (set_1[i] == set_2[j])break;
				if (j == set_2.size() - 1) set_sym_difference.push_back(set_1[i]);
			}
		}
		for (int i = 0; i < set_2.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (set_2[i] == set_1[j])break;
				if (j == set_1.size() - 1) set_sym_difference.push_back(set_2[i]);
			}
		}
	}

	// The function to make an operation INVERSION FOR THE FIRST GRAPHIC 

	void inversion_1() {
		if (!set_inversion_1.empty()) set_inversion_1.resize(0);
		cout << "The result of inversion for the first set: ";
		for (int i = 0; i < set_1.size(); i++) set_inversion_1.push_back(make_pair(set_1[i].second, set_1[i].first));
	}

	// The function to make an operation INVERSION FOR THE SECOND GRAPHIC

	void inversion_2() {
		if (!set_inversion_2.empty()) set_inversion_2.resize(0);
		cout << "The result of inversion for the second set: ";
		for (int i = 0; i < set_2.size(); i++) set_inversion_2.push_back(make_pair(set_2[i].second, set_2[i].first));
	}
	
	// The function to make an operation COMPOSITION BETWEEN THE FIRST AND THE SECOND GRAPHICS 

	void composition_12() {
		if (!set_composition_12.empty()) set_composition_12.resize(0);
		cout << "The result of composition between the first and the second graphics: ";
		for (int i = 0; i < set_1.size(); i++) {
			for (int j = 0; j < set_2.size(); j++) {
				if (set_1[i].second == set_2[j].first) {
					bool check_repeat = true;
					for (int k = 0; k < set_composition_12.size(); k++) {
						if (set_composition_12[k].first == set_1[i].first && set_composition_12[k].second == set_2[j].second) {
							check_repeat = false;
							k = set_composition_12.size();
							break;
						}
					}
					if (check_repeat == true) set_composition_12.push_back(make_pair(set_1[i].first, set_2[j].second));
				}
			}
		}
	}

	// The function to make an operation COMPOSITION BETWEEN THE SECOND AND THE FIRST GRAPHICS

	void composition_21() {
		if (!set_composition_21.empty()) set_composition_21.resize(0);
		cout << "The result of composition between the first and the second graphics: ";
		for (int i = 0; i < set_2.size(); i++) {
			for (int j = 0; j < set_1.size(); j++) {
				if (set_2[i].second == set_1[j].first) {
					bool check_repeat = true;
					for (int k = 0; k < set_composition_21.size(); k++) {
						if (set_composition_21[k].first == set_2[i].first && set_composition_21[k].second == set_1[j].second) {
							check_repeat = false;
							k = set_composition_21.size();
							break;
						}
					}
					if(check_repeat==true) set_composition_21.push_back(make_pair(set_2[i].first, set_1[j].second));
				}
			}
		}
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
				test.show(3);
				break;
			}
			case 2: {
				test.crossing();
				test.show(4);
				break;
			}
			case 3: {
				test.complement_1();
				test.show(5);
				break;
			}
			case 4: {
				test.complement_2();
				test.show(6);
				break;
			}
			case 5: {
				test.difference_12();
				test.show(8);
				break;
			}
			case 6: {
				test.difference_21();
				test.show(9);
				break;
			}
			case 7: {
				test.sym_difference();
				test.show(10);
				break;
			}
			case 8: {
				test.inversion_1();
				test.show(11);
				break;
			}
			case 9: {
				test.inversion_2();
				test.show(12);
				break;
			}
			case 10: {
				test.composition_12();
				test.show(13);
				break;
			}
			case 11: {
				test.composition_21();
				test.show(14);
				break;
			}
			case 12: {
				test.unit();
				test.show(3);
				test.crossing();
				test.show(4);
				test.complement_1();
				test.show(5);
				test.complement_2();
				test.show(6);
				test.difference_12();
				test.show(8);
				test.difference_21();
				test.show(9);
				test.sym_difference();
				test.show(10);
				test.inversion_1();
				test.show(11);
				test.inversion_2();
				test.show(12);
				test.composition_12();
				test.show(13);
				test.composition_21();
				test.show(14);
				break;
			}
			}
		} while (var.check_end("Do you want to finish work with operations") == 2);
	}while (var.check_end("Do you want to end work with program") == 2);
	return 0;
}