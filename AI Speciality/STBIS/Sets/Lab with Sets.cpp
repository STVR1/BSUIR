#include<iostream>
#include<string>
#include<regex>
using namespace std;

// The function to check the size of set

int check1(string name) {
    string power;
    regex b1("^(([1-2]{1}[0-9]{1})|[1-9]{1})$");
    do {
        do {
            cout << "Enter the size of the " << name << " set from 1 including to 25 including\n";
            getline(cin, power);
        } while (!regex_match(power, b1));

    } while (stoi(power) > 25);
    return stoi(power);
}

// The function to check the choice of filling a set 

int check2() {
    string key;
    regex b2("[1-2]{1}");
    do {
        cout << "Choose the way of filling your set with numeric numbers [1-50]?\n";
        cout << "1. Using formula 2*k-1, in which k is starting\n";
        cout << "2. Manual\n";
        getline(cin, key);
    } while (!regex_match(key, b2));
    return stoi(key);
}

// The function to check the element of set

int check3(int i) {
    string a;
    regex b("^(([1-5]{1}[0-9]{1})|([1-9]{1}))$");
    i++;
    do {
        do {
            cout << "Input the element " << i << " of set (only from [1;50])\n";
            getline(cin, a);
        } while (!regex_match(a, b));
    } while (stoi(a) > 50);
    return stoi(a);
}

// The function to check repited elements in one set

bool check4(int* array, int size) {
    bool check4 = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && array[i] == array[j]) {
                check4 = false;
                i = size;
                break;
            }
        }
    }
    return check4;
}

// The function to define the size of set, which is a result of the operation CROSSING

int cross2(int* arr1, int* arr2, int n1, int n2) {
    int cross2 = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                cross2++;
            }
        }
    }
    return cross2;
}

// The function, which fulfills the operation UNIT

void resunit(int* arr1, int* arr2, int n1, int n2) {
    int sizeofunit = n1 + n2 - cross2(arr1, arr2, n1, n2);
    int* unit = new int[sizeofunit];
    cout << "\nThe result of unit: { ";
    for (int f = 0; f <= n1; f++) {
        if (f < n1) {
            unit[f] = arr1[f];
            cout << unit[f] << " ";
        }
        else {
            for (int i = 0; i < n2; i++) {
                for (int j = 0; j < n1; j++) {
                    if (arr2[i] == arr1[j]) {
                        break;
                    }
                    if (j == (n1 - 1) && arr2[i] != arr1[j]) {
                        unit[f] = arr2[i];
                        cout << unit[f] << " ";
                        f++;
                    }
                }
            }
        }
    }
    cout << "}\n";
    delete[] unit;
}

// The function, which fulfills the operation CROSSING

void rescrossing(int* arr1, int* arr2, int n1, int n2) {
    int* crossing = new int[cross2(arr1, arr2, n1, n2)];
    if (cross2(arr1, arr2, n1, n2) > 0) {
        cout << "\nThe result of crossing: { ";
        for (int i = 0, f = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (arr1[i] == arr2[j]) {
                    crossing[f] = arr1[i];
                    cout << crossing[f] << " ";
                    f++;
                }
            }
        }
        cout << "}\n";
    }
    else {
        cout << "\nEmpty set\n";
    }
    delete[] crossing;
}

// The function, which fulfills the operation PRODUCT BETWEEN THE FIRST AND THE SECOND SETS

void resproduct1(int* arr1, int* arr2, int n1, int n2) {
    int size = 2 * n1 * n2;
    int* product1 = new int[size];
    int k = 0;
    cout << "\nThe result of cartesian product between the first and the second sets: { ";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++, k++) {
            product1[k] = arr1[i];
            k++;
            product1[k] = arr2[j];
            if (j == (n2 - 1) && i == (n1 - 1)) {
                cout << "<" << product1[k - 1] << "," << product1[k] << "> ";
            }
            else {
                cout << "<" << product1[k - 1] << "," << product1[k] << ">, ";
            }
        }
    }
    cout << "}\n";
    delete[] product1;
}

// The function, which fulfills the operation PRODUCT BETWEEN THE SECOND AND THE FIRST SETS

void resproduct2(int* arr1, int* arr2, int n1, int n2) {
    int size = 2 * n1 * n2;
    int* product2 = new int[size];
    int k = 0;
    cout << "\nThe result of cartesian product between the second and the first sets: { ";
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n1; j++, k++) {
            product2[k] = arr2[i];
            k++;
            product2[k] = arr1[j];
            if (j == (n1 - 1) && i == (n2 - 1)) {
                cout << "<" << product2[k - 1] << "," << product2[k] << "> ";
            }
            else {
                cout << "<" << product2[k - 1] << "," << product2[k] << ">, ";
            }
        }
    }
    cout << "}\n";
    delete[] product2;
}

// The function, which fulfills the operation COMPLEMENT OF THE FIRST SET

void rescomplement1(int* arr1, int* arr2, int* universe, int n1, int n2) {
    int sizec1 = 50 - n1;
    int* complement1 = new int[sizec1];
    int cross2 = 0;
    if (n1 == 50) {
        cout << "\nThe result of complement for the first set: Empty set\n";
    }
    else {
        cout << "\nThe result of complement for the first set: { ";
        for (int i = 0, f = -1; i < 50; i++) {
            for (int j = 0; j <= n1 - 1; j++) {
                if (universe[i] == arr1[j]) {
                    cross2++;
                }
            }
            if (cross2 == 0) {
                f++;
                complement1[f] = universe[i];
                cout << complement1[f] << " ";
            }
            cross2 = 0;
        }
        cout << "}\n";
    }
    delete[] complement1;
}

// The function, which fulfills the operation COMPLEMENT OF THE SECOND SET

void rescomplement2(int* arr1, int* arr2, int* universe, int n1, int n2) {
    int sizec2 = 50 - n2, cross2 = 0;
    int* complement2 = new int[sizec2];
    if (n2 == 50) {
        cout << "\nThe result of complement for the second set: Empty set\n";
    }
    else {
        cout << "\nThe result of complement for the first set: { ";
        for (int i = 0, f = -1; i < 50; i++) {
            for (int j = 0; j < n2; j++) {
                if (universe[i] == arr2[j]) {
                    cross2++;
                }
            }
            if (cross2 == 0) {
                f++;
                complement2[f] = universe[i];
                cout << complement2[f] << " ";
            }
            cross2 = 0;
        }
        cout << "}\n";
    }
    delete[] complement2;
}

// The function to define the size of set, which is a result of the operation DIFFERENCE BETWEEN THE FIRST AND THE SECOND SETS

int ressized12(int* arr1, int* arr2, int n1, int n2) {
    int sized12 = n1 - cross2(arr1, arr2, n1, n2);
    if (sized12 > 0) {
        return sized12;
    }
    else {
        sized12 = 0;
        return sized12;
    }
}

// The function to define the size of set, which is a result of the operation DIFFERENCE BETWEEN THE SECOND AND THE FIRST SETS

int ressized21(int* arr1, int* arr2, int n1, int n2) {
    int sized21 = n2 - cross2(arr1, arr2, n1, n2);
    if (sized21 > 0) {
        return sized21;
    }
    else {
        sized21 = 0;
        return sized21;
    }
}

// The function, which fulfills the operation DIFFERENCE BETWEEN THE FIRST AND THE SECOND SETS

void resdifference12(int* arr1, int* arr2, int n1, int n2) {
    int* difference12 = new int[ressized12(arr1, arr2, n1, n2)];
    if (ressized12(arr1, arr2, n1, n2) == 0) {
        cout << "\nThe result of difference between the first and the second sets: Empty set\n";
    }
    else {
        cout << "\nThe result of difference between the first and the second sets: { ";
        for (int i = 0, f = -1; i <= (n1 - 1); i++) {
            for (int j = 0; j <= (n2 - 1); j++) {
                if (arr1[i] == arr2[j])
                {
                    break;
                }
                if (j == (n2 - 1)) {
                    f++;
                    difference12[f] = arr1[i];
                    cout << difference12[f] << " ";
                }
            }
        }
        cout << "}\n";
    }
    delete[] difference12;
}

// The function, which fulfills the operation DIFFERENCE BETWEEN THE SECOND AND THE FIRST SETS

void resdifference21(int* arr1, int* arr2, int n1, int n2) {
    int* difference21 = new int[ressized21(arr1, arr2, n1, n2)];
    if (ressized21(arr1, arr2, n1, n2) == 0) {
        cout << "\nThe result of difference between the second and the first sets: Empty set\n";
    }
    else {
        cout << "\nThe result of difference between the second and the first sets: { ";
        for (int i = 0, f = -1; i <= (n2 - 1); i++) {
            for (int j = 0; j <= (n1 - 1); j++) {
                if (arr2[i] == arr1[j]) {
                    break;
                }
                if (j == (n1 - 1)) {
                    f++;
                    difference21[f] = arr2[i];
                    cout << difference21[f] << " ";
                }
            }
        }
        cout << "}\n";
    }
    delete[] difference21;
}

// The function, which fulfills the operation SYMETRICAL DIFFERENCE 

void ressymdifference(int* arr1, int* arr2, int n1, int n2) {
    int* differencesym12 = new int[ressized12(arr1, arr2, n1, n2) + ressized21(arr1, arr2, n1, n2)];
    if (ressized12(arr1, arr2, n1, n2) + ressized21(arr1, arr2, n1, n2) == 0) {
        cout << "\nThe result of symmetrical difference between the first and the second sets: Empty set\n";
    }
    else {
        cout << "\nThe result of symmetrical difference between the first and the second sets: { ";
        for (int i = 0, f = 0; f < (ressized12(arr1, arr2, n1, n2) + ressized21(arr1, arr2, n1, n2)); i++) {
            if (f < ressized12(arr1, arr2, n1, n2)) {
                for (int j = 0; j < n2; j++) {
                    if (arr1[i] == arr2[j]) {
                        break;
                    }
                    if (j == n2 - 1 && arr1[i] != arr2[j]) {
                        differencesym12[f] = arr1[i];
                        cout << differencesym12[f] << " ";
                        f++;
                    }
                }
            }
            else {
                for (int j = 0; j < n2; j++) {
                    for (int i = 0; i < n1; i++) {
                        if (arr1[i] == arr2[j]) {
                            break;
                        }
                        if (i == n1 - 1 && arr1[i] != arr2[j]) {
                            differencesym12[f] = arr2[j];
                            cout << differencesym12[f] << " ";
                            f++;
                        }
                    }
                }
            }
        }
        cout << "}\n";
    }
    delete[] differencesym12;
}

// The main function

int main() {
    string name;
    int n1 = check1("first");              //The first set
    int* arr1 = new int[n1];
    int ping = check2();
    int size = 0;
    int* array = arr1;
    if (ping == 1) {
        for (int i = 0, k = 1; i < n1; i++, k++) {
            arr1[i] = 2 * k - 1;
        }
    }
    else if (ping == 2) {
        do {
            for (int i = 0; i < n1; i++) {
                arr1[i] = check3(i);
            }
        } while (check4(arr1, n1) == false);
    }
    int n2 = check1("second");              //The second set
    ping = check2();
    int* arr2 = new int[n2];
    array = arr2;
    if (ping == 1) {
        for (int i = 0, k = 1; i < n2; i++, k++) {
            arr2[i] = 2 * k - 1;
        }
    }
    else if (ping == 2) {
        do {
            for (int i = 0; i < n2; i++) {
                arr2[i] = check3(i);
            }
        } while (check4(arr2, n2) == false);
    }
    int* universe = new int[50];
    int sum = 1;
    for (int i = 0; i < 50; i++) {
        universe[i] = sum;
        sum++;
    }
    string choice;                             //Operations 
    regex b3("([1-9]{1}|(10){1})");
    do {
        do {
            cout << "Which operation do you want to do?\n";
            cout << "1. Operation unit\n";
            cout << "2. Operation crossing\n";
            cout << "3. Operation cartesian product between the first and the second sets\n";
            cout << "4. Operation cartesian product between the second and the first sets\n";
            cout << "5. Operation complement for the first set\n";
            cout << "6. Operation complement for the second set\n";
            cout << "7. Operation difference between the first and the second sets\n";
            cout << "8. Operation difference between the second and the first sets\n";
            cout << "9. Operation symmetrical difference\n";
            cout << "10. All operations in row\n";
            getline(cin, choice);
        } while (!regex_match(choice, b3));
        switch (stoi(choice)) {
        case 1: {
            resunit(arr1, arr2, n1, n2);
            break;
        }
        case 2: {
            rescrossing(arr1, arr2, n1, n2);
            break;
        }
        case 3: {
            resproduct1(arr1, arr2, n1, n2);
            break;
        }
        case 4: {
            resproduct2(arr1, arr2, n1, n2);
            break;
        }
        case 5: {
            rescomplement1(arr1, arr2, universe, n1, n2);
            break;
        }
        case 6: {
            rescomplement2(arr1, arr2, universe, n1, n2);
            break;
        }
        case 7: {
            resdifference12(arr1, arr2, n1, n2);
            break;
        }
        case 8: {
            resdifference21(arr1, arr2, n1, n2);
            break;
        }
        case 9: {
            ressymdifference(arr1, arr2, n1, n2);
            break;
        }
        case 10: {
            resunit(arr1, arr2, n1, n2);
            rescrossing(arr1, arr2, n1, n2);
            resproduct1(arr1, arr2, n1, n2);
            resproduct2(arr1, arr2, n1, n2);
            rescomplement1(arr1, arr2, universe, n1, n2);
            rescomplement2(arr1, arr2, universe, n1, n2);
            resdifference12(arr1, arr2, n1, n2);
            resdifference21(arr1, arr2, n1, n2);
            ressymdifference(arr1, arr2, n1, n2);
            break;
        }
        }
        cout << "\nDo you want to make one more operation? Press y to continue or other key to exit\n";
        getline(cin, choice);
    } while (choice == "y");
    delete[] arr1;
    delete[] arr2;
    delete[] universe;
    return 0;
}
