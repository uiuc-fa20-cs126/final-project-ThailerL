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

ci::vec2& AABB::Size() {
  return size_;
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
  velocity_ += acceleration_;
  center_ += velocity_;
}

ci::vec2 AABB::Size() const {
  return size_;
}

ci::vec2 AABB::Position() const {
  return center_;
}

ci::vec2 AABB::Velocity() const {
  return velocity_;
}

ci::vec2 AABB::Acceleration() const {
  return acceleration_;
}

}  // namespace game
