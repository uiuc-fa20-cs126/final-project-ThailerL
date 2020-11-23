#pragma once

#include <core/aabb.h>
#include <core/level.h>
#include <cinder/app/KeyEvent.h>
#include "cinder/gl/gl.h"

namespace game {

class GameEngine {
 public:
  void LoadLevel(const Level& level);

  void Update();

  void UseInputs(std::vector<ci::app::KeyEvent> events);

 private:
  AABB player_;
  std::vector<AABB> platforms_;
  std::vector<ci::app::KeyEvent> last_events_;

  void RepelPlayerFromPlatforms();
  bool Colliding(AABB& box1, AABB& box2);

  const ci::vec2 kPlayerSize = {1, 2};
  const float kPlayerSpeed = 3;
  const float kPlayerJump = 10;
  const float kGravity = -9.8;
};

}  // namespace game
