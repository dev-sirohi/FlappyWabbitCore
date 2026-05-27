#include <Core/Common.h>
#include <Core/Global.h>
#include <Core/ICharacter2DController.h>
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
    constexpr Vector2 SIZE     = Vector2{(FRAME_SIZE * SCALE), (FRAME_SIZE * SCALE)};
    constexpr Color COLOR      = WHITE;

    constexpr float VELOCITY_X = 600.0f;
    constexpr float VELOCITY_Y = 800.0f;

    inline void MoveWabbit(Character2D &wabbit, float dt)
    {
        if (wabbit.IsGrounded)
        {
            if (IsKeyPressed(KEY_SPACE))
            {
                wabbit.Velocity.y = -1.0f * VELOCITY_Y;
                wabbit.IsGrounded = false;
            }
        }

        wabbit.Velocity.x = 0.0f;
        if (IsKeyDown(KEY_RIGHT))
        {
            wabbit.Velocity.x = VELOCITY_X;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            wabbit.Velocity.x = -1.0f * VELOCITY_X;
        }
    }

    void PlayerController(Character2D &wabbit, float dt)
    {
        wabbit.UpdateAnimation(dt);

        wabbit.Position.x = round(wabbit.Position.x);
        wabbit.Position.y = round(wabbit.Position.y);

        MoveWabbit(wabbit, dt);

        // Default movements
        wabbit.Velocity.y += wabbit.Gravity * dt;
        wabbit.Position.y += wabbit.Velocity.y * dt;
        wabbit.Position.x += wabbit.Velocity.x * dt;

        if (wabbit.Position.y + wabbit.Size.y > GetWorldCollider().height)
        {
            wabbit.Velocity.y = 0;
            wabbit.IsGrounded = true;
        }

        if (wabbit.Position.x + wabbit.Size.x > GetWorldCollider().width ||
            wabbit.Position.x < GetWorldCollider().x)
        {
            wabbit.Velocity.x = 0;
        }

        if (CheckCollisionRecs(wabbit.GetCollider(), GetWorldCollider()))
        {
            wabbit.Position.x = std::clamp(wabbit.Position.x, 0.0f,
                                           Constants::INTERNAL_SCREEN_WIDTH - wabbit.Size.x);
            wabbit.Position.y = std::clamp(wabbit.Position.y, 0.0f,
                                           Constants::INTERNAL_SCREEN_HEIGHT - wabbit.Size.y);
        }
    }

} // namespace

Wabbit::Wabbit()
{
    _spritePath = SPRITE_PATH;

    Velocity = VELOCITY;
    Position = POSITION;
    Size     = SIZE;
    Color    = COLOR;

    InitializeAnimationController(AnimationState::Size);

    UpdateDelegate = PlayerController;
}

void Wabbit::Load()
{
    Texture = LoadTexture(_spritePath.c_str());

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

void Wabbit::Draw()
{
    Character2D::Draw();

    DrawTexturePro(Texture, GetCurrentAnimationFrame(),
                   Rectangle{Position.x, Position.y, Size.x, Size.y}, Vector2{0, 0}, 0.0f, Color);
}
