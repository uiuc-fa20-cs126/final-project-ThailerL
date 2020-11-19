#include <core/player.h>

namespace game {

Player::Player(ci::vec2 center, ci::vec2 half_size, ci::Color color)
    : AABB(center, half_size), color_(color) {
}

}  // namespace game