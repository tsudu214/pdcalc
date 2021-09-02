#include "Stack.h"
#include "Exception.h"

#include <deque>

using namespace std;

namespace pdCalc {

const string Stack::StackError = "error";

const char* StackEventData::Message(StackEventData::ErrorCondition e)
{
    switch (e)
    {
    case ErrorCondition::Empty: 
        return "Attempting to pop empty stack";
    case ErrorCondition::TooFewArguments: 
        return "Need at least two stack elements to swap top";
    default: 
        return "Unknown error";
    };
}

const char* StackEventData::message() const
{
    return Message( err_ );
}

class Stack::StackImpl
{
public:
    explicit StackImpl(const Stack&);
    void push(double d);
    double pop();
    void swapTop();
    void getElements(size_t n, vector<double>& v) const;
    size_t size() const;
    void clear();

private:
    const Stack& parent_; // for raising events
    deque<double> stack_;
};

Stack::StackImpl::StackImpl(const Stack& s) : parent_(s) 
{ }

void Stack::StackImpl::push(double x)
{
    stack_.push_back(x);
}

void Stack::StackImpl::getElements(size_t n, vector<double>& v) const
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
        parent_.raise( Stack::StackError, make_shared<StackEventData>(StackEventData::ErrorCondition::Empty) );
        throw Exception{ StackEventData::Message(StackEventData::ErrorCondition::Empty) };
    }
    double x = stack_.back();
    stack_.pop_back();
    return x;
}

void Stack::StackImpl::swapTop()
{
    if (stack_.size() < 2) {
        parent_.raise( Stack::StackError, make_shared<StackEventData>(StackEventData::ErrorCondition::TooFewArguments) );
        throw Exception{ StackEventData::Message(StackEventData::ErrorCondition::TooFewArguments) };
    }
    double first = stack_.back();
    stack_.pop_back();
    double second = stack_.back();
    stack_.pop_back();
    stack_.push_back(first);
    stack_.push_back(second);
}

size_t Stack::StackImpl::size() const
{
    return stack_.size();
}

void Stack::StackImpl::clear()
{
    stack_.clear();
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

vector<double> Stack::getElements(size_t n) const
{
    vector<double> v;
    pimpl_->getElements(n, v);
    return v;
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
: pimpl_{ make_unique<StackImpl>(*this) }
{ 
    registerEvent(StackError);
}

Stack::~Stack() = default;

};