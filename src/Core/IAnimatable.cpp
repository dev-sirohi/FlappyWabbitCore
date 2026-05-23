#include <Core/IAnimatable.h>

void IAnimatable::InitializeAnimationController(int size)
{
    _animationController = AnimationController(size);
}

Rectangle IAnimatable::GetCurrentAnimationFrame()
{
    return _animationController.GetCurrentAnimation().GetFrame();
}

void IAnimatable::AddAnimation(Animation2D animation, int animationIndex)
{
    _animationController.AddAnimation(animation, animationIndex);
}

void IAnimatable::SetAnimation(int animationIndex)
{
    _animationController.SetCurrentAnimationState(animationIndex);
}

void IAnimatable::UpdateAnimation(float dt)
{
    _animationController.GetCurrentAnimation().Update(dt);
}
