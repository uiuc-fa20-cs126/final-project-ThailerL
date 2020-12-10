#include <visualizer/game_app.h>
#include <algorithm>

namespace game {

namespace visualizer {

using json = nlohmann::json;
using glm::vec2;

GameApp::GameApp() :
    levels_(GetJson(kLevelsPath)),
    game_display_(game_engine_),
    records_(GetJson(kRecordsPath)),
    menu_display_(records_) {
  ci::app::setWindowSize((int) kWindowSize.x, (int) kWindowSize.y);
  current_level_ = 0;
  game_engine_.LoadLevel(levels_[current_level_]);
}

void GameApp::draw() {
  ci::gl::clear(ci::Color("white"));
  if (game_engine_.LevelOver()) {
    DrawComponentFullScreen(menu_display_);
  } else {
    DrawComponentFullScreen(game_display_);
  }
}

void GameApp::update() {
  if (game_engine_.LevelOver()) {
    if (game_engine_.GetTime() < records_[current_level_]) {
      records_[current_level_] = game_engine_.GetTime();
      WriteJsonToFile(records_, kRecordsPath);
    }
  } else {
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

nlohmann::json GameApp::GetJson(const std::string& path) const {
  json json;
  std::ifstream stream(path);
  stream >> json;
  return json;
}

void GameApp::WriteJsonToFile(const nlohmann::json& json,
                              const std::string& path) const {
  std::ofstream stream(path);
  stream << json;
}

void GameApp::DrawComponentFullScreen(Component& component) const {
  component.SetLocation({0, 0}, ci::app::getWindowSize());
  component.Draw();
}

}  // namespace visualizer

}  // namespace game
