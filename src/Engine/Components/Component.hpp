#ifndef C_COMPONENT_HPP
#define C_COMPONENT_HPP

#include <string>
#include "../../Engine/Time.hpp"

class CComponent
{
    public:
    virtual void Update(Time time);
    virtual std::string TypeID()
    {
        return "CComponent";
    }
};

#endif