#include<iostream>
#include<string>
#include<regex>
#include<fstream>

using namespace std;

/***********************************************************************************/

// Structure with information (index number, full name, address, date)

struct info {
    string number;
    string name;
    string address;
    string date;
};

/***********************************************************************************/

                        /*THE FUNCTIONS TO DEFINE THE CHOICES*/

/***********************************************************************************/

// The function to end program, according to user's choice

int choice_operation() {
    string choice;
    regex check("^[1-9]{1}$");
    cout << "Choose one option:" << endl;
    cout << "1. Creation" << endl;
    cout << "2. Showing (current)" << endl;
    cout << "3. Adding" << endl;
    cout << "4. Saving" << endl;
    cout << "5. Linear search in file" << endl;
    cout << "6. Selection sort in the list" << endl;
    cout << "7. Quick sort in the list" << endl;
    cout << "8. Double search sort in the list" << endl;
    cout << "9. Delete repeated rows" << endl;
    getline(cin, choice);
    while (!regex_match(choice, check)) {
        cout << "Error. Input the correct option" << endl;
        getline(cin, choice);
    }
    return stoi(choice);
}

// The function, which returns choice between two options according to the question

int choice(string question) {
    string choice;
    regex check("^[1-2]{1}$");
    cout << "" << question << "" << endl;
    getline(cin, choice);
    while (!regex_match(choice, check)) {
        cout << "Error. Input the correct variant" << endl;
        getline(cin, choice);
    }
    return stoi(choice);
}

// The function to choose key element in row to search it

int key_search() {
    string choice;
    regex check("^[1-4]{1}$");
    cout << "What info do you want to search?" << endl;
    cout << "1. The number" << endl;
    cout << "2. The name" << endl;
    cout << "3. The address" << endl;
    cout << "4. The date" << endl;
    getline(cin, choice);
    while (!regex_match(choice, check)) {
        cout << "Error. Input it again" << endl;
        getline(cin, choice);
    }
    return stoi(choice);
}

/***********************************************************************************/

                          /*THE FUNCTIONS TO CHECK INPUT*/

/***********************************************************************************/

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

// The function to check the number

string number_check() {
    string taken;
    regex check("^(([+](375))|(80))((44)|(25)|(29)|(33)){1}([0-9]{7})$");
    cout << "Input the number" << endl;
    getline(cin, taken);
    while (!regex_match(taken, check)) {
        cout << "Error. Input the number again" << endl;
        getline(cin, taken);
    }
    return taken;
}

// The function to check the name 

string name_check() {
    string taken;
    regex check("^([[:alpha:]]+[[:space:]]{1}){2}([[:alpha:]]+){1}$");
    cout << "Input the name" << endl;
    getline(cin, taken);
    while (!regex_match(taken, check)) {
        cout << "Error. Input the name again" << endl;
        getline(cin, taken);
    }
    return taken;
}

// The function to check the address

string address_check() {
    string taken;
    regex check("^([[:alpha:]]+[[:space:]]{1}[0-9]+[,]{1}[[:space:]]{1}[0-9]+)$");
    cout << "Input the address" << endl;
    getline(cin, taken);
    while (!regex_match(taken, check)) {
        cout << "Error. Input the address again" << endl;
        getline(cin, taken);
    }
    return taken;
}

// The function to check the date

string date_check() {
    string taken;
    regex check("^[0-9]{2}(.){1}[0-9]{2}(.){1}[0-9]{4}$");
    do {
        cout << "Input the date: form (DD.MM.YYYY)" << endl;
        getline(cin, taken);
    } while (!regex_match(taken, check));
    return taken;
}

/***********************************************************************************/

                        /*THE FUNCTIONS TO DEFINE THE SIZE*/

/***********************************************************************************/

// The function to define the size of list, which reads from file

int size_list(string path) {
    ifstream file;
    string temp;
    int size = 0;
    file.open(path);
    while (getline(file, temp)) {
        size++;
    }
    file.close();
    return size;
}

// The function to define the number of rows, which user wants to add into his list.
// It uses only in one step, when I define the size of list after adding extra rows.

int size_amount() {
    string amount;
    regex check("^([1-9]+[0-9]*){1}$");
    cout << "How many rows do you want to add?" << endl;
    getline(cin, amount);
    while (!regex_match(amount, check)) {
        cout << "Error. Input the correct amount of rows" << endl;
        getline(cin, amount);
    }
    return stoi(amount);
}

// The function to define the new size (if list has repeated rows)

int new_size(info* list, int size) {
    int to_delete = 0, new_amount = size;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i].number == list[j].number && list[i].name == list[j].name && list[i].address == list[j].address && list[i].date == list[j].date) {
                to_delete++;
            }
            if (to_delete != 0 && !(list[i].number == list[j].number && list[i].name == list[j].name && list[i].address == list[j].address && list[i].date == list[j].date)) {
                new_amount = new_amount - to_delete;
                to_delete = 0;
                i = j - 1;
                break;
            }
            if (j == size - 1) new_amount = new_amount - to_delete;
        }
    }
    return new_amount;
}

/***********************************************************************************/

                        /*THE FUNCTIONS (OPERATIONS)*/

/***********************************************************************************/

// The function to delete our list

info* deleting(info* list) {
    delete[] list;
    return NULL;
}

// The function to read the list from file

info* reading(info* list, string path, int mod, int large) {
    string temp;
    ifstream file(path);
    int size = 0;
    if (file.is_open()) {
        while (getline(file, temp)) {
            size++;
        }
    }
    else {
        cout << "Error. Can't open [" << path << "]" << endl;
        return NULL;
    }
    file.close();
    if (size == 0) {
        cout << "Error. Your file is empty" << endl;
        return NULL;
    }
    else {
        string name_1, name_2, name_3, address_1, address_2, address_3;
        if (mod == 1) {
            list = new info[size];
            file.open(path);
            for (int i = 0; i < size; i++) {
                file >> list[i].number >> name_1 >> name_2 >> name_3 >> address_1 >> address_2 >> address_3 >> list[i].date;
                list[i].name = name_1 + "\t" + name_2 + "\t" + name_3;
                list[i].address = address_1 + "\t" + address_2 + "\t" + address_3;
            }
            file.close();
            return list;
        }
        else {
            size = size + large;
            info* temp_list = new info[size];
            file.open(path);
            for (int i = 0; i < size; i++) {
                if (i < large) {
                    temp_list[i].number = list[i].number;
                    temp_list[i].name = list[i].name;
                    temp_list[i].address = list[i].address;
                    temp_list[i].date = list[i].date;
                }
                else {
                    file >> temp_list[i].number >> name_1 >> name_2 >> name_3 >> address_1 >> address_2 >> address_3 >> temp_list[i].date;
                    temp_list[i].name = name_1 + "\t" + name_2 + "\t" + name_3;
                    temp_list[i].address = address_1 + "\t" + address_2 + "\t" + address_3;
                }
            }
            file.close();
            list = deleting(list);
            return temp_list;
        }
    }
}

// The function to add rows into the list manually. Adding from file realised in the main function.

info* adding(info* list, int large, int size) {
    info* temp_list = new info[size];
    for (int i = 0; i < size; i++) {
        if (i < large) {
            temp_list[i].number = list[i].number;
            temp_list[i].name = list[i].name;
            temp_list[i].address = list[i].address;
            temp_list[i].date = list[i].date;
        }
        else {
            cout << "Input the new row (" << size - i << " left)" << endl;
            temp_list[i].number = number_check();
            temp_list[i].name = name_check();
            temp_list[i].address = address_check();
            temp_list[i].date = date_check();
        }
    }
    list = deleting(list);
    return temp_list;
}

// The function to save the list into the certain file 

void writing(info* list, string path, int size) {
    ofstream file(path);
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            file << list[i].number << "\t" << list[i].name << "\t" << list[i].address << "\t" << list[i].date << endl;
        }
    }
    else {
        cout << "Error. Can't open [" << path << "]" << endl;
    }
}

// The fucntion to show the list

void showing(info* list, int size) {
    cout << "№" << "\t" << "Name" << "\t" << "Address" << "\t" << "Date" << endl;
    for (int i = 0; i < size; i++) {
        cout << list[i].number << "\t" << list[i].name << "\t" << list[i].address << "\t" << list[i].date << endl;
    }
}

// The function to search the certain info in the file (linear search)

void linear_search() {
    string path = path_check(), taken, number, name, address, name_1, name_2, name_3, address_1, address_2, address_3, date;
    int variant;
    ifstream file(path);
    if (file.is_open()) {
        variant = key_search();
        switch (variant) {
        case 1: {
            cout << "Input the number" << endl;
            taken = number_check();
            break;
        }
        case 2: {
            cout << "Input the name" << endl;
            taken = name_check();
            break;
        }
        case 3: {
            cout << "Input the address" << endl;
            taken = address_check();
            break;
        }
        case 4: {
            cout << "Input the date" << endl;
            taken = date_check();
            break;
        }
        }
        bool nothing = false;
        while (file >> number >> name_1 >> name_2 >> name_3 >> address_1 >> address_2 >> address_3 >> date) {
            name = name_1 + " " + name_2 + " " + name_3;
            address = address_1 + " " + address_2 + " " + address_3;
            switch (variant) {
            case 1: {
                if (taken == number) {
                    cout << number << "\t" << name << "\t" << address << "\t" << date << endl;
                    nothing = true;
                }
                break;
            }
            case 2: {
                if (taken == name) {
                    cout << number << "\t" << name << "\t" << address << "\t" << date << endl;
                    nothing = true;
                }
                break;
            }
            case 3: {
                if (taken == address) {
                    cout << number << "\t" << name << "\t" << address << "\t" << date << endl;
                    nothing = true;
                }
                break;
            }
            case 4: {
                if (taken == date) {
                    cout << number << "\t" << name << "\t" << address << "\t" << date << endl;
                    nothing = true;
                }
                break;
            }
            }
        }
        if (nothing == false) cout << "Nothing found" << endl;
    }
    else cout << "Error. Can't open [" << path << "]" << endl;
    file.close();
}

//The function to search info in the sorted list (double search). The key is the date

void double_search(info* list, int size) {
    string taken = date_check();
    int i = 0, mid = 0, was_1 = -1, was_2 = -1;
    bool nothing = true;
    while (size - i != 0) {
        mid = (i + size) / 2;
        if (taken == list[i].date && was_1 != i) {
            cout << list[i].number << "\t" << list[i].name << "\t" << list[i].address << "\t" << list[i].date << endl;
            nothing = false;
            was_1 = i;
        }
        if (taken == list[size].date && was_2 != size) {
            cout << list[size].number << "\t" << list[size].name << "\t" << list[size].address << "\t" << list[size].date << endl;
            nothing = false;
            was_2 = size;
        }
        string temp1, temp2;
        temp1.resize(4), temp2.resize(4);
        for (int k = 0, p = 6; k < 4; k++, p++) {
            temp1[k] = list[mid].date[p];
            temp2[k] = taken[p];
        }
        if (stoi(temp1) == stoi(temp2)) {
            temp1.resize(2), temp2.resize(2);
            for (int k = 0, p = 3; k < 2; k++, p++) {
                temp1[k] = list[mid].date[p];
                temp2[k] = taken[p];
            }
            if (stoi(temp1) == stoi(temp2)) {
                temp1.resize(2), temp2.resize(2);
                for (int k = 0, p = 0; k < 2; k++, p++) {
                    temp1[k] = list[mid].date[p];
                    temp2[k] = taken[p];
                }
                if (stoi(temp1) > stoi(temp2)) size = mid - 1;
                else if (stoi(temp1) < stoi(temp2)) i = mid + 1;
                else i++;
            }
            else if (stoi(temp1) > stoi(temp2)) size = mid - 1;
            else if (stoi(temp1) < stoi(temp2)) i = mid + 1;
        }
        else if (stoi(temp1) > stoi(temp2)) size = mid - 1;
        else if (stoi(temp1) < stoi(temp2)) i = mid + 1;
    }
    if (nothing == true) {
        cout << "Nothing found" << endl;
    }
}

// The function to delete repited rows in the list

info* delete_repeated(info* list, int size, int new_amount) {
    if (new_amount != 0) {
        info* new_list = new info[new_amount];
        int i = 0;
        for (int j = 0; j < size; j++) {
            if (j == 0) {
                new_list[i].number = list[j].number;
                new_list[i].name = list[j].name;
                new_list[i].address = list[j].address;
                new_list[i].date = list[j].date;
                i++;
            }
            if (i < new_amount && j != 0 && !(list[j].number == list[j - 1].number && list[j].name == list[j - 1].name && list[j].address == list[j - 1].address && list[j].date == list[j - 1].date)) {
                new_list[i].number = list[j].number;
                new_list[i].name = list[j].name;
                new_list[i].address = list[j].address;
                new_list[i].date = list[j].date;
                i++;
            }
        }
        list = deleting(list);
        return new_list;
    }
    else return list;
}

// The function to sort the list (selection sort)

void selection_sort(info* list, int size) {
    for (int i = 0; i < size; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            string temp1, temp2;
            temp1.resize(4), temp2.resize(4);
            for (int k = 0, p = 6; k < 4; k++, p++) {
                temp1[k] = list[min_index].date[p];
                temp2[k] = list[j].date[p];
            }
            if (stoi(temp1) > stoi(temp2)) {
                min_index = j;
            }
            else if (stoi(temp1) == stoi(temp2)) {
                temp1.resize(2), temp2.resize(2);
                for (int k = 0, p = 3; k < 2; k++, p++) {
                    temp1[k] = list[min_index].date[p];
                    temp2[k] = list[j].date[p];
                }
                if (stoi(temp1) > stoi(temp2)) {
                    min_index = j;
                }
                else if (stoi(temp1) == stoi(temp2)) {
                    temp1.resize(4), temp2.resize(4);
                    for (int k = 0, p = 0; k < 2; k++, p++) {
                        temp1[k] = list[min_index].date[p];
                        temp2[k] = list[j].date[p];
                    }
                    if (stoi(temp1) > stoi(temp2)) {
                        min_index = j;
                    }
                }
            }
        }
        swap(list[i], list[min_index]);
    }
}

// The function to sort the list (quick sort)

int key(info* list, int start, int index) {
    for (int i = 0; i < index;) {
        string temp1, temp2;
        temp1.resize(4), temp2.resize(4);
        for (int k = 0, p = 6; k < 4; k++, p++) {
            temp1[k] = list[i].date[p];
            temp2[k] = list[index].date[p];
        }
        if (stoi(temp1) > stoi(temp2) && i == index - 1) {
            swap(list[i], list[index]);
            index--;
        }
        else if (stoi(temp1) > stoi(temp2)) {
            swap(list[index - 1], list[index]);
            swap(list[i], list[index]);
            index--;
        }
        else if (stoi(temp1) == stoi(temp2)) {
            temp1.resize(2), temp2.resize(2);
            for (int k = 0, p = 3; k < 2; k++, p++) {
                temp1[k] = list[i].date[p];
                temp2[k] = list[index].date[p];
            }
            if (stoi(temp1) > stoi(temp2) && i == index - 1) {
                swap(list[i], list[index]);
                index--;
            }
            else if (stoi(temp1) > stoi(temp2)) {
                swap(list[index - 1], list[index]);
                swap(list[i], list[index]);
                index--;
            }
            else if (stoi(temp1) == stoi(temp2)) {
                temp1.resize(2), temp2.resize(2);
                for (int k = 0, p = 0; k < 2; k++, p++) {
                    temp1[k] = list[i].date[p];
                    temp2[k] = list[index].date[p];
                }
                if (stoi(temp1) > stoi(temp2) && i == index - 1) {
                    swap(list[i], list[index]);
                    index--;
                }
                else if (stoi(temp1) > stoi(temp2)) {
                    swap(list[index - 1], list[index]);
                    swap(list[i], list[index]);
                    index--;
                }
                else i++;
            }
            else i++;
        }
        else i++;
    }
    return index;
}

void quick_sort(info* list, int start, int end) {
    if (start < end) {
        int index = key(list, start, end);
        quick_sort(list, start, index - 1);
        quick_sort(list, index + 1, end);
    }
}

/***********************************************************************************/

// The main function, which consists of the variables (list, size of list, path), cycle do-while
// and the operator switch in it.  

int main() {
    info* list = NULL;
    int size = 0;
    bool sorted = false;
    string path;
    do {
        switch (choice_operation()) {
        case 1: {
            if (list == NULL) {
                path = path_check();
                list = reading(list, path, 1, size);
                sorted = false;
                if (list != NULL) size = size_list(path);
            }
            else {
                if (choice("Your list is created. Do you want to: replace (1) it or continue work (2) with it?") == 1) {
                    list = deleting(list);
                    path = path_check();
                    list = reading(list, path, 1, size);
                    sorted = false;
                    if (list != NULL) size = size_list(path);
                }
            }
            break;
        }
        case 2: {
            if (list == NULL) cout << "Error. You don't have a list" << endl;
            else showing(list, size);
            break;
        }
        case 3: {
            if (list == NULL) cout << "Your list isn't created" << endl;
            else {
                if (choice("Do you want to add manually (1) or from file (2)?") == 1) {
                    int amount = size_amount();
                    list = adding(list, size, size + amount);
                    size = size + amount;
                }
                else {
                    path = path_check();
                    list = reading(list, path, 3, size);
                    size = size + size_list(path);
                }
                sorted = false;
            }
            break;
        }
        case 4: {
            if (list == NULL) cout << "Error. You don't have a list" << endl;
            else {
                path = path_check();
                writing(list, path, size);
            }
            break;
        }
        case 5: {
            linear_search();
            break;
        }
        case 6: {
            if (list != NULL) {
                selection_sort(list, size);
                sorted = true;
                cout << "Successfully sorted" << endl;
            }
            else cout << "Error. Your list isn't created" << endl;
            break;
        }
        case 7: {
            if (list != NULL) {
                quick_sort(list, 0, size - 1);
                sorted = true;
                cout << "Successfully sorted" << endl;
            }
            else cout << "Error. Your list isn't created" << endl;
            break;
        }
        case 8: {
            if (list != NULL) {
                if (sorted == true) {
                    double_search(list, size - 1);
                }
                else cout << "Your array isn't sorted" << endl;
            }
            else cout << "Your list isn't created" << endl;
            break;
        }
        case 9: {
            if (list != NULL) {
                if (sorted == true) {
                    int new_amount = new_size(list, size);
                    if (new_amount != size) {
                        list = delete_repeated(list, size, new_amount);
                        size = new_amount;
                        cout << "Successfully deleted" << endl;
                    }
                    else cout << "You don't have repeated rows" << endl;
                }
                else cout << "Your array isn't sorted" << endl;
            }
            else cout << "Your list isn't created" << endl;
            break;
        }
        }
    } while (choice("Do you want to make one more operation with this list: yes (1) or not (2)?") == 1);
    list = deleting(list);
    return 0;
}