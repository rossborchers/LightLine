#ifndef WORLD_OBJECT_HPP
#define WORLD_OBJECT_HPP

#define DEFAULT_COMPONENT_RESERVED_COUNT 8

#include <vector>
#include <string>

#include "../../Components/Component.hpp"

class WorldObject 
{
    friend class SWorld;

    public:

    CComponent* WorldObject::GetComponent(std::string cTypeId)
    {
        for(int i = 0; i < _components.size(); i++)
        {
            if (cTypeId == _components[i]->TypeID()) 
            {
                return _components[i];
            }
        }
        return nullptr;
    }

    CComponent* WorldObject::AddComponent(CComponent* component)
    {
        _components.push_back(component);
        return component;
    }
    
    ~WorldObject()
    {
        for(int i = 0; i < _components.size(); i++)
        {
            delete _components[i];
        }
        _components.clear();
    }

    private:  
    
    WorldObject()
    {
        _components.reserve(DEFAULT_COMPONENT_RESERVED_COUNT);
    }

    std::vector<CComponent*> _components;
};

#endif