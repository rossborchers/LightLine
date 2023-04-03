#ifndef S_RENDERER_HPP
#define S_RENDERER_HPP

#include <Arduino.h>
#include <FastLED.h>
#include <vector>
#include "../World/World.hpp"

#define DATA_PIN 2

class SRenderer 
{
    public:
    
    SRenderer(int ledStripLength)
    {
        _leds.resize(ledStripLength);
        FastLED.addLeds<WS2812B, DATA_PIN, GRB>(&_leds[0], ledStripLength);
        Clear(CRGB::Black);
    }

    void Render(SWorld* world)
    {
        Clear(CRGB::Green);

        for(int i = 0; i < world->_worldObjects.size(); i++) 
        {
           world->_worldObjects[i]->Render(_leds);
        }

        FastLED.show();
    }

    
    private:

    void Clear(CRGB color)
    {
        for(int i = 0; i < _leds.size(); i++)
        {
            _leds[i] = color;
        }
    }

    std::vector<CRGB> _leds;
};

#endif