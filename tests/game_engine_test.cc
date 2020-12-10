#include <catch2/catch.hpp>
#include <core/game_engine.h>
#include <visualizer/game_app.h>

TEST_CASE("Level 1") {
  nlohmann::json levels;
  std::ifstream stream(game::visualizer::kLevelsPath);
  stream >> levels;
  game::GameEngine game_engine;
  game_engine.LoadLevel(levels[0]);
  SECTION("Load level") {
    auto level = game_engine.GetLevel();
    std::vector<game::AABB> expected_platforms = {{{20, 1}, {10, 0.5}},
                                                  {{20, 1}, {10, 14.5}},
                                                  {{1, 15}, {0.5, 7.5}},
                                                  {{1, 15}, {19.5, 7.5}},
                                                  {{5, 1}, {10, 5}}};
    REQUIRE(level.size.x == Approx(20));
    REQUIRE(level.size.y == Approx(15));
    REQUIRE(level.platforms == expected_platforms);
    REQUIRE(level.goal == game::AABB({1, 1}, {12, 6}));
  }

  SECTION("Update once") {
    game_engine.Update();
    REQUIRE(game_engine.GetPlayer().Position().x == Approx(3));
    REQUIRE(game_engine.GetPlayer().Position().y == Approx(5.99));
    REQUIRE(game_engine.GetPlayer().Velocity().x == 0);
    REQUIRE(game_engine.GetPlayer().Velocity().y == Approx(-.01));
    REQUIRE(game_engine.GetPlayer().Acceleration().x == 0);
    REQUIRE(game_engine.GetPlayer().Acceleration().y == Approx(-.01));
  }

  for (size_t i = 0; i < 1000; ++i) {
    game_engine.Update();
  }
  SECTION("Player reach ground") {
    REQUIRE(game_engine.GetPlayer().Position().x == Approx(3));
    REQUIRE(game_engine.GetPlayer().Position().y == Approx(1.5));
    REQUIRE(game_engine.GetPlayer().Velocity().x == 0);
    REQUIRE(game_engine.GetPlayer().Velocity().y == 0);
  }
}