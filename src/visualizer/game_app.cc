#include <visualizer/game_app.h>
#include "cinder/Rand.h"

namespace game {

namespace visualizer {

using glm::vec2;

GameApp::GameApp() : game_engine_(), window_(Layout::kHorizontal, kMargin) {
  ci::app::setWindowSize((int) kWindowSize.x, (int) kWindowSize.y);

  window_.Add(std::make_unique<GameDisplay>(game_engine_));
}

void GameApp::draw() {
}

void GameApp::update() {
}

}  // namespace visualizer

}  // namespace game
