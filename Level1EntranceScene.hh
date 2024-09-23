#pragma once

#include "psyqo/fixed-point.hh"
#include "psyqo/scene.hh"
#include "graphics/Camera2D.hh"
#include "graphics/TileMap.hh"
#include "Player.hh"
#include "GraveKeeper.hh"
#include "Ghost.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
  /**
   * Level 1
   */
  class Level1EntranceScene final : public psyqo::Scene {
      void start(Scene::StartReason reason) override;
      void frame() override;
      void teardown(Scene::TearDownReason reason) override;

    public:

    private:
      HauntedGraveyard::graphics::Camera2D camera = { { .x = 0.0_fp, .y = 0.0_fp } };
      // HauntedGraveyard::graphics::TileMap tile_layer_0;
      // HauntedGraveyard::graphics::TileMap tile_layer_1;
      HauntedGraveyard::Player player = { { .x = 0.0_fp, .y = 0.0_fp }, { .col = 8, .row = 1 } };
      // HauntedGraveyard::GraveKeeper grave_keeper;
      // HauntedGraveyard::Ghost ghost_0;
      void update();
  };
}
