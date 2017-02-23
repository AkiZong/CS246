#include "Expression.h"
#include <string>
#include <sstream>

using namespace std;


Expression::Expression(string s): formu(s) {
    istringstream ss(s);
    ss >> value;
}

Expression::Expression(int i, string s): value(i), formu(s) {}


void Expression::setupint(int i) {
    value = i;
}

void Expression::setupstring(string s) {
    formu = s;
}

int Expression::i_result() {
    return value;
}

string Expression::s_result() {
    return formu;
}

Expression::~Expression () {}

void Expression::prettyprint() {
    cout << formu << endl;
    cout << "= " << value << endl;
}

void Expression::evaluate() {}


