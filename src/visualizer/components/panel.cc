#include "cinder/gl/gl.h"
#include "visualizer/components/panel.h"

namespace game {

namespace visualizer {

Panel::Panel(Layout layout,
             float margin,
             const glm::vec2& top_left_corner,
             const glm::vec2& dimensions)
    : layout_(layout), margin_(margin), Component(top_left_corner, dimensions) {
}

void Panel::Draw() const {

  for (size_t i = 0; i < components_.size(); ++i) {
    glm::vec2 comp_dim;
    glm::vec2 top_left;
    switch (layout_) {
      case Layout::kHorizontal:
        comp_dim.x = (dimensions_.x - (margin_ * (components_.size() - 1.0f)))
            / components_.size();
        comp_dim.y = dimensions_.y;
        top_left.x = top_left_corner_.x + i * (comp_dim.x + margin_);
        top_left.y = top_left_corner_.y;
        break;
      case Layout::kVertical:
        comp_dim.x = dimensions_.x;
        comp_dim.y = (dimensions_.y - (margin_ * (components_.size() - 1.0f)))
            / components_.size();
        top_left.x = top_left_corner_.x;
        top_left.y = top_left_corner_.y + i * (comp_dim.y + margin_);
        break;
    }
    components_[i]->SetLocation(top_left, comp_dim);
  }

  for (const auto& component : components_) {
    component->Draw();
  }
}
void Panel::Add(std::unique_ptr<Component> component) {
  components_.push_back(std::move(component));
}

}  // namespace visualizer

}  // namespace game
