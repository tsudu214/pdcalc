#include <iostream>

#include "Stack.h"
#include "Observer.h"
#include "Exception.h"

using pdCalc::Stack;

using namespace std;

namespace pdCalc {
class StackObserver : public Observer
{
public: 
    StackObserver() : Observer("stackObserver")
    {
    }
private:
    void notifyImpl(std::shared_ptr<EventData> d)
    {
        shared_ptr<StackEventData> p = dynamic_pointer_cast<StackEventData>(d);
        if (p) {
            cout << p->message() << endl;
        } else {
            throw Exception {"Invalid event dataa"};
        }
    }
};

};

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
    S.attach(Stack::StackError, make_unique<pdCalc::StackObserver>());

    try {
        S.pop(); // Observer detect error
    } catch (pdCalc::Exception& e) {
        cout << "Exception " << e.what() << endl;
    }

    S.push(1);
    vector<double> v = S.getElements(3);
    pp(v);  // 1

    try {
        S.swapTop(); // Observer detect error
    } catch (pdCalc::Exception& e) {
        cout << "Exception " << e.what() << endl;
    }

    S.push(2);
    S.push(3);
    S.swapTop();
    v = S.getElements(3);
    pp(v);  // 2 3 1

    return 0;
}