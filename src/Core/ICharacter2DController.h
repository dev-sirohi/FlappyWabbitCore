//#pragma once
//
//#include <Core/Character2D.h>
//
//class ICharacter2DController
//{
//  public:
//    ICharacter2DController()
//    {
//    }
//
//    virtual void Update(float dt) {
//        UpdateDelegate();
//    }
//
//    virtual ~ICharacter2DController() = default;
//};
//
//class PlayerCharacter2DController : public ICharacter2DController
//{
//  public:
//    PlayerCharacter2DController() : ICharacter2DController()
//    {
//    }
//
//    void Update(float dt) override;
//};
//
//class CutsceneCharacter2DController : public ICharacter2DController
//{
//  public:
//    CutsceneCharacter2DController() : ICharacter2DController()
//    {
//    }
//
//    void Update(float dt) override;
//};