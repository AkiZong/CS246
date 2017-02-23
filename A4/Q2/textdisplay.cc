#include "textdisplay.h"
using namespace std;


TextDisplay::TextDisplay(int n): View(n) {
    theDisplay = new char*[n*n];
    for (int i=0;i<n*n;i++){
        theDisplay[i]=new char;
        *theDisplay[i]='0';
    }
}


TextDisplay::~TextDisplay() {
    for (int i=0; i<gridSize*gridSize; i++) {
        delete theDisplay[i];
    }
    delete [] theDisplay;
}


void TextDisplay::notify(int r, int c, char ch) {
    if ((r>=0) && (r<gridSize) &&
        (c>=0) && (c<gridSize) &&
        (ch >= 48) && (ch <= 52)) {
        *theDisplay[r*gridSize+c]=ch;
    }
}


void TextDisplay::print(std::ostream &out) {
    for (int i=0;i<gridSize*gridSize;i++){
        if((i+1)%gridSize){
            out<<*theDisplay[i];
        }else{
            out<<*theDisplay[i]<<endl;
        }
    }
}

