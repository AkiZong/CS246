#ifndef __ECHO_H__
#define __ECHO_H__
#include <iostream>
#include <string>
#include "textprocess.h"

/* concrete implementation of TextProcessor, which provides default behaviour: 
   it echoes the words in its input stream, one token at a time.
 */

class Echo: public TextProcessor {
    std::istream *source; //pointer to source
    bool failed; //if cant't get a word, return failed
 public:
    //Default constructor
    Echo();
    // setter for pointer of source word(s)
    void setSource(std::istream *inp);
    //getter for a word
    std::string getWord();
    //if can't get a word, return failed
    bool fail() const;
};

#endif
