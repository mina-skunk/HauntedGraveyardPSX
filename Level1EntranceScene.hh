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
#include "level1_map_detail.h"
#include "level1_map_surface.h"

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
      psyqo::Vec2 spawn_point = { 160.0_fp, 288.0_fp };
      HauntedGraveyard::graphics::Camera2D camera = { { .x = 40.0_fp, .y = 128.0_fp } };
      HauntedGraveyard::graphics::TileMap tile_layer_ground = {
        { .x = 0.0_fp, .y = 0.0_fp },
        { .w = level1_map_WIDTH, .h = level1_map_HEIGHT },
        level1_map,
        { .col = 8, .row = 0 }
      };
      HauntedGraveyard::graphics::TileMap tile_layer_ground_detail = {
        { .x = 0.0_fp, .y = 0.0_fp },
        { .w = level1_map_WIDTH, .h = level1_map_HEIGHT },
        level1_map_detail,
        { .col = 8, .row = 0 }
      };
      HauntedGraveyard::graphics::TileMap tile_layer_surface = {
        { .x = 0.0_fp, .y = 0.0_fp },
        { .w = level1_map_WIDTH, .h = level1_map_HEIGHT },
        level1_map_surface,
        { .col = 8, .row = 0 }
      };
      HauntedGraveyard::Player player = { { .x = 160.0_fp, .y = 288.0_fp } };
      // HauntedGraveyard::GraveKeeper grave_keeper;
      // HauntedGraveyard::Ghost ghost_0;
      
  };
}
