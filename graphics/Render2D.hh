#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/gpu.hh"
#include "psyqo/ordering-table.hh"
#include "psyqo/primitives/common.hh"
#include "psyqo/vector.hh"

#define LAYERS_COUNT 8
#define MAX_Z LAYERS_COUNT - 1

namespace HauntedGraveyard::graphics {
class Camera2D;
class Sprite;
class TileMap;
class BigSprite;
/**
 * Handles generating primatives / framgments for objects in 2d space
 */
class Render2D {
public:
  static void init(psyqo::GPU *gpu_);
  /**
   * Sets current active Camera2D
   */
  static void set_camera(HauntedGraveyard::graphics::Camera2D *camera);
  static void draw_sprite(HauntedGraveyard::graphics::Sprite *sprite);
  static void draw_tilemap(HauntedGraveyard::graphics::TileMap *tilemap);
  static void draw_bigsprite(HauntedGraveyard::graphics::BigSprite *sprite);
  static void draw_background(psyqo::Color color);
  static void finish_drawing();

private:
  static psyqo::GPU *gpu;
  static HauntedGraveyard::graphics::Camera2D *active_camera;
  static psyqo::OrderingTable<LAYERS_COUNT> ordering_tables[2];
  static psyqo::Fragments::SimpleFragment<psyqo::Prim::FastFill> background_fragments[2];
  static psyqo::Vec2 get_relative_position(psyqo::Vec2 world_position);
};
}  // namespace HauntedGraveyard::graphics
