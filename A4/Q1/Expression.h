#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
#include <iostream>

/* Expression is a base class which will be entered in reverse Polish notation(RPN),
   as known as postfix notation, in which the operator is written after its operands
 */

class Expression {
protected:
    int value; //value is the value result of an expression
    std::string formu; // formu is to denote an expression
    
public:
    // Constructor
    Expression(std::string s);
    // Construcor
    Expression(int i, std::string s);
    // Destructor
    virtual ~Expression ();
    // get the final denotation of an expression
    virtual void prettyprint();
    // get the final result(value) of an expression
    virtual void evaluate();
    // setter for a string to an expression
    void setupstring(std::string s);
    // setter for a value of an expression
    void setupint(int i);
    // return the value result of an expression
    int i_result();
    // return the denotation of an expression
    std::string s_result();
};

#endif

