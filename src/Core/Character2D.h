#pragma once

#include <Core/Global.h>
#include <Core/ICollidable.h>
#include <Core/IEntity.h>
#include <Core/Includes.h>
#include <Core/IAnimatable.h>

class Character2D : public IEntity, public ICollidable, public IAnimatable
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
        UnloadTexture(_texture);
    }

    virtual void Load()           = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw()           = 0;

    Rectangle GetCollider() const override
    {
        return Rectangle{_position.x, _position.y, _size.x, _size.y};
    }
};
