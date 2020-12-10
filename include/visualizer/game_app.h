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
  void mouseDown(ci::app::MouseEvent event) override;

  const glm::vec2 kWindowSize = {1500.0f, 1000.0f};

 private:
  GameEngine game_engine_;
  GameDisplay game_display_;
  std::vector<int> pressed_key_codes_;

  const std::string kLevelsPath =
      "C:/Cinder/my-projects/final-project-ThailerL/data/levels.json";
};

}  // namespace visualizer

}  // namespace game
