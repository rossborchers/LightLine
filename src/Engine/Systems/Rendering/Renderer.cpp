#include "Renderer.hpp"

SRenderer::SRenderer()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

    randoColors[0] = CRGB::Red;
    randoColors[1] = CRGB::Orange;
    randoColors[2] = CRGB::Yellow;
    randoColors[3] = CRGB::Purple;
    randoColors[4] = CRGB::Blue;
    randoColors[5] = CRGB::LawnGreen;
    randoColors[6] = CRGB::Pink;
    randoColors[7] = CRGB::BlueViolet;

    int r = 0;
    for(int i = 0; i < NUM_LEDS; i++)
    {
        colors[i]= randoColors[r%8];
        r++;
    }
}

void SRenderer::Render(SWorld* world)
{
    for(int i = 0; i < NUM_LEDS; i++) 
    {
        int colorIndex = (i+offset) % NUM_LEDS;
        leds[i] = colors[colorIndex];
    }
    FastLED.show();

    offset++;
}