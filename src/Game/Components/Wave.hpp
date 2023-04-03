#ifndef OWAVE_HPP
#define OWAVE_HPP

#include <vector>
#include "../../Engine/Systems/World/WorldObject.hpp"


class OWave : public WorldObject
{
  public:
    void Update(Time time) override
    {
      Position += time.DeltaTime * 2;
      
    }

    void Render(std::vector<CRGB>& leds) override
    {
       int pos = ((int)Position) % leds.size();
       leds[pos] = CRGB::Red;
    }
};

#endif