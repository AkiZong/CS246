#include "doublewords.h"
#include <string>

using namespace std;

DoubleWords::DoubleWords(TextProcessor *tp2): Decorator(tp2),index(0),s("") {}


void DoubleWords::setSource(std::istream *is2) {
    Decorator::setSource(is2);
}


string DoubleWords::getWord() {
    if(!index){
        s=Decorator::getWord();
        index++;
    }else{
        index=0;
    }
    return s;
}


bool DoubleWords::fail() const {
    return Decorator::fail();
}


DoubleWords::~DoubleWords() {}


