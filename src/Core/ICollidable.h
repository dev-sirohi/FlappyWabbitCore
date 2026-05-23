#pragma once

#include <Core/Includes.h>

class ICollidable
{
  public:
    virtual Rectangle GetCollider() const = 0;

    virtual ~ICollidable() = default;
};
