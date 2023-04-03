#ifndef C_TRANSFORM_HPP
#define C_TRANSFORM_HPP

#include <string>
#include <vector>
#include "Component.hpp"
#include "../Systems/World/WorldObject.hpp"

#define CTRANSFORM_MAX_CHILD_COUNT 10

class CTransform : public CComponent
{
    public:
    int LocalPosition;
    int LossyGlobalPosition;
    WorldObject* WorldObject;

    void AddChild(CTransform* child)
    {
        _children.push_back(child);
    }

    std::vector<CTransform*> GetChildren()
    {
        return _children;
    }

    private:
    std::vector<CTransform*> _children;

    void Update(Time time) override { }

    std::string TypeID() override
    {
        return "CTransform";
    }
};

#endif