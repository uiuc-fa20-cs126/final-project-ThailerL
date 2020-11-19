#pragma once

#include "cinder/gl/gl.h"

namespace game {

class AABB {
 public:
  AABB(ci::vec2 center, ci::vec2 half_size);

 protected:
  ci::vec2 center_;
  ci::vec2 half_size_;
};

}  // namespace game
