#include<iostream>
#include<cmath>
#include<string>
#include<regex>
using namespace std;
double check(char);
int main() {
    double x,y,z,t,k;
    k = check('k');
    z = check('z');
    if (k < 1) {
        x = k * pow(z, 3);
        cout << "The calculation was held on the way 1\n";
    }
    else {
        x = z * (z + 1);
        cout << "The calculation was held on the way 2\n";
    }
    t = log(1 + pow(x, 2)) + cos(x + 1);
    y = pow(t, exp(k * x));
    cout << y << endl;
    return 0;
}
double check(char type) {
    string foo;
    regex b("^[-]?[0-9]+[.]?[0-9]*$");
    regex b1("^[-]?[0-9]+[.]{1}$");
    do {
        cout << "Enter the meaning of " << type << "\n";
        getline(cin, foo);
    } while (!regex_match(foo, b) || regex_match(foo, b1));
    return stod(foo);
}