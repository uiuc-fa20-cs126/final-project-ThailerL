#pragma once

#include <core/game_engine.h>
#include "cinder/gl/gl.h"
#include "component.h"

namespace game {

namespace visualizer {

class GameDisplay : public Component {
 public:
  GameDisplay(const GameEngine& game_engine,
              const glm::vec2& top_left_corner = {},
              const glm::vec2& dimensions = {});

  void Draw() const override;

 private:
  const GameEngine& game_engine_;

  void DrawAABB(AABB box) const;
};

}  // namespace visualizer

}  // namespace game
