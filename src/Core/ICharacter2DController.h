#pragma once

#include <Core/Character2D.h>

class ICharacter2DController
{
  protected:
    Character2D *_character;

  public:
    ICharacter2DController(Character2D *character) : _character(character)
    {
    }

    virtual void Update(float dt) = 0;

    virtual ~ICharacter2DController() = default;
};

class PlayerCharacter2DController : public ICharacter2DController
{
  public:
    PlayerCharacter2DController(Character2D *character) : ICharacter2DController(character)
    {
    }

    void Update(float dt) override;
};

class CutsceneCharacter2DController : public ICharacter2DController
{
  public:
    CutsceneCharacter2DController(Character2D *character) : ICharacter2DController(character)
    {
    }

    void Update(float dt) override;
};