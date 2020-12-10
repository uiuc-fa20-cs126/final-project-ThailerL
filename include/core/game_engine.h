#pragma once

#include <core/aabb.h>
#include <cinder/app/KeyEvent.h>
#include "cinder/gl/gl.h"
#include <json.hpp>
#include <chrono>

namespace game {

// Represents a game engine that a user can use load a level of the game into
// and make the player do actions.
class GameEngine {
 public:
  struct Level {
    ci::vec2 size;
    std::vector<AABB> platforms;
    AABB goal;
  };

  // Loads a level and sets up the player and platforms in the level.
  void LoadLevel(const nlohmann::json& json);
  // Updates the game engine by moving the player and all the platforms,
  // while applying physics to the player.
  void Update();
  // Gives the game engine a new set up keys that are being pressed. Used
  // when a new key is pressed or a key is let go.
  void UpdatePressedKeys(const std::vector<int>& key_codes);
  // Gets the player's AABB object.
  AABB GetPlayer() const;
  // Gets the level information from the game engine.
  Level GetLevel() const;
  // Gets the projectile AABB object.
  AABB GetProjectile() const;
  // Returns true if the player has completed the level.
  bool LevelOver() const;
  void ShootProjectileTowards(const ci::vec2& target);
  double GetTime() const;

 private:
  AABB player_;
  Level level_;
  AABB projectile_;
  bool projectile_active_;
  bool player_trying_to_jump_;
  bool level_over_;

  std::chrono::steady_clock::time_point start_time_;

  // If the player is touching any platform, the player is pushed too the
  // side at which they are touching it so that they don't go into the platform.
  void RepelPlayerFromPlatforms();
  // Returns true if 2 AABB's are touching.
  static bool Colliding(const AABB& box1, const AABB& box2);
  // Returns a ci::vec2 created by the 2 values in a std::vector.
  static ci::vec2 Vec2(const std::vector<float>& v);

  const ci::vec2 kPlayerSize = {.3, 1};
  // The horizontal speed of the player.
  const float kPlayerSpeed = .06f;
  // The initial vertical velocity of the player when they jump.
  const float kPlayerJump = .3f;
  // The constant vertical acceleration on the player.
  const float kGravity = -.01f;
  const ci::vec2 kProjectileSize = {.2, .2};
  const float kProjectileSpeed = .1f;
};

}  // namespace game
