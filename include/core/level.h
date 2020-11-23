#pragma once

#include "cinder/gl/gl.h"
#include "aabb.h"

namespace game {

class Level {
 public:
  Level(const std::vector<AABB>& platforms, const ci::vec2& player_start);

  std::vector<AABB> GetPlatforms() const;
  ci::vec2 GetPlayerStart() const;

 private:
  const std::vector<AABB> platforms_;
  const ci::vec2 player_start_;
};

}  // namespace game
