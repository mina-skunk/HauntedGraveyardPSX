#pragma once

#include "Ghost.hh"
#include "GraveKeeper.hh"
#include "Level3CryptScene.hh"
#include "LevelScene.hh"
#include "Player.hh"
#include "graphics/TileMap.hh"

namespace HauntedGraveyard {
/**
 * Level 2
 */
class Level2GraveyardScene final : public HauntedGraveyard::LevelScene {
  // void start(Scene::StartReason reason) override;
  // void frame() override;
  // void teardown(Scene::TearDownReason reason) override;
  // void update() override;
  // void draw() override;

public:
  // TODO
private:
  // HauntedGraveyard::graphics::TileMap tile_layer_0;
  // HauntedGraveyard::graphics::TileMap tile_layer_1;
  // HauntedGraveyard::Player player;
  // HauntedGraveyard::GraveKeeper grave_keeper;
  // HauntedGraveyard::Ghost ghost_0;
  // HauntedGraveyard::Ghost ghost_1;
  Level3CryptScene next_scene;
  // ...ect
};
}  // namespace HauntedGraveyard
