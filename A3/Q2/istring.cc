#include "istring.h"
#include <cstring>
#include <locale>

using namespace std;

// iString(): Create an empty string (length is zero, chars is NULL)
iString::iString(): length(0), capacity(0) {
    chars = NULL;
}


// iString(a): Create a string initialized with the word a
iString::iString(const char *a) {
    int len = strlen(a);
    length = len;
    capacity = len;
    chars = new char[capacity+1];
    strcpy(chars,a);
}

/* iString(a): Call the copy constructor, initialize this contents
   to be a copy of the contents of a
 */
iString::iString(const iString &a) {
    length = a.length;
    capacity = a.capacity;
    chars = NULL;
    chars = new char[capacity+1];
    for (int i=0; i< length; i++) {
        chars[i] = a.chars[i];
    }
    chars[length] = '\0';
}

// ~iString(): destructor
iString::~iString() {
    delete [] chars;
}

// operator=(other): overload the assignment operator
iString &iString::operator=(const iString &other) {
    if (this == &other) return *this;
    char *tmp;
    if (other.capacity != 0) {
        tmp = new char[other.capacity+1];
    } else {
        tmp = NULL;
    }
    length = other.length;
    capacity = other.capacity;
    delete [] chars;
    chars = tmp;
    if (other.length == 0) {
        chars = NULL;
    } else {
        strcpy(chars,other.chars);
    }
    return *this;
}

// operator*(i,s): overload the multiplication opeator
iString operator*(const int i, const iString &s) {
    iString tmp;
    if (i == 0) {
        tmp.chars = NULL;
    } else {
        if (s.chars == NULL) {
            tmp.chars = NULL;
        } else {
            for (int j=0; j<i; j++) {
                tmp = tmp+s;
            }
        }
    }
    return tmp;
}

// operator+(s1,s2): overload the addition operator
iString operator+(const iString &s1, const iString &s2) {
    int l1 = s1.length;
    int l2 = s2.length;
    iString tmp;
    tmp.length = l1+l2;
    tmp.capacity = s1.capacity + s2.capacity;
    tmp.chars = new char[tmp.capacity+1];
    for (int i=0; i<l1; i++) {
        tmp.chars[i] = s1.chars[i];
    }
    for (int j=0; j<l2; j++) {
        tmp.chars[j+l1] = s2.chars[j];
    }
    tmp.chars[tmp.length] = '\0';
    return tmp;
}

// operator+(s1,s2): overload the addition operator
iString operator+(const iString &s1, const char *s2) {
    int l1 = s1.length;
    int l2 = strlen(s2);
    iString tmp;
    tmp.length = l1+l2;
    tmp.capacity = s1.capacity + l2;
    tmp.chars = new char[tmp.capacity+1];
    if ((s1.chars == NULL) && (s2 == NULL)) {
        tmp.chars = NULL;
    } else {
        for (int i=0; i<l1; i++) {
            tmp.chars[i] = s1.chars[i];
        }
        for (int j=0; j<=l2; j++) {
            tmp.chars[j+l1] = s2[j];
        }
        tmp.chars[tmp.length] = '\0';
    }
    return tmp;
}

// operator>>(in,d): overload the input operator
istream &operator>>(istream &in, iString &d) {
    bool is_in = false;
    while (true) {
        if (isspace(in.peek()) && (is_in == true)) {
            break;
        }
        char c;
        in >> c;
        if (in.eof()) {
            break;
        } else {
            if (!isspace(c)) {
                if (d.length == 0) {
                    d.capacity = 1;
                    d.chars = new char[d.capacity+1];
                } else if (d.length >= d.capacity) {
                    char *tmp = d.chars;
                    d.chars = new char[d.capacity*2+1];
                    for (int i=0; i<d.length; i++) {
                        d.chars[i] = tmp[i];
                    }
                    d.capacity = d.capacity*2;
                    delete [] tmp;
                }
                d.chars[d.length] = c;
                d.length++;
                is_in = true;
            }
        }
        d.chars[d.length] = '\0';
    }
    return in;
}

// operator<<(out,s): overload the output operator
ostream &operator<<(ostream &out, const iString &s) {
    for (int i=0; i<s.length; i++) {
        out << s.chars[i];
    }
    return out;
}


    
    
