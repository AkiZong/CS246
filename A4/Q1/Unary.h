#ifndef __UNARY_H__
#define __UNARY_H__
#include "Expression.h"
#include "Integers.h"

/* Unary is a subclass of Expression, where a unary operation
   (NEG or ABS, denoting negation and absolute value) applied
   to an expression
 */

class Unary: public Expression {
    Expression *una; // una is a pointer to Expression
public:
    // Constructor
    Unary(std::string s, Expression *u1);
    // Destructor
    ~Unary();
    // get the final denotation of an expression
    void prettyprint();
    // get the final result(value) of an expression
    void evaluate();
    // return a pointer of an unary expression
    Expression * const puna();
};

#endif


