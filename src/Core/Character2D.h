#pragma once

#include <Core/Global.h>
#include <Core/IEntity.h>
#include <Core/Includes.h>

class Character2D : public IEntity
{
  protected:
    std::string _spritePath;
    Texture2D _texture;
    Color _color;
    Vector2 _position{};
    Vector2 _velocity{};
    float _gravity = Constants::GRAVITY;

  public:
    virtual ~Character2D()
    {
        UnloadTexture(_texture);
    }

    virtual void Load()           = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw()           = 0;
};