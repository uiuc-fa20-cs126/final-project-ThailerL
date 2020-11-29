#pragma once

#include "cinder/gl/gl.h"

namespace game {

// Represents an Axis Aligned Bounding Box (AABB), which is a rectangle with
// sides parallel to the coordinate axes.
class AABB {
 public:
  // Creates an AABB with a size, center position, velocity, and acceleration.
  AABB(const ci::vec2& size = {},
       const ci::vec2& center = {},
       const ci::vec2& velocity = {},
       const ci::vec2& acceleration = {});
  // Gets a reference to the size vector of the AABB.
  ci::vec2& Size();
  // Gets a reference to the center position vector of the AABB.
  ci::vec2& Position();
  // Gets a reference to the velocity vector of the AABB.
  ci::vec2& Velocity();
  // Gets a reference to the acceleration vector of the AABB.
  ci::vec2& Acceleration();
  // Updates the velocity based on acceleration and the position based on the
  // velocity.
  void Update();

 protected:
  ci::vec2 size_;
  ci::vec2 center_;
  ci::vec2 velocity_;
  ci::vec2 acceleration_;
};

}  // namespace game
