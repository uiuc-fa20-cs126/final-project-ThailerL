#include "core/aabb.h"
#pragma once

#include "cinder/gl/gl.h"

namespace game {

AABB::AABB(const ci::vec2& size,
           const ci::vec2& center,
           const ci::vec2& velocity,
           const ci::vec2& acceleration) :
    center_(center),
    size_(size),
    velocity_(velocity),
    acceleration_(acceleration) {
}

ci::vec2& AABB::Position() {
  return center_;
}

ci::vec2& AABB::Velocity() {
  return velocity_;
}

ci::vec2& AABB::Acceleration() {
  return acceleration_;
}

void AABB::Update() {
  center_ += velocity_;
  velocity_ += acceleration_;
}

}  // namespace game
