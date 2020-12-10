#include <catch2/catch.hpp>
#include <core/aabb.h>

TEST_CASE("No movement") {
  game::AABB aabb({2,2}, {4,3}, {0, 0}, {0, 0});
  aabb.Update();
  REQUIRE(aabb.Position().x == Approx(4));
  REQUIRE(aabb.Position().y == Approx(3));
}

TEST_CASE("Constant velocity") {
  game::AABB aabb({2,2}, {4,3}, {2, 3}, {0, 0});
  aabb.Update();
  REQUIRE(aabb.Position().x == Approx(6));
  REQUIRE(aabb.Position().y == Approx(6));
  aabb.Update();
  REQUIRE(aabb.Position().x == Approx(8));
  REQUIRE(aabb.Position().y == Approx(9));
}

TEST_CASE("Acceleration") {
  game::AABB aabb({2,2}, {4,3}, {2, 3}, {1, 2});
  aabb.Update();
  REQUIRE(aabb.Velocity().x == Approx(3));
  REQUIRE(aabb.Velocity().y == Approx(5));
  REQUIRE(aabb.Position().x == Approx(7));
  REQUIRE(aabb.Position().y == Approx(8));
  aabb.Update();
  REQUIRE(aabb.Velocity().x == Approx(4));
  REQUIRE(aabb.Velocity().y == Approx(7));
  REQUIRE(aabb.Position().x == Approx(11));
  REQUIRE(aabb.Position().y == Approx(15));
}