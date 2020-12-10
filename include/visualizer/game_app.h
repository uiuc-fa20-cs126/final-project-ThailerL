#pragma once

#include <visualizer/components/menu_display.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "components/game_display.h"
#include "components/panel.h"

namespace game {

namespace visualizer {

const std::string kLevelsPath =
    "C:/Cinder/my-projects/final-project-ThailerL/data/levels.json";
const std::string kRecordsPath =
    "C:/Cinder/my-projects/final-project-ThailerL/data/records.json";

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
  nlohmann::json levels_;
  GameEngine game_engine_;
  GameDisplay game_display_;
  nlohmann::json records_;
  MenuDisplay menu_display_;

  size_t current_level_;
  std::vector<int> pressed_key_codes_;

  nlohmann::json GetJson(const std::string& path) const;
  void WriteJsonToFile(const nlohmann::json& json,
                       const std::string& path) const;
  void DrawComponentFullScreen(Component& component) const;
};

}  // namespace visualizer

}  // namespace game
