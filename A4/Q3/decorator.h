#ifndef __DECORATOR_H__
#define __DECORATOR_H__
#include <iostream>
#include <string>
#include "textprocess.h"

// Decorator is a decorator of TextProcessor

class Decorator: public TextProcessor {
    // pointer to TextProcessor
    TextProcessor *tp;
public:
    // Default Constructor
    Decorator(TextProcessor *t);
    // setter for pointer of source word(s)
    void setSource(std::istream *is1);
    // getter for a word
    std::string getWord();
    // if cant't get a word, return failed
    bool fail() const;
    // destructor
    ~Decorator();
};

#endif

