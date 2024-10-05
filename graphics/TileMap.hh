#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "Visual2D.hh"
#include "Render2D.hh"
#include "TexturePage.hh"

// max tiles in a layer (15 + 1) * (20 + 1)
#define MAX_TILES 336

#define TILE_SET_WIDTH 16

namespace HauntedGraveyard::graphics {
  struct TileSet {
    uint8_t width, height;
    uint8_t * flags;
  };

  typedef psyqo::Fragments::FixedFragmentWithPrologue<psyqo::Prim::TPage, psyqo::Prim::Sprite16x16, MAX_TILES> TileMapFragment;

  /**
    * Parent of tile sprites. Loads map data.
    */
  class TileMap : public HauntedGraveyard::graphics::Visual2D  {
    friend class Render2D;
    public:
      psyqo::Vertex size;
      const uint8_t * data;
      HauntedGraveyard::graphics::TexturePage texture_page;
      TileMap(psyqo::Vec2 position, HauntedGraveyard::graphics::TexturePage texture_page, int32_t z_order, psyqo::Vertex size, const uint8_t * data) : Visual2D(position, texture_page, z_order), size(size), data(data) {
        for (auto & fragment : fragments) {
          fragment.count = MAX_TILES;
          texture_page.get_primative(&fragment.prologue);
        }
      }
    private:
      TileMapFragment fragments[2];
      TileMapFragment *get_fragment(uint8_t buffer_index);
  };
} // namespace HauntedGraveyard::graphics
