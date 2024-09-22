#pragma once

#include "graphics/Camera2D.hh"
#include "psyqo/scene.hh"
#include "graphics/TileMap.hh"
#include "Player.hh"
#include "GraveKeeper.hh"
#include "Ghost.hh"

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
      HauntedGraveyard::graphics::Camera2D camera;
      // HauntedGraveyard::graphics::TileMap tile_layer_0;
      // HauntedGraveyard::graphics::TileMap tile_layer_1;
      // HauntedGraveyard::Player player;
      // HauntedGraveyard::GraveKeeper grave_keeper;
      // HauntedGraveyard::Ghost ghost_0;
  };
}
