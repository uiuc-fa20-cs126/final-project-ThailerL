#pragma once

#include <core/aabb.h>
#include <core/level.h>
#include <cinder/app/KeyEvent.h>
#include "cinder/gl/gl.h"

namespace game {

class GameEngine {
 public:
  void LoadLevel(const Level& level);

  void UseInput(ci::app::KeyEvent event);

 private:
  AABB player_;
  std::vector<AABB> platforms_;

  const float kPlayerSpeed = 3;
  const float kPlayerJump = 10;
  const float kGravity = -9.8;
};

}  // namespace game
