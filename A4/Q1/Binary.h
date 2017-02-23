#ifndef __BINARY_H__
#define __BINARY_H__
#include "Expression.h"
#include "Integers.h"

/* Binary is a subclass of Expression, where a binary operation (+, -, *, or /)
   applied to two expressions
 */

class Binary: public Expression {
    Expression *bin1; //bin1 is a pointer to an Expression
    Expression *bin2; //bin2 is a pointer to an Expression
public:
    // Constructor
    Binary(std::string k, Expression *b1, Expression *b2);
    // Destructor
    ~Binary();
    // // get the final denotation of an expression
    void prettyprint();
    // get the final result(value) of an expression
    void evaluate();
    // return a pointer of a binary expression
    Expression *const pbin();
};

#endif


