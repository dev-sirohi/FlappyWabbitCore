#include <Core/Common.h>
#include <Core/Debugging.h>
#include <Core/IDebuggable.h>

void IDebuggable::DrawColliderLines()
{
#ifdef ENABLE_DEBUGGING_CORE
    if (_worldColliderLinesDrawn)
    {
        return;
    }
    DrawRectangleLinesEx(GetWorldCollider(), Debugging::World::LineWidth, Debugging::World::Color);
#endif
}
