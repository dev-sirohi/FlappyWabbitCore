#pragma once

class IDebuggable {
  private:
      bool _worldColliderLinesDrawn = false;

  public:
      virtual void DrawColliderLines() = 0;
};
