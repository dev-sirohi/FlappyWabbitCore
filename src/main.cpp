#include <Core/Includes.h>
#include <Scenes/TitleScene.h>

void SetDefaults(void)
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Hello Raylib");
    SearchAndSetResourceDir("resources");
}

int main(void)
{
    SetDefaults();

    std::unique_ptr<IScene> currentScene = std::make_unique<TitleScene>();
    currentScene->Load();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        currentScene->Draw();
        currentScene->Update(GetFrameTime());

        EndDrawing();

        if (currentScene->ChangeScene)
        {
            currentScene = std::move(currentScene->NextScene);
            currentScene->Load();
        }
    }


    CloseWindow();
    return 0;
}