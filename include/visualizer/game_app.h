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
  void keyDown(ci::app::KeyEvent event) override;
  void keyUp(ci::app::KeyEvent event) override;

  const glm::vec2 kWindowSize = {1500.0f, 900.0f};
  const float kMargin = 10;

 private:
  GameEngine game_engine_;
  Panel window_;
  std::vector<int> pressed_key_codes_;

  const std::vector<AABB> kPlatforms = {{{1500, 30}, {750, 15}},
                                        {{1500, 30}, {750, 500}},
                                        {{1500, 30}, {750, 600}}};
  const Level kLevel = {kPlatforms, {50, 200}};
};

}  // namespace visualizer

}  // namespace game
