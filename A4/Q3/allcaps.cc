#include "allcaps.h"
#include <string>

using namespace std;

AllCaps::AllCaps(TextProcessor *tp3): Decorator(tp3) {}


void AllCaps::setSource(std::istream *is3) {
    Decorator::setSource(is3);
}


string AllCaps::getWord() {
    string tmp = Decorator::getWord();
    for (int i=0; i<tmp.length(); i++) {
        tmp[i] = toupper(tmp[i]);
    }
    return tmp;
}


bool AllCaps::fail() const {
    return Decorator::fail();
}


AllCaps::~AllCaps() {}


