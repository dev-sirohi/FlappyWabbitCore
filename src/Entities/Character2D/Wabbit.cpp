#include <Core/Common.h>
#include <Core/Global.h>
#include <Core/Includes.h>
#include <Entities/Character2D/Wabbit.h>

namespace
{
enum AnimationState
{
    REST,
    // Total Count
    Size,
};

constexpr std::string_view SPRITE_PATH = "Wabbit.png";
constexpr float SCALE                  = 2.0f;
constexpr float FRAME_SIZE             = 32.0f;

constexpr Vector2 VELOCITY = Vector2{};
constexpr Vector2 POSITION = Vector2{100, 100};
constexpr Vector2 SIZE     = Vector2{FRAME_SIZE * SCALE, FRAME_SIZE *SCALE};
constexpr Color COLOR      = WHITE;

constexpr float VELOCITY_X = 600.0f;
constexpr float VELOCITY_Y = 800.0f;

} // namespace

Wabbit::Wabbit()
{
    _spritePath = SPRITE_PATH;

    _velocity = VELOCITY;
    _position = POSITION;
    _size     = SIZE;
    _color    = WHITE;

    InitializeAnimationController(AnimationState::Size);
}

void Wabbit::Load()
{
    _texture = LoadTexture(_spritePath.c_str());

    // FrameCount for each animation
    // 0, 0   -> 32, 32
    // 32, 32 -> 64, 64
    // ... and so on
    int frameCount            = 0;
    int currentAnimationState = AnimationState::REST;

    frameCount = 1;
    Animation2D restAnimation;
    for (int i = 0; i < frameCount; i++)
    {
        float x      = (float)currentAnimationState * FRAME_SIZE;
        float y      = i * FRAME_SIZE;
        float width  = FRAME_SIZE;
        float height = FRAME_SIZE;
        restAnimation.AddFrame(Rectangle{x, y, width, height});
    }
    AddAnimation(restAnimation, currentAnimationState);

    SetAnimation(AnimationState::REST);
}

void Wabbit::_Move(float dt)
{
    if (Wabbit::IsGrounded)
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            _velocity.y = -1.0f * VELOCITY_Y;
            IsGrounded  = false;
        }
    }

    _velocity.x = 0.0f;
    if (IsKeyDown(KEY_RIGHT))
    {
        _velocity.x = VELOCITY_X;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        _velocity.x = -1.0f * VELOCITY_X;
    }
}

void Wabbit::Update(float dt)
{
    UpdateAnimation(dt);

    _Move(dt);

    // Default movements
    _velocity.y += _gravity * dt;
    _position.y += _velocity.y * dt;
    _position.x += _velocity.x * dt;

    if (_position.y + _size.y > GetWorldCollider().height)
    {
        _velocity.y = 0;
        IsGrounded  = true;
    }

    if (_position.x + _size.x > GetWorldCollider().width || _position.x < GetWorldCollider().x)
    {
        _velocity.x = 0;
    }

    if (CheckCollisionRecs(GetCollider(), GetWorldCollider()))
    {
        _position.x = std::clamp(_position.x, 0.0f, Constants::INTERNAL_SCREEN_WIDTH - _size.x);
        _position.y = std::clamp(_position.y, 0.0f, Constants::INTERNAL_SCREEN_HEIGHT - _size.y);
    }

    _position.x = round(_position.x);
    _position.y = round(_position.y);
}

void Wabbit::Draw()
{
#ifdef ENABLE_COLLISION_DEBUGGING
    DrawRectangleLinesEx(GetCollider(), 2, RED);
    DrawRectangleLinesEx(GetWorldCollider(), 2, GREEN);
#endif
    DrawTexturePro(_texture,
                   GetCurrentAnimationFrame(),
                   Rectangle{_position.x, _position.y, _size.x, _size.y},
                   Vector2{0, 0},
                   0.0f,
                   _color);
}
