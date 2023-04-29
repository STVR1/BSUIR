#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>

using namespace std;

// The class with information

class info {
public:
	void show(vector<info>&);
	void save(string, vector<info>&);
	void read(string, vector<info>&);
	void add(vector<info>&);
	void search(vector<info>&);
private:
	string name;
	string group;
	string mark_phys;
	string mark_math;
	string mark_info;
	double mark_avg=0;
};

// The function to choose the mod to fill (for adding function)

int mod_add() {
	string choice;
	regex check("^[1-2]{1}$");
	cout << "Choose the mod to add: manually (1) or from file (2)" << endl;
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
	regex check("^[1-5]{1}$");
	cout << "Choose the operation" << endl;
	cout << "1. Creation (reading from file)" << endl;
	cout << "2. Adding" << endl;
	cout << "3. Saving" << endl;
	cout << "4. Showing" << endl;
	cout << "5. Search (according to task)" << endl;
	getline(cin, choice);
	while (!regex_match(choice, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, choice);
	}
	return stoi(choice);
}

// The function to define the amount of rows (for adding function)

int amount_rows() {
	string rows;
	regex check("^[1-9]+[0-9]*$");
	cout << "How many rows do you want to add?" << endl;
	getline(cin, rows);
	while (!regex_match(rows, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, rows);
	}
	return stoi(rows);
}

// The function to warn user that he has already had a created list

int sure() {
	string sure;
	regex check("^[1-2]{1}$");
	cout << "Your list isn't empty. Do you want to replace it: Yes (1) or Not (2)?" << endl;
	getline(cin, sure);
	while (!regex_match(sure, check)) {
		cout << "Error. Input it again" << endl;
		getline(cin, sure);
	}
	return stoi(sure);
}

// The function to exit or continue work with this application

int choice_end() {
	string choice;
	regex check("^[1-2]{1}$");
	cout << "Do you want to exit: Yes (1) or Not (2)" << endl;
	getline(cin, choice);
	while (!regex_match(choice, check)) {
		cout << "Error. Input your choice again" << endl;
		getline(cin, choice);
	}
	return stoi(choice);
}

// The function to check our path to the .txt file

string path_check() {
	string path;
	regex check("^([A-Za-z0-9[:space:]]+[:]{1}){1}(([\\\\]{1}[A-Za-z0-9[:space:]]+)*([\\\\]{1}[A-Za-z0-9[:space:]]+(.txt){1}){1}){1}$");
	cout << "Input the path to the .txt file" << endl;
	getline(cin, path);
	while (!regex_match(path, check)) {
		cout << "Error. Input the correct path to the .txt file" << endl;
		getline(cin, path);
	}
	return path;
}

// The function to read info from file

void info::read(string path, vector<info>& list) {
	int size = 0;
	string name_1, name_2, name_3;
	ifstream file(path);
	if (file.is_open()) {
		string temp;
		while (getline(file, temp)) size++;
		file.close();
		if (size != 0) {
			list.resize(size);
			file.open(path);
			for (int i = 0; i < size; i++) {
				file >> name_1 >> name_2 >> name_3 >> list[i].group >> list[i].mark_phys >> list[i].mark_math >> list[i].mark_info;
				list[i].mark_avg = (stod(list[i].mark_info) + stod(list[i].mark_math) + stod(list[i].mark_phys)) / 3;
				list[i].name = name_1 + "\t" + name_2 + "\t" + name_3;
			}
			file.close();
		}
		else cout << "Your file is empty" << endl;
	}
	else cout << "Error. Can't open [" << path << "]" << endl;
}

// The function to save a list into the certain file

void info::save(string path, vector<info>& list) {
	ofstream file(path);
	if (file.is_open()) {
		for (int i = 0; i < list.size(); i++) {
			file << list[i].name << "\t" << list[i].group << "\t" << list[i].mark_phys << "\t" << list[i].mark_math << "\t" << list[i].mark_info <<"\t" << list[i].mark_avg << endl;
		}
		file.close();
	}
	else cout << "Error. Can't open " << path << "" << endl;
}

// The function to add info in the list (manual or reading mods)

void info::add(vector<info>& list) {
	if (mod_add() == 1) {
		string name_1, name_2, name_3;
		int i = list.size();
		list.resize(list.size() + amount_rows());
		for (i; i < list.size(); i++) {
			cout << "Input your row (left " << list.size() - i << ")" << endl;
			cin >> name_1 >>name_2>>name_3>> list[i].group >> list[i].mark_phys >> list[i].mark_math >> list[i].mark_info;
			list[i].mark_avg = (stod(list[i].mark_phys) + stod(list[i].mark_math) + stod(list[i].mark_info))/3;
			list[i].name = name_1 + "\t" + name_2 + "\t" + name_3;
		}
	}
	else {
		string path = path_check();
		ifstream file(path);
		if (file.is_open()) {
			string temp, name_1, name_2, name_3;
			int counter = 0;
			while (getline(file, temp)) {
				counter++;
			}
			file.close();
			if (counter != 0) {
				int i = list.size();
				list.resize(list.size() + counter);
				file.open(path);
				for (i; i < list.size(); i++) {
					file >> name_1 >> name_2 >> name_3 >> list[i].group >> list[i].mark_phys >> list[i].mark_math >> list[i].mark_info;
					list[i].name = name_1 + "\t" + name_2 + "\t" + name_3;
					list[i].mark_avg = (stod(list[i].mark_phys) + stod(list[i].mark_math) + stod(list[i].mark_info)) / 3;
				}
				file.close();
			}
			else cout << "Your file is empty" << endl;
		}
		else cout << "Error. Can't open [" << path << "]" << endl;
	}
}

// The function to show a list

void info::show(vector<info>& list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].name << "\t" << list[i].group << "\t" << list[i].mark_phys << "\t" << list[i].mark_math << "\t" << list[i].mark_info<<"\t"<<list[i].mark_avg << "\t" << endl;
	}
}

// The function to search students who passed session on 8 or higher

void info::search(vector<info>& list) {
	bool searched = false;
	for (int i = 0; i < list.size(); i++) {
		if (list[i].mark_avg > 8) {
			if(searched==false) cout << "Searched information" << endl;
			searched = true;
			cout << list[i].name << "\t" << list[i].group << "\t" << list[i].mark_phys << "\t" << list[i].mark_math << "\t" << list[i].mark_info << "\t" << list[i].mark_avg << endl;
		}
	}
	if (searched == false) cout << "Didn't find" << endl;
}

// The main function

int main() {
	info task;
	vector<info> list;
	string path;
	do {
		switch (choice_operation()) {
		case 1: {
			if (list.size() != 0) {
				if (sure() == 1) {
					list.resize(0);
					path = path_check();
					task.read(path, list);
				}
			}
			else {
				path = path_check();
				task.read(path, list);
			}
			break;
		}
		case 2: {
			if (list.size() != 0) task.add(list);
			else cout << "Error. Your list isn't created" << endl;
			break;
		}
		case 3: {
			path = path_check();
			task.save(path, list);
			break;
		}
		case 4: {
			if (list.size() != 0) task.show(list);
			else cout << "Your list isn't created" << endl;
			break;
		}
		case 5: {
			if (list.size() != 0) task.search(list);
			else cout << "Error. You list isn't created" << endl;
			break;
		}
		}
	} while (choice_end()==2);
	return 0;
}