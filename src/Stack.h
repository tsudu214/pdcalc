#ifndef STACK_H
#define STACK_H

#include <vector>
#include <deque>

class Stack
{
public:
    Stack() {};
    ~Stack() {};

    void push(double d);
    void getElements(size_t n, std::vector<double>& v) const;
    double pop();
    void swapTop();

private:
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    Stack(Stack&&) = delete;
    Stack&& operator=(Stack&&) = delete;

    std::deque<double> stack_;
};

#endif