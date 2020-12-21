#include "visualizer/components/component.h"

namespace game {

namespace visualizer {

Component::Component(const glm::vec2& top_left_corner,
                     const glm::vec2& dimensions) :
    top_left_corner_(top_left_corner), dimensions_(dimensions) {
}

void Component::DrawFrame(const ci::Color& border,
                          const ci::Color& fill) const {
  ci::Rectf pixel_bounding_box
      (top_left_corner_, top_left_corner_ + dimensions_);
  ci::gl::color(fill);
  ci::gl::drawSolidRect(pixel_bounding_box);
  ci::gl::color(border);
  ci::gl::drawStrokedRect(pixel_bounding_box, 3);
}
void Component::SetLocation(const glm::vec2& top_left_corner,
                            const glm::vec2& dimensions) {
  top_left_corner_ = top_left_corner;
  dimensions_ = dimensions;
}

}  // namespace visualizer

}  // namespace game