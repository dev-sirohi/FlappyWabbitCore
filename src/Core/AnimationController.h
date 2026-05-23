#pragma once

#include <Core/Animation2D.h>
#include <Core/Includes.h>

class AnimationController
{
  private:
    std::vector<Animation2D> _animationList;
    int _currentAnimationIndex = 0;

  public:
    AnimationController(int size = 0)
    {
        _animationList = std::vector<Animation2D>(size);
    }

    void AddAnimation(Animation2D animation, int index)
    {
        _animationList[index] = animation;
    }

    void SetCurrentAnimationState(int animationIndex)
    {
        _currentAnimationIndex = animationIndex;
    }

    Animation2D *GetCurrentAnimation()
    {
        return &_animationList[_currentAnimationIndex];
    }
};