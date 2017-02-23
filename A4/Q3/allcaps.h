#ifndef __ALLCAPS_H_
#define __ALLCAPS_H_
#include "decorator.h"
#include "textprocess.h"

/* AllCaps is a concrete decorator of Decorator to make all letters in 
   the string are presented in uppercase. Other characters remain unchanged.
*/

class AllCaps: public Decorator {
public:
    // Default Constructor
    AllCaps(TextProcessor *tp3);
    // setter for pointer of source word(s)
    void setSource(std::istream *is3);
    // getter for a word
    std::string getWord();
    // if can't get a word, return failed
    bool fail() const;
    // destructor
    ~AllCaps();
};

#endif


