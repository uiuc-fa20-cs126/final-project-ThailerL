#include "core/level.h"

namespace game {

Level::Level(const std::vector<AABB>& platforms, const ci::vec2& player_start,
             const ci::vec2& dimensions)
    : platforms_(platforms), player_start_(player_start),
      dimensions_(dimensions) {
}

std::vector<AABB> Level::GetPlatforms() const {
  return platforms_;
}

ci::vec2 Level::GetPlayerStart() const {
  return player_start_;
}

ci::vec2 Level::GetDimensions() const {
  return dimensions_;
}

}  // namespace game