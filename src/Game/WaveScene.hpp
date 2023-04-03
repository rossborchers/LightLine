#ifndef WAVE_SCENE_HPP
#define WAVE_SCENE_HPP

#include "Engine/Systems/World/Scene.hpp"

#include "Components/Wave.hpp"

class WaveScene : public Scene
{
    public:
     void Construct(SWorld* world) override
     {
        WorldObject* waveObj = world->CreateWorldObject();
        CWave* wave = (CWave*)waveObj->AddComponent(new CWave());
     }
};

#endif