#ifndef S_WORLD_HPP
#define S_WORLD_HPP

#include "../../Components/Transform.hpp"
#include "../../Time.hpp"

#include "WorldObject.hpp"

class SWorld
{
    public:
  
SWorld()
{
    _root = new CTransform();
    _root->WorldObject = nullptr;
    _root->LocalPosition = 0;
}

void Update(Time time)
{
     UpdateHeirachy(_root, _root->LocalPosition);
     UpdateSimulation(_root, time);
}


void Clear()
{
    //TODO:
}

WorldObject* CreateWorldObject()
{
    //Always need a transform!
    WorldObject* worldObject = new WorldObject();
    CTransform* trans = worldObject->AddComponent(new CTransform());
    trans->WorldObject = worldObject;
    _root->AddChild(trans);
    return worldObject;
}

   private:

    void UpdateHeirachy(CTransform* trans, int basis)
    {
        std::vector<CTransform*> children = trans->GetChildren();
        for(int i = 0 ; i < children.size(); i++)
        {
            children[i]->LossyGlobalPosition = basis + children[i]->LocalPosition;
            UpdateHeirachy(children[i], children[i]->LossyGlobalPosition);
        }
    }

     void UpdateSimulation(CTransform* trans, Time time)
    {
        if(trans == nullptr)
        {
            return;
        }

        if(trans->WorldObject != nullptr)
        {
            std::vector<CComponent*> components = trans->WorldObject->_components;
            for(int c = 0 ; c < components.size(); c++) //get it ha
            {
                components[c]->Update(time);
            }
        }
       

        std::vector<CTransform*> children = trans->GetChildren();
        for(int i = 0 ; i < children.size(); i++)
        {
            UpdateSimulation(children[i], time);
        }
    }

   CTransform* _root;
};


#endif