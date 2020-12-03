#include <visualizer/game_app.h>
#include <algorithm>

namespace game {

namespace visualizer {

using json = nlohmann::json;
using glm::vec2;

GameApp::GameApp() : window_(Layout::kHorizontal) {
  ci::app::setWindowSize((int) kWindowSize.x, (int) kWindowSize.y);
  json levels;
  std::ifstream levels_stream(kLevelsPath);
  levels_stream >> levels;
  game_engine_.LoadLevel(levels[0]);
  window_.Add(std::make_unique<GameDisplay>(game_engine_));
}

void GameApp::draw() {
  ci::gl::clear(ci::Color("white"));
  window_.SetLocation({0, 0}, ci::app::getWindowSize());
  window_.Draw();
}

void GameApp::update() {
  if (!game_engine_.LevelOver()) {
    game_engine_.Update();
  }
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

void GameApp::mouseDown(ci::app::MouseEvent event) {
  if (event.isLeft() && !game_engine_.LevelOver()) {
    vec2 pixel_pos = event.getPos();
    pixel_pos.y = ci::app::getWindowSize().y - pixel_pos.y;
    game_engine_.ShootProjectileTowards(game_engine_.GetLevel().size *
        pixel_pos / vec2(ci::app::getWindowSize()));
  }
}

}  // namespace visualizer

}  // namespace game
