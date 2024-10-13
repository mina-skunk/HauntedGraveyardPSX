#pragma once

#include "Gate.hh"
#include "Ghost.hh"
#include "GraveKeeper.hh"
#include "JackOLantern.hh"
#include "Level2GraveyardScene.hh"
#include "LevelScene.hh"
#include "core/Area.hh"
#include "graphics/Camera2D.hh"
#include "graphics/TileMap.hh"
#include "level1_map_ground.h"
#include "level1_map_detail.h"
#include "level1_map_surface.h"
#include "psyqo/fixed-point.hh"
#include "psyqo/scene.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
/**
 * Level 1
 */
class Level1EntranceScene final : public HauntedGraveyard::LevelScene {
  void start(Scene::StartReason reason) override;
  void teardown(Scene::TearDownReason reason) override;
  void update() override;
  void draw() override;

public:
  Level1EntranceScene() : LevelScene({160.0_fp, 288.0_fp}, {{160.0_fp, 16.0_fp}, {16.0_fp, 16.0_fp}}) {
    gate.sprite.uv.u = 160;
    gate.sprite.uv.v = 0;
  }

private:
  HauntedGraveyard::graphics::Camera2D camera = {{.x = 40.0_fp, .y = 128.0_fp}};
  HauntedGraveyard::graphics::TileMap tile_layers[3] = {
      {{.x = 0.0_fp, .y = 0.0_fp},
       {.col = 8, .row = 0},
       6,
       {.w = level1_map_ground_WIDTH, .h = level1_map_ground_HEIGHT},
       level1_map_ground},
      {{.x = 0.0_fp, .y = 0.0_fp},
       {.col = 8, .row = 0},
       5,
       {.w = level1_map_ground_WIDTH, .h = level1_map_ground_HEIGHT},
       level1_map_detail},
      {{.x = 0.0_fp, .y = 0.0_fp},
       {.col = 8, .row = 0},
       4,
       {.w = level1_map_ground_WIDTH, .h = level1_map_ground_HEIGHT},
       level1_map_surface}};
  HauntedGraveyard::GraveKeeper grave_keeper = {
      {.x = 128.0_fp, .y = 240.0_fp},
      {"The gate to the Graveyard is locked.", "Search the area for the key."},
      {"Good luck in the Graveyard.", "Beware the wandering spirits!"}};
  // HauntedGraveyard::Ghost ghost_0;
  Level2GraveyardScene next_scene;
  HauntedGraveyard::core::Area2D world_bounds = {
      { .x = 0.0_fp, .y = 16.0_fp},
      { .x = 320.0_fp, .y = 320.0_fp}};
  HauntedGraveyard::core::Area2D fences[2] = {
      {{0.0_fp, 32.0_fp},
       {158.0_fp, 16.0_fp}},
      {{178.0_fp, 32.0_fp},
       {142.0_fp, 16.0_fp}}};
  HauntedGraveyard::JackOLantern jack_o_lanterns[6] = {
      {{128.0_fp, 48.0_fp}},
      {{192.0_fp, 48.0_fp}},
      {{64.0_fp, 96.0_fp}},
      {{96.0_fp, 128.0_fp}},
      {{48.0_fp, 240.0_fp}},
      {{208.0_fp, 240.0_fp}}};
  HauntedGraveyard::JackOLantern jack_o_lantern_with_key = {{240.0_fp, 112.0_fp}, true};
  HauntedGraveyard::Gate gate = {
      {160.0_fp, 32.0_fp},
      {{144.0_fp, 0.0_fp}, {.col = 8, .row = 0}, 4, {32, 48}}};
};
}  // namespace HauntedGraveyard
