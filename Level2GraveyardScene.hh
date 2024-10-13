#pragma once

#include "Ghost.hh"
#include "GraveKeeper.hh"
#include "Level3CryptScene.hh"
#include "LevelScene.hh"
#include "Player.hh"
#include "graphics/Camera2D.hh"
#include "graphics/TileMap.hh"
#include "level2_map_detail.h"
#include "level2_map_ground.h"
#include "level2_map_surface.h"

namespace HauntedGraveyard {
/**
 * Level 2
 */
class Level2GraveyardScene final : public HauntedGraveyard::LevelScene {
  void start(Scene::StartReason reason) override;
  void teardown(Scene::TearDownReason reason) override;
  void update() override;
  void draw() override;

public:
  Level2GraveyardScene() : LevelScene({224.0_fp, 448.0_fp}, {{64.0_fp, 128.0_fp}, {16.0_fp, 16.0_fp}}) {}

private:
  HauntedGraveyard::graphics::Camera2D camera = {{.x = 64.0_fp, .y = 328.0_fp}};
  HauntedGraveyard::graphics::TileMap tile_layers[3] = {
      {{.x = 0.0_fp, .y = 0.0_fp},
       {.col = 8, .row = 0},
       6,
       {.w = level2_map_ground_WIDTH, .h = level2_map_ground_HEIGHT},
       level2_map_ground},
      {{.x = 0.0_fp, .y = 0.0_fp},
       {.col = 8, .row = 0},
       5,
       {.w = level2_map_ground_WIDTH, .h = level2_map_ground_HEIGHT},
       level2_map_detail},
      {{.x = 0.0_fp, .y = 0.0_fp},
       {.col = 8, .row = 0},
       4,
       {.w = level2_map_ground_WIDTH, .h = level2_map_ground_HEIGHT},
       level2_map_surface}};
  // HauntedGraveyard::GraveKeeper grave_keeper;
  // HauntedGraveyard::Ghost ghost_0;
  // HauntedGraveyard::Ghost ghost_1;
  Level3CryptScene next_scene;
  // ...ect
};
}  // namespace HauntedGraveyard
