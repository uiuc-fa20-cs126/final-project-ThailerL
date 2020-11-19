#pragma once

#include <core/aabb.h>
#include <core/level.h>
#include "cinder/gl/gl.h"

namespace game {

class GameEngine {
 public:
  GameEngine();
  void LoadLevel(const Level& level);

 private:
  AABB player_;
  Level level_;
};

}  // namespace game
