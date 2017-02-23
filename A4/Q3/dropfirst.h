#ifndef __DROPFIRST_H_
#define __DROPFIRST_H_
#include "decorator.h"
#include "textprocess.h"

/* DropFirst is a concrete decorator of Decorator to drop the first n 
   characters of each word. If n is greater than the length of some 
   word, the entire word is dropped (though the following word is not
   affected.)
 */

class DropFirst: public Decorator {
    int n; // need to drop first n character(s}
public:
    // Default Constructor
    DropFirst(TextProcessor *tp1, int n);
    // setter for pointer of source word(s)
    void setSource(std::istream *is1);
    // getter for a word
    std::string getWord();
    // if can't get a word, return failed
    bool fail() const;
    // destructor
    ~DropFirst();
};

#endif


