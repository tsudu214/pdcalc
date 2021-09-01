#ifndef STACK_H
#define STACK_H

#include "Publisher.h"

#include <vector>
#include <memory>

namespace pdCalc {

class Stack : private Publisher
{
public:
    static Stack& Instance();
    void push(double d);
    // returns first min(n, stackSize) elements of the stack with the top of stack at position 0
    std::vector<double> getElements(size_t n) const;
    double pop();
    void swapTop();

    using Publisher::attach;
    using Publisher::detach;

private:
    Stack();
    ~Stack();

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    Stack(Stack&&) = delete;
    Stack&& operator=(Stack&&) = delete;

    class StackImpl;
    std::unique_ptr<StackImpl> pimpl_;
};

};

#endif