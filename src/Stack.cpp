#include "Stack.h"

#include <deque>

using namespace std;

namespace pdCalc {

class Stack::StackImpl
{
public:
    void push(double d);
    double pop();
    void swapTop();
    void getElements(size_t n, vector<double>& v) const;

private:
    deque<double> stack_;
};

void Stack::StackImpl::push(double x)
{
    stack_.push_back(x);
}

void Stack::StackImpl::getElements(size_t n, std::vector<double>& v) const
{
    v.clear();
    if (stack_.size() < n) { // get all elements for smaller stack
        n = stack_.size();
    }
    v.insert(v.end(), stack_.rbegin(), stack_.rbegin() + n);
}

double Stack::StackImpl::pop()
{
    if (stack_.empty()) {
        throw "No elements!";
    }
    double x = stack_.back();
    stack_.pop_back();
    return x;
}

void Stack::StackImpl::swapTop()
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

Stack& Stack::Instance()
{
    static Stack instance;
    return instance;
}

void Stack::push(double x)
{
    pimpl_->push(x);
}

void Stack::getElements(size_t n, std::vector<double>& v) const
{
    pimpl_->getElements(n, v);
}

double Stack::pop()
{
    return pimpl_->pop();
}

void Stack::swapTop()
{
    pimpl_->swapTop();
}

Stack::Stack()
{
    pimpl_ = make_unique<StackImpl>();
}

Stack::~Stack() {}

};