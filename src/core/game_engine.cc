#include "core/game_engine.h"
#include <algorithm>
namespace game {

void GameEngine::LoadLevel(const Level& level) {
  player_ = AABB(kPlayerSize, level.GetPlayerStart(), {0, 0}, {0, kGravity});
  platforms_ = level.GetPlatforms();
}

void GameEngine::Update() {
  RepelPlayerFromPlatforms();
  player_.Update();
  for (auto& platform : platforms_) {
    platform.Update();
  }
}

void GameEngine::UseInputs(std::vector<ci::app::KeyEvent> events) {
  for (const auto& event : events) {
    if (std::find(last_events_.begin(), last_events_.end(), event)
        == last_events_.end()) {
      switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_w:
          player_.Velocity().y = kPlayerJump;
          break;
        case ci::app::KeyEvent::KEY_a:
          player_.Velocity().x = -kPlayerSpeed;
          break;
        case ci::app::KeyEvent::KEY_d:
          player_.Velocity().x = kPlayerSpeed;
          break;
      }
    }
  }

  last_events_ = events;
}

AABB GameEngine::GetPlayer() const {
  return player_;
}

std::vector<AABB> GameEngine::GetPlatforms() const {
  return platforms_;
}

void GameEngine::RepelPlayerFromPlatforms() {
  for (auto& platform : platforms_) {
    if (Colliding(player_, platform)) {
      if (player_.Position().y > platform.Position().y) {
        player_.Position().y = platform.Position().y
            + (player_.Size().y + platform.Size().y) / 2;
      } else {
        player_.Position().y = platform.Position().y
            - (player_.Size().y + platform.Size().y) / 2;
      }
      player_.Velocity().y = 0;
    }
  }
}

bool GameEngine::Colliding(AABB& box1, AABB& box2) {
  return box1.Position().x <= box2.Position().x + box2.Size().x / 2
      && box1.Position().x + box1.Size().x / 2 > box2.Position().x
      && box1.Position().y < box2.Position().y + box2.Size().y / 2
      && box1.Position().y + box1.Size().y / 2 > box2.Position().y;
}


}  // namespace game