#pragma once

#include <Core/ICharacter2DController.h>

class PlayerCharacter2DController : public ICharacter2DController
{
  public:
    virtual void Update(float dt) override = 0;
};