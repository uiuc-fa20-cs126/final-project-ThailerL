#pragma once

#include "component.h"
#include <json.hpp>

namespace game {

namespace visualizer {

class MenuDisplay : public Component {
 public:
  MenuDisplay(nlohmann::json game_info,
              const glm::vec2& top_left_corner = {},
              const glm::vec2& dimensions = {});

  void Draw() const override;

 private:
  const nlohmann::json& game_info_;
};

}  // namespace visualizer

}  // namespace game