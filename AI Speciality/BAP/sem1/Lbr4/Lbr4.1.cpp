#include<iostream>
#include<string>
#include<regex>
#include<ctime>
using namespace std;

// The function to define the size of the array

int def_size() {
    string size;
    regex check("^[1-9]+[0-9]*$");
    cout << "Input the size" << endl;
    getline(cin, size);
    while (!regex_match(size, check)) {
        cout << "Error. Input the size correctly" << endl;
        getline(cin, size);
    }
    return stoi(size);
}

// The function to check and define user's choice, how to fill the array

int choice_mod() {
    string choice;
    regex check("^[1-2]{1}$");
    cout << "Choose the mod: manually (1) or randomly (2)" << endl;
    getline(cin, choice);
    while (!regex_match(choice, check)) {
        cout << "Error. Input the choice correctly" << endl;
        getline(cin, choice);
    }
    return stoi(choice);
}

// The function to check the element

int element_check() {
    string element;
    regex check("^([-][1-9]+[0-9]*)|([0]{1})$");
    getline(cin, element);
    while (!regex_match(element, check)) {
        cout << "Error. Input it again" << endl;
        getline(cin, element);
    }
    return stoi(element);
}

// The function to fill the array

void fill(int* array, int& size) {
    if (choice_mod() == 1) {
        for (int i = 0; i < size; i++) {
            cout << "Input the element of the array [" << i << "]: ";
            array[i] = element_check();
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            array[i] = rand() % 41 - 20;
        }
    }
}

// The function to show the elements of the array

void show(int* array, int& size) {
    cout << "Your array: [";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout <<"]" << endl;
}

// The function to complete the task (count the arithmetical mean)

void task(int* array, int& size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) sum = sum + array[i];
    }
    sum = sum / size;
    if (sum == 0) cout << "We couldn't define the arithmetical mean, because we hadn't found positive elements" << endl;
    else cout <<"Your sum: "<< sum << endl;
}

// The main function

int main() {
    srand(time(NULL));
    int size = def_size();
    int* array = new int[size];
    fill(array, size);
    show(array, size);
    task(array, size);
    delete[] array;
    return 0;
}