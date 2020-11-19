#pragma once

#include <core/game_engine.h>
#include "cinder/gl/gl.h"
#include "component.h"

namespace game {

namespace visualizer {

/*
 * This object stores the on-screen location and bounds of an environment and
 * draws an environment.
 */
class GameDisplay : public Component {
 public:
  GameDisplay(const GameEngine& game_engine,
                     const glm::vec2& top_left_corner = {},
                     const glm::vec2& dimensions = {});

  /*
   * Draws the referenced environment that was passed in through the
   * constructor.
   */
  void Draw() const override;

 private:
  const GameEngine& game_engine_;
};

}  // namespace visualizer

}  // namespace game
