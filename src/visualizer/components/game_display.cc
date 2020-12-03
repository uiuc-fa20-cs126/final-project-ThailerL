#include <visualizer/components/game_display.h>

namespace game {

namespace visualizer {

using glm::vec2;

GameDisplay::GameDisplay(const GameEngine& game_engine,
                         const vec2& top_left_corner,
                         const vec2& dimensions)
    : game_engine_(game_engine), Component(top_left_corner, dimensions) {
}

void GameDisplay::Draw() const {
  ci::gl::color(ci::Color("red"));
  DrawAABB(game_engine_.GetPlayer());
  ci::gl::color(ci::Color("black"));
  for (const auto& platform : game_engine_.GetLevel().platforms) {
    DrawAABB(platform);
  }
  ci::gl::color(ci::Color("blue"));
  DrawAABB(game_engine_.GetLevel().goal);
}

void GameDisplay::DrawAABB(const AABB& box) const {
  ci::vec2 scale_factor = dimensions_ / game_engine_.GetLevel().size;
  ci::vec2 position = box.Position() * scale_factor;
  position.y = dimensions_.y - position.y;
  ci::vec2 top_left(position - box.Size() * scale_factor / 2.0f);
  ci::vec2 bot_right = top_left + box.Size() * scale_factor;
  ci::gl::drawSolidRect(ci::Rectf(top_left, bot_right));
}

}  // namespace visualizer

}  // namespace game
