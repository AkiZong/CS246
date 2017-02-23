#include "Unary.h"
#include "Integers.h"
#include "Expression.h"
#include <string>
#include <cstdlib>

using namespace std;

Unary::Unary(string s, Expression *u1): Expression(s),
una(new Expression(u1->i_result(), u1->s_result())) {}

Unary::~Unary() {
    delete una;
}

void Unary::prettyprint() {
    if (formu == "ABS") {
        formu = "|" + una->s_result();
        formu = formu + "|";
    } else if (formu == "NEG") {
        formu = "-" + una->s_result();
    }
}

void Unary::evaluate() {
    if (formu == "ABS") {
        if (una->i_result() < 0) {
            value = -una->i_result();
        }else{
            value = una->i_result();
        }
    } else if (formu == "NEG") {
        value = -una->i_result();
    }
}


Expression *const Unary::puna() {
    Expression *puna = new Expression(value,formu);
    return puna;
}


