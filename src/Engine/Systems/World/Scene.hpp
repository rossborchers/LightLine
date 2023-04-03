#ifndef SCENE_HPP
#define SCENE_HPP

#include "World.hpp"

class Scene
{
  public:
   virtual void Construct(SWorld* world);
};

#endif