#include "Publisher.h"
#include "Observer.h"
#include "Exception.h"

#include <unordered_map>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

namespace pdCalc {

EventData::~EventData()
{ }

Publisher::Publisher()
{ }

Publisher::~Publisher()
{
    // std::unique_ptr requires a definition of the destructor instead
    // of using the default because the destructor must appear in a scope
    // in which the complete definition of the template argument for
    // std::unique_ptr is known
}

void Publisher::attach(const string& eventName, unique_ptr<Observer> observer)
{
    auto ev = findCheckedEvent(eventName);
    auto& obsList = ev->second;

    auto obs = obsList.find(observer->name());
    if ( obs != obsList.end() )
        throw Exception("Observer already attached to publisher");   

    obsList.insert( std::make_pair(observer->name(), std::move(observer)) );
}

unique_ptr<Observer> Publisher::detach(const string& eventName, const string& observerName)
{
    auto ev = findCheckedEvent(eventName);
    auto& obsList = ev->second;
    
    auto obs = obsList.find(observerName);
    if ( obs == obsList.end() )
        throw Exception("Cannot detach observer because observer not found");

    auto tmp = std::move(obs->second);
    obsList.erase(obs);

    return tmp;
}

void Publisher::raise(const string& eventName, shared_ptr<EventData> d) const
{
    auto ev = findCheckedEvent(eventName);
    const auto& obsList = ev->second;
    
    for (const auto& obs : obsList)
        obs.second->notify(d);
}

void Publisher::registerEvent(const string& eventName)
{
    auto i = events_.find(eventName);
    if ( i != events_.end() )
        throw Exception{"Event already registered"};
    
    events_[eventName] = Publisher::ObserverList{};
}

Publisher::Events::const_iterator Publisher::findCheckedEvent(const string& eventName) const
{
    auto ev = events_.find(eventName);
    if ( ev == events_.end() )
    {
        ostringstream oss;
        oss << "Publisher does not support event '" << eventName << "'";
        throw Exception( oss.str() );
    }
    return ev;
}

Publisher::Events::iterator Publisher::findCheckedEvent(const string& eventName)
{
    auto ev = events_.find(eventName);
    if ( ev == events_.end() )
    {
        ostringstream oss;
        oss << "Publisher does not support event '" << eventName << "'";
        throw Exception( oss.str() );
    }
    return ev;
}


};


