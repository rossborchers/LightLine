#ifndef WAVE_SCENE_HPP
#define WAVE_SCENE_HPP

#include "Engine/Systems/World/Scene.hpp"

#include "Components/Wave.hpp"

class WaveScene : public Scene
{
    public:
     void Construct(SWorld* world) override
     {
        OWave* wave = new OWave();
        world->AddWorldObject(wave);
     }
};

#endif