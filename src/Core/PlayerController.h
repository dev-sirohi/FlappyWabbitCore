#pragma once

#include <Core/IEntityController.h>
#include <Core/Includes.h>

class PlayerController : public IEntityController
{
  public:
    PlayerController(IEntity *entity) : IEntityController(entity)
    {
    }

    void Update(float dt) override
    {
        if (IsKeyDown(KEY_D))
        {
            _entity->Position.x += 100 * dt;
        }
    }
};