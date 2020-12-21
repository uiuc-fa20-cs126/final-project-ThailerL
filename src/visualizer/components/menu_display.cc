#include "visualizer/components/menu_display.h"

namespace game {

namespace visualizer {

MenuDisplay::MenuDisplay(const nlohmann::json& records,
                         const glm::vec2& top_left_corner,
                         const glm::vec2& dimensions) :
    records_(records), Component(top_left_corner, dimensions) {
}

void MenuDisplay::Draw() const {
  ci::Font font("Consolas", 50);
  ci::gl::color(ci::Color("black"));
  for (size_t level = 0; level < records_.size(); ++level) {
    ci::vec2 panel_top_left(top_left_corner_.x + 20 + level * 220,
                            top_left_corner_.y + 20);
    ci::vec2 panel_bot_right(panel_top_left + 200.0f);
    ci::gl::drawStrokedRect({panel_top_left, panel_bot_right});

    ci::gl::drawStringCentered("Level " + std::to_string(level),
                               ci::vec2(panel_top_left.x + 100,
                                        panel_top_left.y + 20),
                               "black",
                               font);
    ci::gl::drawStringCentered("Best:",
                               ci::vec2(panel_top_left.x + 100,
                                        panel_top_left.y + 80),
                               "black",
                               font);
    double record = records_[level];
    ci::gl::drawStringCentered(std::to_string(record),
                               ci::vec2(panel_top_left.x + 100,
                                        panel_top_left.y + 140),
                               "black",
                               font);
  }
}

}  // namespace visualizer

}  // namespace game