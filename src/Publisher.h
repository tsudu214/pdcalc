#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <unordered_map>
#include <memory>
#include <string>

namespace pdCalc {

class Observer;

class EventData
{
public:
    virtual ~EventData();
};

class Publisher
{
    using ObserverList = std::unordered_map<std::string, std::unique_ptr<Observer>>;
    using Events = std::unordered_map<std::string, ObserverList>;

public:
    Publisher();
    void attach(const std::string& eventName, std::unique_ptr<Observer> observer);
    std::unique_ptr<Observer> detach(const std::string& eventName, const std::string& observerName);

protected:
    ~Publisher();

    void raise(const std::string& eventName, std::shared_ptr<EventData> d) const;
    void registerEvent(const std::string& eventName);

private:
    Events::const_iterator findCheckedEvent(const std::string& eventName) const;
    Events::iterator findCheckedEvent(const std::string& eventName);

private:
    Events events_;
};

};

#endif