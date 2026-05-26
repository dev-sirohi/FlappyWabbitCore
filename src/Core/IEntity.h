#pragma once

class IEntity
{
  public:
    virtual ~IEntity()
    {
    }

    virtual void Load()                 = 0;
    virtual void Update(float dt)       = 0;
    virtual void Draw()                 = 0;
};
