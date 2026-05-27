#include <Core/Character2D.h>
#include <Core/Common.h>
#include <Core/Debugging.h>

void Character2D::Draw()
{
    DrawColliderLines();
}

void Character2D::Update(float dt)
{
    if (UpdateDelegate)
    {
        UpdateDelegate(*this, dt);
    }
}

Rectangle Character2D::GetCollider() const
{
    return Rectangle{Position.x, Position.y, Size.x, Size.y};
}

void Character2D::DrawColliderLines()
{
    IDebuggable::DrawColliderLines();

#ifdef ENABLE_DEBUGGING_CORE
    DrawRectangleLinesEx(GetCollider(), Debugging::Character2D::LineWidth,
                         Debugging::Character2D::Color);
#endif
}
