#include "core/game_engine.h"

namespace game {

void GameEngine::LoadLevel(const Level& level) {
  player_ = AABB({1, 2}, level.GetPlayerStart(), {0, 0}, {0, kGravity});
  platforms_ = level.GetPlatforms();
}

void GameEngine::UseInput(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_w:
      player_.SetVelocity();
      break;
    case ci::app::KeyEvent::KEY_DELETE:
      sketchpad_.Clear();
      break;
  }
}

}  // namespace game