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
  void UpdatePressedKeys(std::vector<int> key_codes);
  AABB GetPlayer() const;
  std::vector<AABB> GetPlatforms() const;

 private:
  AABB player_;
  std::vector<AABB> platforms_;
  bool player_trying_to_jump_;

  void RepelPlayerFromPlatforms();
  bool Colliding(AABB& box1, AABB& box2);

  const ci::vec2 kPlayerSize = {30, 60};
  const float kPlayerSpeed = 3;
  const float kPlayerJump = 6;
  const float kGravity = -.1f;
};

}  // namespace game
