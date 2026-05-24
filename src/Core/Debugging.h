#pragma once

#include <raylib.h>

#define ENABLE_DEBUGGING_CORE

namespace Debugging
{
struct World
{
    constexpr static ::Color Color = ::WHITE;
    constexpr static int LineWidth = 2;
};
struct Character2D
{
    constexpr static ::Color Color = ::GREEN;
    constexpr static int LineWidth = 2;
};
} // namespace Debugging
