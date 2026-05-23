#pragma once

class IScene
{
  public:
    virtual ~IScene()
    {
    }

    bool ChangeScene = false;
    std::unique_ptr<IScene> NextScene;

    virtual void Load()           = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw()           = 0;
};
