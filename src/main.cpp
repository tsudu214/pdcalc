#include <iostream>

#include "Stack.h"

using pdCalc::Stack;

using namespace std;

void pp(const vector<double>& v)
{
    for (auto & x : v) {
        cout << " " << x;
    }
    cout << endl;
}

int main()
{
    Stack& S = Stack::Instance();
    S.push(1);
    vector<double> v = S.getElements(3);
    pp(v);  // 1

    S.push(2);
    S.push(3);
    S.swapTop();
    v = S.getElements(3);
    pp(v);  // 2 3 1

    return 0;
}