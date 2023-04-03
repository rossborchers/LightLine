#ifndef S_WORLD_HPP
#define S_WORLD_HPP

#include "../../Time.hpp"
#include "WorldObject.hpp"

class SWorld
{
    friend class SRenderer;
    
    public:

    void AddWorldObject(WorldObject* worldObject)
    {
        _worldObjects.push_back(worldObject);
    }

    void Update(Time time)
    {
        for(int i = 0; i < _worldObjects.size(); i++)
        {
            _worldObjects[i]->Update(time);
        }
    }

    void Clear()
    {
        for(int i = 0; i < _worldObjects.size(); i++)
        {
            delete _worldObjects[i];
        }
        _worldObjects.clear();
    }

    private:

    std::vector<WorldObject*> _worldObjects;
};


#endif