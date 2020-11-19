#pragma once

#include "cinder/gl/gl.h"
#include "aabb.h"

namespace game {

class Player : AABB {
 public:
  Player(ci::vec2 center, ci::vec2 half_size, ci::Color color);

 private:
  ci::Color color_;

  const static float gravity
};

}  // namespace game