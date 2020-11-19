#include "core/aabb.h"
#pragma once

#include "cinder/gl/gl.h"

namespace game {

AABB::AABB(const ci::vec2& center,
           const ci::vec2& half_size,
           const ci::vec2& velocity) :
    center_(center), half_size_(half_size), velocity_(velocity) {
}

void AABB::SetVelocity(const ci::vec2& velocity) {
  velocity_ = velocity;
}

void AABB::Update() {
  center_ += velocity_;
}

}  // namespace game
