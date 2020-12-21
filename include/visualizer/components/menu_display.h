#pragma once

#include "component.h"
#include <json.hpp>

namespace game {

namespace visualizer {

class MenuDisplay : public Component {
 public:
  MenuDisplay(const nlohmann::json& records,
              const glm::vec2& top_left_corner = {},
              const glm::vec2& dimensions = {});

  void Draw() const override;

 private:
  const nlohmann::json& records_;
};

}  // namespace visualizer

}  // namespace game