#ifndef OBSERVER_H
#define OBSERVER_H

#include <memory>
#include <string>

namespace pdCalc {

class EventData;

class Observer
{
public:
    explicit Observer(const std::string& name);
    virtual ~Observer();

    void notify(std::shared_ptr<EventData> d);

    const std::string name() const { return name_; }

private:
    virtual void notifyImpl(std::shared_ptr<EventData> d) = 0;

    std::string name_;
};

};

#endif