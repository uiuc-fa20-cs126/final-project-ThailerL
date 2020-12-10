#include "visualizer/components/menu_display.h"

namespace game {

namespace visualizer {

MenuDisplay::MenuDisplay(nlohmann::json game_info,
                         const glm::vec2& top_left_corner,
                         const glm::vec2& dimensions) :
    game_info_(game_info), Component(top_left_corner, dimensions) {
}

void MenuDisplay::Draw() const {

}

}  // namespace visualizer

}  // namespace game