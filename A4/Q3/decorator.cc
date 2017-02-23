#include "decorator.h"

using namespace std;



Decorator::Decorator(TextProcessor *t) {
    tp = t;
}

void Decorator::setSource(istream *in) {
    tp->setSource(in);
}


string Decorator::getWord() {
    return tp->getWord();
}

bool Decorator::fail() const {
    return tp->fail();
}


Decorator::~Decorator() {
    delete tp;
}
