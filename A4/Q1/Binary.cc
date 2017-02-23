#include "Binary.h"
#include "Integers.h"
#include <string>
#include <cstdlib>

using namespace std;

Binary::Binary(string s, Expression *b1, Expression *b2):
Expression(s),
bin1(new Expression (b1->i_result(),b1->s_result())),
bin2(new Expression (b2->i_result(),b2->s_result())) {}

Binary::~Binary() {
    delete bin1;
    delete bin2;
}

void Binary::prettyprint() {
    string tmp;
    tmp = "(" + bin1->s_result();
    tmp = tmp + " ";
    tmp = tmp + formu;
    tmp = tmp + " ";
    tmp = tmp + bin2->s_result();
    tmp = tmp + ")";
    formu = tmp;
}


void Binary::evaluate() {
    if (formu == "+") {
        value = bin1->i_result() + bin2->i_result();
    } else if (formu == "-") {
        value = bin1->i_result() - bin2->i_result();
    } else if (formu == "*") {
        value = bin1->i_result() * bin2->i_result();
    } else if (formu == "/") {
        value = bin1->i_result() / bin2->i_result();
    }
}

Expression *const Binary::pbin() {
    Expression *pbin = new Expression(value, formu);
    return pbin;
}


