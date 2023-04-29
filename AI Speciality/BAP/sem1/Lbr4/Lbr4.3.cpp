#include<iostream>
#include<string>
#include<regex>
#include<sstream>
using namespace std;

// The function to complete task: find digits multiples of 3 and write them in the array

void task(string& N) {
    int number = 0, size = 0;
    bool ping = false;
    int* array = NULL;
    for (int i = 0; i < N.size(); i++) {
        stringstream ss;
        ss << N[i];
        ss >> number;
        if (number % 3 == 0) {
            if (ping == true) array[size] = number;
            size++;
        }
        if (i == N.size() - 1 && ping == false) {
            if (size == 0) {
                cout << "Can't do it" << endl;
                break;
            }
            else array = new int[size];
            size = 0;
            i = -1;
            ping = true;
        }
    }
    if (array != NULL) {
        cout << "Your array: [ ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << "]" << endl;
        delete[] array;
    }
}

// The main function: checks, defines the meaning of N and completes the task

int main() {
    string N;
    regex check("^([1-9]+[0-9]*)|([0]{1})$");
    cout << "Input N" << endl;
    getline(cin, N);
    while (!regex_match(N, check)) {
        cout << "Error. Input it again" << endl;
        getline(cin, N);
    }
    task(N);
    return 0;
}