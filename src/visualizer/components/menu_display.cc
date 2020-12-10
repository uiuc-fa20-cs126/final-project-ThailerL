#include "visualizer/components/menu_display.h"

namespace game {

namespace visualizer {

MenuDisplay::MenuDisplay(nlohmann::json records,
                         const glm::vec2& top_left_corner,
                         const glm::vec2& dimensions) :
    records_(records), Component(top_left_corner, dimensions) {
}

void MenuDisplay::Draw() const {

}

}  // namespace visualizer

}  // namespace game