#pragma  once

#include "cinder/gl/gl.h"
#include "component.h"

namespace game {

namespace visualizer {

/*
 * Stores different layouts that a Panel can display components with.
 */
enum class Layout {
  kHorizontal,
  kVertical
};

/*
 * Represents a panel that can hold other Components of any sub-type. The
 * panel manages the display of the components within.
 */
class Panel : public Component {
 public:
  /*
   * Constructs a panel with a layout and margin between component.
   */
  Panel(Layout layout = Layout::kHorizontal,
        float margin = 0,
        const glm::vec2& = {},
        const glm::vec2& dimensions = {});

  /*
   * Add a component to the panel through a std::unique_ptr. Once added, the
   * ownership of the component is transferred to the panel and the panel
   * manages its location.
   */
  void Add(std::unique_ptr<Component> component);

  /*
   * Draws the panel with all components within it separated by the margin.
   */
  void Draw() const override;

 private:
  Layout layout_;
  float margin_;
  std::vector<std::unique_ptr<Component>> components_;
};

}  // namespace visualizer

}  // namespace game
