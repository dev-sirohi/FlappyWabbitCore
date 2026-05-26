#include <Core/Character2D.h>
#include <Core/Common.h>
#include <Core/Debugging.h>

void Character2D::Draw()
{
    DrawColliderLines();
}

void Character2D::Update(float dt)
{
    if (Controller)
    {
        Controller->Update(dt);
    }
}

Rectangle Character2D::GetCollider() const
{
    return Rectangle{_position.x, _position.y, _size.x, _size.y};
}

void Character2D::DrawColliderLines()
{
    IDebuggable::DrawColliderLines();

#ifdef ENABLE_DEBUGGING_CORE
    DrawRectangleLinesEx(GetCollider(), Debugging::Character2D::LineWidth,
                         Debugging::Character2D::Color);
#endif
}
