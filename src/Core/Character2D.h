#pragma once

#include <Core/Animatable.h>
#include <Core/Global.h>
#include <Core/ICollidable.h>
#include <Core/IDebuggable.h>
#include <Core/IEntity.h>
#include <Core/Includes.h>
#include <Core/ICharacter2DController.h>

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
    bool _isGrounded;

  public:
    virtual ~Character2D()
    {
        if (_texture.id != 0)
        {
            UnloadTexture(_texture);
        }
    }

    std::unique_ptr<ICharacter2DController> Controller;

    virtual void Load()           = 0;
    void Update(float dt);
    virtual void Draw();

    Rectangle GetCollider() const override;

    void DrawColliderLines() override;
};
