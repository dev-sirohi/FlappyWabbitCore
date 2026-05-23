#pragma once

#include <Core/AnimationController.h>
#include <Core/Includes.h>

class IAnimatable
{
  private:
    AnimationController _animationController;

  public:
    virtual void InitializeAnimationController(int size);
    Rectangle GetCurrentAnimationFrame();
    void AddAnimation(Animation2D animation, int animationIndex);
    void SetAnimation(int animationIndex);
    void UpdateAnimation(float dt);

    virtual ~IAnimatable() = default;
};
