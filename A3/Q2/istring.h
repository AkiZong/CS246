#ifndef __ISTRING_H__
#define __ISTRING_H__
#include <iostream>

/* iString is a class to implement the undefined constructors and destructors 
   for the iString type. Further, it will overload the input, output,
   assignment, addition, and multiplication operators
 */
struct iString {
    char * chars;
    unsigned int length;
    unsigned int capacity;
    iString();
    iString(const char *);
    iString(const iString&);
    ~iString();
    iString& operator=(const iString&);
};

// Add other declarations here:

// operator*(int,iString&): Multiply an iString by an integer scalar
iString operator*(const int, const iString &);

// operator+(iString&, iString&): Concatenate two iString
iString operator+(const iString &, const iString &);

// operator+(iString&, char *): Concatenate an iString and one word
iString operator+(const iString &, const char *);

// operator<<(ostream&, iString&): Print iStrings to stdout
std::ostream &operator<<(std::ostream &, const iString &);

// operator>>(istream&, iString&): Read in whitespace-delimited strings from stdin
std::istream &operator>>(std::istream &, iString &);



#endif

