#pragma once

#include "Render2D.hh"
#include "TexturePage.hh"
#include "Visual2D.hh"
#include "common.hh"
#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"

// max tiles in a layer (15 + 2) * (20 + 2)
#define MAX_TILES 374

#define TILE_SET_WIDTH 16

namespace HauntedGraveyard::graphics {
struct TileSet {
  uint8_t width, height;
  uint8_t* flags;
};

/**
 * Parent of tile sprites. Loads map data.
 */
class TileMap : public HauntedGraveyard::graphics::Visual2D {
  friend class Render2D;

public:
  psyqo::Vertex size;
  const uint8_t* data;
  TileMap(psyqo::Vec2 position, HauntedGraveyard::graphics::TexturePage texture_page, int32_t z_order, psyqo::Vertex size, const uint8_t* data) : Visual2D(position, texture_page, z_order), size(size), data(data) {
    for (auto& sprite_fragment_buffer : sprite_fragments) {
      for (auto& sprite_fragment : sprite_fragment_buffer) {
        texture_page.get_primative(&sprite_fragment.primitive.t_page);
      }
    }
  }

private:
  SpriteFragment sprite_fragments[2][MAX_TILES];
};
}  // namespace HauntedGraveyard::graphics
