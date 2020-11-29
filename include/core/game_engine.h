#pragma once

#include <core/aabb.h>
#include <core/level.h>
#include <cinder/app/KeyEvent.h>
#include "cinder/gl/gl.h"

namespace game {

// Represents a game engine that a user can use load a level of the game into
// and make the player do actions.
class GameEngine {
 public:
  // Loads a level and sets up the player and platforms in the level.
  void LoadLevel(const Level& level);
  // Updates the game engine by moving the player and all the platforms,
  // while applying physics to the player.
  void Update();
  // Gives the game engine a new set up keys that are being pressed. Used
  // when a new key is pressed or a key is let go.
  void UpdatePressedKeys(std::vector<int> key_codes);
  // Gets the player's AABB object.
  AABB GetPlayer() const;
  // Gets the collection of AABB platforms in the game.
  std::vector<AABB> GetPlatforms() const;

 private:
  AABB player_;
  std::vector<AABB> platforms_;
  bool player_trying_to_jump_;

  // If the player is touching any platform, the player is pushed too the
  // side at which they are touching it so that they don't go into the platform.
  void RepelPlayerFromPlatforms();
  // Returns true if 2 AABB's are touching.
  bool Colliding(AABB& box1, AABB& box2);

  const ci::vec2 kPlayerSize = {30, 60};
  // The horizontal speed of the player.
  const float kPlayerSpeed = 3;
  // The initial vertical velocity of the player when they jump.
  const float kPlayerJump = 6;
  // The constant vertical acceleration on the player.
  const float kGravity = -.1f;
};

}  // namespace game
