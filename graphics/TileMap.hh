#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "Spatial2D.hh"
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
  class TileMap : public HauntedGraveyard::graphics::Spatial2D  {
    friend class Render2D;
    public:
      psyqo::Vertex size;
      const uint8_t * data;
      HauntedGraveyard::graphics::TexturePage texture_page;
      inline TileMap(psyqo::Vec2 position, psyqo::Vertex size, const uint8_t * data, HauntedGraveyard::graphics::TexturePage texture_page) : Spatial2D(position), size(size), data(data), texture_page(texture_page) {
        fragment.count = MAX_TILES;
        texture_page.get_primative(&fragment.prologue);
      }
    private:
      TileMapFragment fragment;
  };
} // namespace HauntedGraveyard::graphics
