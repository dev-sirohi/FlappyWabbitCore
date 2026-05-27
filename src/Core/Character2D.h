#pragma once

#include <Core/Animatable.h>
#include <Core/Global.h>
#include <Core/ICharacter2DController.h>
#include <Core/ICollidable.h>
#include <Core/IDebuggable.h>
#include <Core/IEntity.h>
#include <Core/Includes.h>

class Character2D : public IEntity, public ICollidable, public Animatable, public IDebuggable
{
  protected:
    std::string _spritePath = "";

  public:
    Texture2D Texture{};
    Color Color;
    Vector2 Position{};
    Vector2 Velocity{};
    Vector2 Size{};
    float Gravity = Constants::GRAVITY;
    bool IsGrounded;

    virtual ~Character2D()
    {
        if (Texture.id != 0)
        {
            UnloadTexture(Texture);
        }
    }

    std::function<void(Character2D &, float)> UpdateDelegate;

    virtual void Load() = 0;
    void Update(float dt);
    virtual void Draw();

    Rectangle GetCollider() const override;

    void DrawColliderLines() override;
};
