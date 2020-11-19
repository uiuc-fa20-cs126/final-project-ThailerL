#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "components/game_display.h"
#include "components/panel.h"

namespace game {

namespace visualizer {

class GameApp : public ci::app::App {
 public:
  GameApp();

  void draw() override;
  void update() override;

  const glm::vec2 kWindowSize = {1500.0f, 900.0f};
  const float kMargin = 10;

 private:
  GameEngine game_engine_;
  Panel window_;
};

}  // namespace visualizer

}  // namespace game
