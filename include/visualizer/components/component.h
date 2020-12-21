#pragma  once

#include "cinder/gl/gl.h"

namespace game {

namespace visualizer {

/*
 * Represents a GUI component that can be placed by the user or managed by
 * another component.
 */
class Component {
 public:
  /*
   * Sets the location and dimensions of the component.
   */
  Component(const glm::vec2& top_left_corner = {},
            const glm::vec2& dimensions = {});

  /*
   * Draws the component within the bounds of the dimensions.
   */
  virtual void Draw() const = 0;

  /*
   * Sets the location and dimensions of the component.
   */
  void SetLocation(const glm::vec2& top_left_corner,
                   const glm::vec2& dimensions);

 protected:
  glm::vec2 top_left_corner_;
  glm::vec2 dimensions_;

  /*
   * Draws the frame and background filling where the component is.
   */
  void DrawFrame(const ci::Color& border = "black",
                 const ci::Color& fill = "white") const;
};

}  // namespace visualizer

}  // namespace game
