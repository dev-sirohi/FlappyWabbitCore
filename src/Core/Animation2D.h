#pragma once

#include <Core/Includes.h>

class Animation2D
{
  private:
    std::vector<Rectangle> _frames;
    int _currentFrameIndex = 0;

  public:
    float Timer = 0.0;
    float Speed = 0.0;

    void AddFrame(Rectangle frame)
    {
        _frames.push_back(frame);
    }

    void Update(float dt)
    {
        _currentFrameIndex = (_currentFrameIndex + 1) % _frames.size();
    }

    Rectangle GetFrame()
    {
        return _frames[_currentFrameIndex];
    }
};