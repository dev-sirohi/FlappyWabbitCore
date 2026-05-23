#include <Core/Includes.h>
#include <Entities/Character2D/Wabbit.h>
#include <Scenes/TitleScene.h>

TitleScene::TitleScene()
{
    auto wabbit = std::make_unique<Wabbit>();
    wabbit->Load();
    _entityList.push_back(std::make_unique<Wabbit>());
}

void TitleScene::Load()
{
    for (const auto &entity : _entityList)
    {
        entity->Load();
    }
}

void TitleScene::Update(float dt)
{
    for (const auto &entity : _entityList)
    {
        entity->Update(dt);
    }
}

void TitleScene::Draw()
{
    for (const auto &entity : _entityList)
    {
        entity->Draw();
    }
}
