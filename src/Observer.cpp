#include "Observer.h"
#include "Publisher.h"

namespace pdCalc {

Observer::Observer(const std::string& name)
: name_{name}
{ }

Observer::~Observer() = default;

void Observer::notify(std::shared_ptr<EventData> d)
{
    notifyImpl(d);
}

};

