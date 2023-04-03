#include <Arduino.h>

#include "Engine/Systems/Rendering/Renderer.hpp"
#include "Engine/Systems/World/World.hpp"
#include "Engine/Time.hpp"


#include "Game/WaveScene.hpp"

//Systems
SRenderer* _renderer = nullptr;
SWorld* _world = nullptr;
Scene* _activeScene = nullptr;

unsigned long _currentMicros;
unsigned long _lastMicros;


void SetScene(Scene* scene)
{
  if(_activeScene != nullptr)
  {
    delete _activeScene;
  }

  _world->Clear();
  _activeScene = scene;
  _activeScene->Construct(_world);
}

void setup() 
{
  //Setup systems
  _renderer = new SRenderer();
  _world = new SWorld();
 
  //Init time for first loop
  _currentMicros = micros();

  SetScene(new WaveScene());
}

void loop() 
{
    //Calculate time and delta time
    Time time;
    _lastMicros = _currentMicros;
    _currentMicros = micros(); 
    unsigned long deltaMicros = _lastMicros - _currentMicros;
    time.DeltaTime = deltaMicros / (double)1000000;
    time.Time = _currentMicros / (double)1000000;

    _world->Update(time);
    _renderer->Render(_world);
}