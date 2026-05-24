#pragma once

#include <Core/Animatable.h>
#include <Core/Global.h>
#include <Core/ICollidable.h>
#include <Core/IDebuggable.h>
#include <Core/IEntity.h>
#include <Core/Includes.h>

class Character2D : public IEntity, public ICollidable, public Animatable, public IDebuggable
{
  protected:
    std::string _spritePath = "";
    Texture2D _texture{};
    Color _color = WHITE;
    Vector2 _position{};
    Vector2 _velocity{};
    Vector2 _size{};
    float _gravity = Constants::GRAVITY;

  public:
    virtual ~Character2D()
    {
        if (_texture.id != 0)
        {
            UnloadTexture(_texture);
        }
    }

    virtual void Load()           = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw();

    Rectangle GetCollider() const override;

    void DrawColliderLines() override;
};
