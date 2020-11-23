#include "core/game_engine.h"
#include <algorithm>
namespace game {

void GameEngine::LoadLevel(const Level& level) {
  player_ = AABB(kPlayerSize, level.GetPlayerStart(), {0, 0}, {0, kGravity});
  platforms_ = level.GetPlatforms();
}

void GameEngine::Update() {
  player_.Update();
  RepelPlayerFromPlatforms();
  for (auto& platform : platforms_) {
    platform.Update();
  }
}

void GameEngine::UpdatePressedKeys(std::vector<int> key_codes) {
  for (int code : key_codes) {
    if (std::find(last_codes_.begin(), last_codes_.end(), code)
        == last_codes_.end()) {
      switch (code) {
        case ci::app::KeyEvent::KEY_w:player_.Velocity().y = kPlayerJump;
          break;
        case ci::app::KeyEvent::KEY_a:player_.Velocity().x = -kPlayerSpeed;
          break;
        case ci::app::KeyEvent::KEY_d:player_.Velocity().x = kPlayerSpeed;
          break;
      }
    }
  }

  last_codes_ = key_codes;
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
  return std::abs(box1.Position().x - box2.Position().x) * 2
      <= (box1.Size().x + box2.Size().x)
      && std::abs(box1.Position().y - box2.Position().y) * 2
          <= (box1.Size().y + box2.Size().y);
}

}  // namespace game