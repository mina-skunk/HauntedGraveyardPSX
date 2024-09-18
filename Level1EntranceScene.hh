#pragma once

#include "psyqo/scene.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
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
      HauntedGraveyard::graphics::TileMap tile_layer_0;
      HauntedGraveyard::graphics::TileMap tile_layer_1;
      HauntedGraveyard::Player player;
      HauntedGraveyard::GraveKeeper grave_keeper;
      HauntedGraveyard::Ghost ghost_0;
  };
}
