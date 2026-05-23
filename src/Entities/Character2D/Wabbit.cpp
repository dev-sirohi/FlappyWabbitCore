#include <Core/Includes.h>
#include <Entities/Character2D/Wabbit.h>

enum AnimationState
{
    REST,
    // Total Count
    Size,
};

Wabbit::Wabbit()
{
    _spritePath          = "Wabbit.png";
    _animationController = AnimationController(AnimationState::Size);
}

void Wabbit::Load()
{
    _texture = LoadTexture(_spritePath.c_str());

    Animation2D restAnimation;
    restAnimation.AddFrame(Rectangle{0, 0, 32, 32});
    _animationController.AddAnimation(restAnimation, AnimationState::REST);

    _animationController.SetCurrentAnimationState(AnimationState::REST);
}

void Wabbit::_Move(float dt)
{
    if (IsKeyPressed(KEY_SPACE) && Wabbit::IsGrounded)
    {
        _velocity.y = -300.0f;
    }

    _velocity.x = 0.0f;
    if (IsKeyDown(KEY_RIGHT))
    {
        _velocity.x = 200.0f;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        _velocity.x = -200.0f;
    }
}

void Wabbit::Update(float dt)
{
    _animationController.GetCurrentAnimation()->Update(dt);

    _Move(dt);

    // Default forces
    _velocity.y += _gravity * dt;
    _position.y += _velocity.y * dt;
    if (_position.y > 500)
    {
        _position.y = 500;
        _velocity.y = 0;
        IsGrounded  = true;
    }
}

void Wabbit::Draw()
{
    DrawTextureRec(_texture, _animationController.GetCurrentAnimation()->GetFrame(), _position, _color);
}