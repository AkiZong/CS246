#include "count.h"
#include <string>
#include <sstream>

using namespace std;

Count::Count(TextProcessor *tp4, char c): Decorator(tp4), c(c), count(1) {}


void Count::setSource(std::istream *is4) {
    Decorator::setSource(is4);
}


string Count::getWord() {
    string tmp = Decorator::getWord();
    string result;
    for (int i=0; i<tmp.length(); i++) {
        if (tmp[i] == c) {
            ostringstream oss;
            oss << count;
            result = result + oss.str();
            count++;
        } else {
            result = result + tmp[i];
        }
    }
    return result;
}


bool Count::fail() const {
    return Decorator::fail();
}

Count::~Count() {}

