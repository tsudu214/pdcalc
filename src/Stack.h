#ifndef STACK_H
#define STACK_H

#include <vector>
#include <memory>

namespace pdCalc {

class Stack
{
    class StackImpl;
public:
    static Stack& Instance();
    void push(double d);
    void getElements(size_t n, std::vector<double>& v) const;
    double pop();
    void swapTop();

private:
    Stack();
    ~Stack();

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    Stack(Stack&&) = delete;
    Stack&& operator=(Stack&&) = delete;

    std::unique_ptr<StackImpl> pimpl_;
};

};

#endif