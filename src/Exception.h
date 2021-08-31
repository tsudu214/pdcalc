#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

namespace pdCalc {

class Exception
{
public:
    explicit Exception(const std::string& msg) : msg_(msg) {}
    const std::string& what() const { return msg_; }
    
private:
    std::string msg_;
};

};

#endif