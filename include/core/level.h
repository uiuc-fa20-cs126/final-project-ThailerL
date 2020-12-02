#pragma once

#include "cinder/gl/gl.h"
#include "aabb.h"

namespace game {

// Represents a static level with platforms and a player starting location.
// TODO: Add more members for ending of the level, etc.
class Level {
 public:
  // Constructs a level with given platforms and player starting location.
  Level(const std::vector<AABB>& platforms, const ci::vec2& player_start,
        const ci::vec2& dimensions);
  // Gets the dimensions of the level, with (0, 0) being the bottom left and
  // the dimensions vector being the top right of the level.
  ci::vec2 GetDimensions() const;
  // Gets the collection of platforms in the level.
  std::vector<AABB> GetPlatforms() const;
  // The the position that the player starts in the level.
  ci::vec2 GetPlayerStart() const;

 private:
  const std::vector<AABB> platforms_;
  const ci::vec2 player_start_;
  const ci::vec2 dimensions_;
};

}  // namespace game
