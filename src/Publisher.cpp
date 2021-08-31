#include "Publisher.h"
#include "Observer.h"
#include "Exception.h"

#include <unordered_map>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

namespace pdCalc {

void Publisher::attach(const string& eventName, unique_ptr<Observer> observer)
{
    auto ev = events_.find(eventName);
    if ( ev == events_.end() )
    {
        ostringstream oss;
        oss << "Publisher does not support event '" << eventName << "'";
        throw Exception( oss.str() );
    }

    auto& obsList = ev->second;

    auto obs = obsList.find(observer->name());
    if ( obs != obsList.end() )
        throw Exception("Observer already attached to publisher");   

    obsList.insert( std::make_pair(observer->name(), std::move(observer)) );
}

unique_ptr<Observer> Publisher::detach(const string& eventName, const string& observerName)
{
    auto ev = events_.find(eventName);
    if ( ev == events_.end() )
    {
        ostringstream oss;
        oss << "Publisher does not support event '" << eventName << "'";
        throw Exception( oss.str() );
    }

    auto& obsList = ev->second;
    
    auto obs = obsList.find(observerName);
    if( obs == obsList.end() )
        throw Exception("Cannot detach observer because observer not found");

    auto tmp = std::move(obs->second);
    obsList.erase(obs);

    return tmp;
}

};


