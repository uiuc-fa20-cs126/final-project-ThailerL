#include <visualizer/game_app.h>
#include <algorithm>
#include <iostream>
#include <fstream>

namespace game {

namespace visualizer {

using json = nlohmann::json;
using glm::vec2;

GameApp::GameApp() : window_(Layout::kHorizontal, kMargin) {
  ci::app::setWindowSize((int) kWindowSize.x, (int) kWindowSize.y);
  json levels;
  std::ifstream levels_stream(kLevelsPath);
  levels_stream >> levels;
  game_engine_.LoadLevel(levels[0]);
  window_.Add(std::make_unique<GameDisplay>(game_engine_));
}

void GameApp::draw() {
  ci::gl::clear(ci::Color("white"));
  window_.SetLocation(vec2(kMargin),
                      ci::app::getWindowSize() - static_cast<int>(2 * kMargin));
  window_.Draw();
}

void GameApp::update() {
  game_engine_.Update();
}

void GameApp::keyDown(ci::app::KeyEvent event) {
  pressed_key_codes_.push_back(event.getCode());
  game_engine_.UpdatePressedKeys(pressed_key_codes_);
}

void GameApp::keyUp(ci::app::KeyEvent event) {
  pressed_key_codes_.erase(std::remove(pressed_key_codes_.begin(),
                                       pressed_key_codes_.end(),
                                       event.getCode()),
                           pressed_key_codes_.end());
  game_engine_.UpdatePressedKeys(pressed_key_codes_);
}

}  // namespace visualizer

}  // namespace game
