#pragma once

#include "EndingScene.hh"
#include "Ghost.hh"
#include "GraveKeeper.hh"
#include "LevelScene.hh"
#include "Player.hh"
#include "graphics/TileMap.hh"

namespace HauntedGraveyard {
/**
 * Level 2
 */
class Level3CryptScene final : public HauntedGraveyard::LevelScene {
  // void start(Scene::StartReason reason) override;
  // void frame() override;
  // void teardown(Scene::TearDownReason reason) override;
  // void update() override;
  // void draw() override;

public:
  Level3CryptScene() : LevelScene({160.0_fp, 288.0_fp}, {{160.0_fp, 16.0_fp}, {16.0_fp, 16.0_fp}}) {}
private:
  // HauntedGraveyard::graphics::TileMap tile_layer_0;
  // HauntedGraveyard::graphics::TileMap tile_layer_1;
  // HauntedGraveyard::Player player;
  // HauntedGraveyard::GraveKeeper grave_keeper;
  // HauntedGraveyard::Ghost ghost_0;
  // HauntedGraveyard::Ghost ghost_1;
  EndingScene next_scene;
  // ...ect
};
}  // namespace HauntedGraveyard
