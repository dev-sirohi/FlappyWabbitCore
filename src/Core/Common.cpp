#include <Core/Common.h>
#include <Core/Global.h>

float GetClampedFrameTime()
{
    float dt = GetFrameTime();
    if (dt > 0.5)
    {
        return 0.5;
    }
    return dt;
}

Rectangle GetWorldCollider()
{
    return Rectangle{0, 0, Constants::INTERNAL_SCREEN_WIDTH, Constants::INTERNAL_SCREEN_HEIGHT};
}
