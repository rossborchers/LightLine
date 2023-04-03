#ifndef CWAVE_HPP
#define CWAVE_HPP

#include <string>
#include "../../Engine/Components/Component.hpp"

class CWave : public CComponent
{
  public:
    void Update(Time time) override
    {
      
    }

    std::string TypeID() override
    {
        return "CWave";
    }
};

#endif