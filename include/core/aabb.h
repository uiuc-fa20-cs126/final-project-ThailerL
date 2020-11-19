#pragma once

#include "cinder/gl/gl.h"

namespace game {

class AABB {
 public:
  AABB(const ci::vec2& center,
       const ci::vec2& half_size,
       const ci::vec2& velocity = {0, 0});

  void SetVelocity(const ci::vec2& velocity);

  void Update();

 protected:
  ci::vec2 center_;
  ci::vec2 half_size_;
  ci::vec2 velocity_;
};

}  // namespace game
