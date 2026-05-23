#include <Core/Common.h>
#include <Core/Global.h>
#include <Core/Includes.h>
#include <Scenes/TitleScene.h>

void SetDefaults(void)
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Game");
    SetTargetFPS(120);
    SearchAndSetResourceDir("resources");
}

int main(void)
{
    SetDefaults();

    RenderTexture2D gameRenderTexture =
        LoadRenderTexture(Constants::INTERNAL_SCREEN_WIDTH, Constants::INTERNAL_SCREEN_HEIGHT);
    SetTextureFilter(gameRenderTexture.texture, TEXTURE_FILTER_POINT);

    std::unique_ptr<IScene> currentScene = std::make_unique<TitleScene>();
    currentScene->Load();

    while (!WindowShouldClose())
    {
        BeginTextureMode(gameRenderTexture);

        ClearBackground(BLACK);

        currentScene->Draw();
        currentScene->Update(GetClampedFrameTime());

        EndTextureMode();

        BeginDrawing();

        ClearBackground(BLACK);

        float scale        = floor(std::min((float)GetScreenWidth() / Constants::INTERNAL_SCREEN_WIDTH,
                                     (float)GetScreenHeight() / Constants::INTERNAL_SCREEN_HEIGHT));
        float renderWidth  = floor(Constants::INTERNAL_SCREEN_WIDTH * scale);
        float renderHeight = floor(Constants::INTERNAL_SCREEN_HEIGHT * scale);
        float offsetX      = floor((GetScreenWidth() - renderWidth) * 0.5f);
        float offsetY      = floor((GetScreenHeight() - renderHeight) * 0.5f);

        DrawTexturePro(gameRenderTexture.texture,
                       Rectangle{0, 0, (float)gameRenderTexture.texture.width, -(float)gameRenderTexture.texture.height},
                       Rectangle{offsetX, offsetY, renderWidth, renderHeight},
                       Vector2{0, 0},
                       0.0f,
                       WHITE);

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
