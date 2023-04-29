#include<iostream>
#include<cmath>
#include<string>
#include<regex>
using namespace std;
int main() {
    string foo;
    regex b("^[-]?[0-9]+[.]?[0-9]*$");
    regex b1("^[-]?[0-9]+[.]{1}$");
    do {
        cout << "Enter the meaning of z\n";
        getline(cin, foo);
    } while (!regex_match(foo, b) || regex_match(foo, b1));
    double x=0, f=0, y=0, z=0;
    z = stod(foo);
    if (z < 1) {
        x = pow(z, 2);
        cout << "The calculation was held on the branch 1\n";
    }
    else {
        x = z + 1;
        cout << "The calculation was held on the branch 2\n";
    }
    string d1;
    regex b2("[1-3]{1}");
    do {
        cout << "Input the number of function which you want to use for calculating\n";
        cout << "1. 2x\n";
        cout << "2. x to the power of 2\n";
        cout << "3. x/3\n";
        getline(cin, d1);

    } while (!regex_match(d1, b2));
    int d = stoi(d1);
    switch (d) {
    case 1: f = 2 * x;
        cout << "The calculation was held with function 1\n";
        break;
    case 2: f = pow(x, 2);
        cout << "The calculation was held with function 2\n";
        break;
    case 3: f = x / 3;
        cout << "The calculation was held with function 3\n";
        break;
    }
    double intpart, fractpart;
    fractpart = modf(f+1, &intpart);
    y = log(1 + pow(x, 0.2)) + pow(cos(intpart), 2);
    cout << "The calculated meaning: a*" << y;
    return 0;
}