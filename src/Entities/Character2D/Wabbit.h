#pragma once

#include <Core/AnimationController.h>
#include <Core/Character2D.h>
#include <Core/Includes.h>

class Wabbit final : public Character2D
{
  private:
    void _Move(float dt);

  public:
    Wabbit();
    void Load() override;
    virtual void Update(float dt) override;
    void Draw() override;
};
