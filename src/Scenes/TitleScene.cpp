#include <Core/Includes.h>
#include <Entities/Character2D/Wabbit.h>
#include <Scenes/TitleScene.h>

namespace
{
    enum Cutscenes
    {
        Opening,
    };

    bool IsCutscene = false;
    int CutsceneId  = -1;
} // namespace

TitleScene::TitleScene()
{
    auto wabbit = std::make_unique<Wabbit>();
    wabbit->Load();
    _entityList.push_back(std::make_unique<Wabbit>());
}

void TitleScene::Load()
{
    switch (CutsceneId)
    {
        case Cutscenes::Opening:
        {
        }
        default:
        {
            for (const auto &entity : _entityList)
            {
                entity->Load();
            }
        }
    }
}

void TitleScene::Update(float dt)
{
    if (IsCutscene)
    {
    }

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
