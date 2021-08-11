#include <iostream>

#include "Stack.h"

using namespace std;

void pp(const vector<double>& v)
{
    bool first = true;
    for (auto & x : v) {
        if (!first) cout << " ";
        first = false;
        cout << x;
    }
    cout << endl;
}

int main()
{
    Stack S;
    S.push(1);
    vector<double> v;
    S.getElements(3, v);
    pp(v);  // 1

    S.push(2);
    S.push(3);
    S.swapTop();
    S.getElements(3, v);
    pp(v);  // 2 3 1

    return 0;
}