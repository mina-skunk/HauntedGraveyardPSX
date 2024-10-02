#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "Spatial2D.hh"
#include "Render2D.hh"
#include "TexturePage.hh"

#define MAX_TILES 512
#define TILE_SET_WIDTH 16

namespace HauntedGraveyard::graphics {
  struct TileSet {
    uint8_t width, height;
    uint8_t * flags;
  };

  /**
    * Parent of tile sprites. Loads map data.
    */
  class TileMap : public HauntedGraveyard::graphics::Spatial2D  {
    friend class Render2D;
    public:
      psyqo::Vertex size;
      const uint8_t * data;
      HauntedGraveyard::graphics::TexturePage texture_page;
      TileMap(psyqo::Vec2 position, psyqo::Vertex size, const uint8_t * data, HauntedGraveyard::graphics::TexturePage texture_page) : Spatial2D(position), size(size), data(data), texture_page(texture_page) {}
    private:
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, MAX_TILES> fragment;
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, MAX_TILES> *get_fragment();
  };
} // namespace HauntedGraveyard::graphics
