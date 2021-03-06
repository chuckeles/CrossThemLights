#pragma once

#include <glm/vec3.hpp>
#include <vector>

#include "Component.hpp"
#include "Events.hpp"
#include "Entity.hpp"


/**
 * Physics collider. Can check for collisions with other colliders.
 */


class Entity;

class ColliderComponent : public Component {

public:

    enum class Group {
        Solid = 1 << 1,
        FakeSolid = 1 << 2,
        Player = 1 << 3,
        Enemy = 1 << 4,
        Collectible = 1 << 5,
        Hint = 1 << 6
    };


public:

    virtual void OnAttach(std::weak_ptr<Entity> entity) override;
    virtual std::string GetType() const override;

    Entity::Id CheckCollision(int withGroup) const;
    std::vector<Entity::Id> CheckCollision(std::vector<int> withGroups) const;

    ColliderComponent(float sx, float sy, float sz, Group group);


private:

    std::weak_ptr<Entity> mEntity;
    glm::vec3 mSize;
    Group mGroup;

};


