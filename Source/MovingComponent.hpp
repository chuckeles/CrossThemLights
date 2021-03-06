#pragma once

#include "Component.hpp"
#include "Transform.hpp"
#include "Events.hpp"


/**
 * A simple component that makes the entity move forever. Configurable.
 */


class MovingComponent : public Component {

public:

    virtual void OnAttach(std::weak_ptr<Entity> entity) override;
    virtual void OnDetach() override;
    virtual std::string GetType() const override;

    void OnUpdate(float deltaSeconds);

    MovingComponent(Transform::Axis axis, float speed, Transform::Space space = Transform::Space::Local);


private:

    std::weak_ptr<Entity> mEntity;
    Events::ListenerId listenerId;

    float mSpeed;
    Transform::Axis mAxis;
    Transform::Space mSpace;

};


