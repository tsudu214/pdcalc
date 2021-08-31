#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <unordered_map>
#include <memory>
#include <string>

namespace pdCalc {

class Observer;

class Publisher
{
public:
    void attach(const std::string& eventName, std::unique_ptr<Observer> observer);
    std::unique_ptr<Observer> detach(const std::string& eventName, const std::string& observerName);

private:
    using ObserverList = std::unordered_map<std::string, std::unique_ptr<Observer>>;
    using Events = std::unordered_map<std::string, ObserverList>;
    Events events_;
};

};

#endif