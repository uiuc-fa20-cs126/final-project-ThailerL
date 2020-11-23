#pragma once

#include "cinder/gl/gl.h"

namespace game {

class AABB {
 public:
  AABB(const ci::vec2& size,
       const ci::vec2& center,
       const ci::vec2& velocity = {0, 0},
       const ci::vec2& acceleration = {0, 0});

  ci::vec2& Size();
  ci::vec2& Position();
  ci::vec2& Velocity();
  ci::vec2& Acceleration();

  void Update();

 protected:
  ci::vec2 size_;
  ci::vec2 center_;
  ci::vec2 velocity_;
  ci::vec2 acceleration_;
};

}  // namespace game
