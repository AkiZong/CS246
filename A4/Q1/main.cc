#include "Expression.h"
#include "Integers.h"
#include "Binary.h"
#include "Unary.h"
#include <string>
#include <sstream>

using namespace std;

int main() {
    Expression *mystack[10];
    int count=0;
    string tmp;
    bool startyet = false;
    while (cin >> tmp) {
        if ((tmp == "ABS") || (tmp == "NEG")) {
            Expression *top1 = mystack[count-1];
            Unary u(tmp, mystack[count-1]);
            u.evaluate();
            u.prettyprint();
            mystack[count-1] = u.puna();
            delete top1;
        } else if ((tmp == "+") || (tmp == "-") ||
                   (tmp == "*") || (tmp == "/")) {
            Expression *e_tmp1 = mystack[count-1];
            Expression *top2 = mystack[count-1];
            mystack[count-1] = NULL;
            count--;
            Expression *e_tmp2 = mystack[count-1];
            Expression *top3 = mystack[count-1];
            mystack[count-1] = NULL;
            count--;
            Binary b(tmp, e_tmp2, e_tmp1);
            b.evaluate();
            b.prettyprint();
            count++;
            mystack[count-1] = b.pbin();
            delete top2;
            delete top3;
        } else {
            if (count == 10) {
                cerr << "Stack overflow" <<endl;
                return 1;
            }
            int val;
            stringstream ss(tmp);
            ss >> val;
            ostringstream oss;
            oss << val;
            tmp = oss.str();
            Expression *e_tmp3 = new Expression(val,tmp);
            mystack[count] = e_tmp3;
            count++;
            startyet = true;
        }
    }
    if (startyet) {
        mystack[count-1]->prettyprint();
        Expression *top4 = mystack[count-1];
        delete top4;
    }
}

