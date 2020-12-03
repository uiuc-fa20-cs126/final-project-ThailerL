#include "core/game_engine.h"
#include <algorithm>
namespace game {

using json = nlohmann::json;

void GameEngine::LoadLevel(const json& level) {
  player_ = AABB(kPlayerSize, Vec2(level["start"]), {0, 0}, {0, kGravity});
  platforms_.clear();
  for (auto platform : level["platforms"]) {
    platforms_.emplace_back(Vec2(platform["size"]), Vec2(platform["center"]));
  }
  player_trying_to_jump_ = false;
}

void GameEngine::Update() {
  player_.Update();
  RepelPlayerFromPlatforms();
  for (auto& platform : platforms_) {
    platform.Update();
  }
}

void GameEngine::UpdatePressedKeys(const std::vector<int>& key_codes) {
  player_.Velocity().x = 0;
  player_trying_to_jump_ = false;
  for (int code : key_codes) {
    switch (code) {
      case ci::app::KeyEvent::KEY_w:player_trying_to_jump_ = true;
        break;
      case ci::app::KeyEvent::KEY_a:player_.Velocity().x = -kPlayerSpeed;
        break;
      case ci::app::KeyEvent::KEY_d:player_.Velocity().x = kPlayerSpeed;
        break;
    }
  }
}

AABB GameEngine::GetPlayer() const {
  return player_;
}

std::vector<AABB> GameEngine::GetPlatforms() const {
  return platforms_;
}

void GameEngine::RepelPlayerFromPlatforms() {
  for (const auto& platform : platforms_) {
    if (Colliding(player_, platform)) {
      auto player_feet_y = player_.Position().y - player_.Size().y / 2;
      auto player_head_y = player_.Position().y + player_.Size().y / 2;
      auto player_left_x = player_.Position().x - player_.Size().x / 2;
      auto player_right_x = player_.Position().x + player_.Size().x / 2;
      auto platform_bot_y = platform.Position().y - platform.Size().y / 2;
      auto platform_top_y = platform.Position().y + platform.Size().y / 2;
      auto platform_left_x = platform.Position().x - platform.Size().x / 2;
      auto platform_right_x = platform.Position().x + platform.Size().x / 2;

      // If the player goes down into the top of the platform, put them at
      // the top of it and jump if they want to, and similar for other cases.
      if (player_.Velocity().y <= 0
          && player_feet_y - player_.Velocity().y >= platform_top_y) {
        player_.Velocity().y = 0;
        player_.Position().y = platform_top_y + player_.Size().y / 2;
        if (player_trying_to_jump_) {
          player_.Velocity().y = kPlayerJump;
        }
      } else if (player_.Velocity().y > 0
          && player_head_y - player_.Velocity().y <= platform_bot_y) {
        player_.Velocity().y = 0;
        player_.Position().y = platform_bot_y - player_.Size().y / 2;
      } else if (player_.Velocity().x > 0
          && player_right_x - player_.Velocity().x <= platform_left_x) {
        player_.Position().x = platform_left_x - player_.Size().x / 2;
      } else if (player_.Velocity().x < 0
          && player_left_x - player_.Velocity().x >= platform_left_x) {
        player_.Position().x = platform_right_x + player_.Size().x / 2;
      }
    }
  }
}

bool GameEngine::Colliding(const AABB& box1, const AABB& box2) {
  return std::abs(box1.Position().x - box2.Position().x) * 2
      < (box1.Size().x + box2.Size().x)
      && std::abs(box1.Position().y - box2.Position().y) * 2
          < (box1.Size().y + box2.Size().y);
}

ci::vec2 GameEngine::Vec2(const std::vector<float>& v) {
  return ci::vec2(v[0], v[1]);
}

}  // namespace game