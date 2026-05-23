#pragma once

#include <Core/AnimationController.h>
#include <Core/Character2D.h>
#include <Core/Includes.h>

class Wabbit : public Character2D
{
  private:
    void _Move(float dt);

  public:
    bool IsGrounded = false;

    Wabbit();
    void Load() override;
    void Update(float dt) override;
    void Draw() override;
};
