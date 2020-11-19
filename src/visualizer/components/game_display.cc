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
}

}  // namespace visualizer

}  // namespace game
