#include "Integers.h"
#include <string>

using namespace std;

Integers::Integers(int i, string s): Expression(i,s) {}

void Integers::prettyprint() {
    cout << formu << endl;
    cout << "= " << value << endl;
}

void Integers::evaluate() {
    cout << value << endl;
}


