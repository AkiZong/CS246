#ifndef __COUNT_H_
#define __COUNT_H_
#include "decorator.h"
#include "textprocess.h"

/* Count is a concrete decorator of Decorator. The effect is the first occurrence 
   of the character c in the string is replaced with 1. The second is replaced with
   2, ... the tenth is replaced with 10, and so on.
 */

class Count: public Decorator {
    char c;  // charater c to find all the same charactehr in a word
    int count; //count is to fingure how many same characters in a word
public:
    // Default Constructor
    Count(TextProcessor *tp4, char c);
    // setter for pointer of source word(s)
    void setSource(std::istream *is4);
    // getter for a word
    std::string getWord();
    // if can't get a word, return failed
    bool fail() const;
    // destructor
    ~Count();
};

#endif


