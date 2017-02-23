#ifndef __INTEGERS_H__
#define __INTEGERS_H__
#include "Expression.h"

// Integers is a subclass of Expression, where represent lone integers

class Integers: public Expression {
public:
    // Constructor
    Integers(int, std::string);
    // get the final denotation of an expression
    void prettyprint();
    // get the final result(value) of an expression
    void evaluate();
};

#endif


