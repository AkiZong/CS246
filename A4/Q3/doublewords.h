#ifndef __DOUBLEWORDS_H_
#define __DOUBLEWORDS_H_
#include "decorator.h"
#include "textprocess.h"

/* DoubleWords is a concrete decorator of Decorator and it is to double 
   up all words in the string.
*/

class DoubleWords: public Decorator {
    int index; // index is a controller
    std::string s; //s is a word
public:
    // Default Constructor
    DoubleWords(TextProcessor *tp2);
    // setter for pointer of source word(s)
    void setSource(std::istream *is2);
    // getter for a word
    std::string getWord();
    // if can't get a word. return failed
    bool fail() const;
    // destructor
    ~DoubleWords();
};

#endif


