#include "Observer.h"

namespace pdCalc {

Observer::Observer(const std::string& name)
: name_{name}
{ }

Observer::~Observer() = default;

void Observer::notify()
{
    notifyImpl();
}

};

