#pragma once

#include "psyqo/fixed-point.hh"
#include "psyqo/scene.hh"
#include "graphics/Camera2D.hh"
#include "graphics/TileMap.hh"
#include "Player.hh"
#include "GraveKeeper.hh"
#include "Ghost.hh"
#include "LevelScene.hh"
#include "level1_map.h"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
  /**
   * Level 1
   */
  class Level1EntranceScene final : public HauntedGraveyard::LevelScene {
      void start(Scene::StartReason reason) override;
      void frame() override;
      void teardown(Scene::TearDownReason reason) override;
      void update() override;
      void draw() override;

    public:

    private:
      HauntedGraveyard::graphics::Camera2D camera = { { .x = 0.0_fp, .y = 0.0_fp } };
      HauntedGraveyard::graphics::TileMap tile_layer_0 = {
        { .x = 0.0_fp, .y = 0.0_fp },
        { .w = level1_map_WIDTH, .h = level1_map_HEIGHT },
        level1_map,
        { .col = 8, .row = 0 }
      };
      // HauntedGraveyard::graphics::TileMap tile_layer_1;
      HauntedGraveyard::Player player = { { .x = 16.0_fp, .y = 16.0_fp } };
      // HauntedGraveyard::GraveKeeper grave_keeper;
      // HauntedGraveyard::Ghost ghost_0;
      
  };
}
