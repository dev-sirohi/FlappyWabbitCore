#pragma once

#include <Core/AnimationController.h>
#include <Core/Character2D.h>
#include <Core/Includes.h>

class Wabbit final : public Character2D
{
  public:
    Wabbit();
    void Load() override;
    void Draw() override;
};
