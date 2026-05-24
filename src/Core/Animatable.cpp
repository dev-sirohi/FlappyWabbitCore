#include <Core/Animatable.h>

void Animatable::InitializeAnimationController(int size)
{
    _animationController = AnimationController(size);
}

Rectangle Animatable::GetCurrentAnimationFrame()
{
    return _animationController.GetCurrentAnimation().GetFrame();
}

void Animatable::AddAnimation(Animation2D animation, int animationIndex)
{
    _animationController.AddAnimation(animation, animationIndex);
}

void Animatable::SetAnimation(int animationIndex)
{
    _animationController.SetCurrentAnimationState(animationIndex);
}

void Animatable::UpdateAnimation(float dt)
{
    _animationController.GetCurrentAnimation().Update(dt);
}
