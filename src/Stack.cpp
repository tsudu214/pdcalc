#include "Stack.h"

using namespace std;

void Stack::push(double x)
{
    stack_.push_back(x);
}

void Stack::getElements(size_t n, std::vector<double>& v) const
{
    v.clear();
    if (stack_.size() < n) { // get all elements for smaller stack
        n = stack_.size();
    }
    v.insert(v.end(), stack_.rbegin(), stack_.rbegin() + n);
}

double Stack::pop()
{
    if (stack_.empty()) {
        throw "No elements!";
    }
    double x = stack_.back();
    stack_.pop_back();
    return x;
}

void Stack::swapTop()
{
    if (stack_.size() < 2) {
        throw "insufficient elements!";
    }
    double first = stack_.back();
    stack_.pop_back();
    double second = stack_.back();
    stack_.pop_back();
    stack_.push_back(first);
    stack_.push_back(second);
}
