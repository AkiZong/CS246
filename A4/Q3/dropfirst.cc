#include "dropfirst.h"
#include <string>
#include <sstream>

using namespace std;


DropFirst::DropFirst(TextProcessor *tp1, int n): Decorator(tp1), n(n){}


void DropFirst::setSource(istream *is1) {
    Decorator::setSource(is1);
}


string DropFirst::getWord() {
    string tmp = Decorator::getWord();
    while ((n >= tmp.length()) &&
           (!Decorator::fail())) {
        tmp=Decorator::getWord();
    }
    if (n < tmp.length()) {
        tmp = tmp.substr(n,tmp.length()-n);
    }
    return tmp;
}


bool DropFirst::fail() const {
    return Decorator::fail();
}

DropFirst::~DropFirst() {}


