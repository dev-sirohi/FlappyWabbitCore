#pragma once

#include <Core/Includes.h>
#include <Core/IScene.h>
#include <Core/IEntity.h>

class TitleScene : public IScene
{
  private:
    std::vector<std::unique_ptr<IEntity>> _entityList;

  public:
    TitleScene();
    void Load() override;
    void Update(float dt) override;
    void Draw() override;
};
