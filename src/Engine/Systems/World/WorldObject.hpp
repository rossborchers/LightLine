#ifndef WORLD_OBJECT_HPP
#define WORLD_OBJECT_HPP

#define DEFAULT_COMPONENT_RESERVED_COUNT 8

#include <vector>
#include <FastLED.h>

class WorldObject 
{
    friend class SWorld;

    public:
    float Position;

    virtual void Update(Time time) = 0;
    virtual void Render(std::vector<CRGB>& leds) = 0;
};

#endif