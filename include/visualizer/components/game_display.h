#pragma once

#include <core/game_engine.h>
#include "cinder/gl/gl.h"
#include "component.h"

namespace game {

namespace visualizer {

// Represents a GUI component that displays a game engine's contents.
class GameDisplay : public Component {
 public:
  // Creates a display with game engine, position, and size.
  GameDisplay(const GameEngine& game_engine,
              const glm::vec2& top_left_corner = {},
              const glm::vec2& dimensions = {});
  // Draws the game.
  void Draw() const override;

 private:
  const GameEngine& game_engine_;

  // Draws one AABB to the window.
  void DrawAABB(AABB box) const;
};

}  // namespace visualizer

}  // namespace game
