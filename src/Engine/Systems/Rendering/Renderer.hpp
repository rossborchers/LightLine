#ifndef S_RENDERER_HPP
#define S_RENDERER_HPP

#include <Arduino.h>
#include <FastLED.h>

#include "../World/World.hpp"

#define NUM_LEDS 20
#define DATA_PIN 2

class SRenderer 
{
    public:
    SRenderer();
    void Render(SWorld* world);

    private:

    CRGB leds[NUM_LEDS];
    CRGB::HTMLColorCode randoColors[8];
    CRGB::HTMLColorCode colors[NUM_LEDS];
    int offset = 0;
};

#endif