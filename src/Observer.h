#ifndef OBSERVER_H
#define OBSERVER_H

#include <memory>
#include <string>

namespace pdCalc {

class Observer
{
public:
    explicit Observer(const std::string& name);
    virtual ~Observer();

    void notify();

    const std::string name() const { return name_; }

private:
    virtual void notifyImpl() = 0;

    std::string name_;
};

};

#endif