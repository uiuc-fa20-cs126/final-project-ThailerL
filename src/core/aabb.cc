#include "core/aabb.h"
#pragma once

#include "cinder/gl/gl.h"

namespace game {

AABB::AABB(ci::vec2 center, ci::vec2 half_size) :
    center_(center), half_size_(half_size) {
}

}  // namespace game
