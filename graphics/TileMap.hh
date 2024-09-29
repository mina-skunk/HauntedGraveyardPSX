#pragma once

#include <EASTL/array.h>
#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "Spatial2D.hh"
#include "Render2D.hh"
#include "TexturePage.hh"

#define MAX_TILES 255

namespace HauntedGraveyard::graphics {
  struct TileSet {
    uint8_t width, height;
    uint8_t * flags;
  };

  /**
    * Parent of tile sprites. Loads map data.
    */
  // template<size_t W, size_t H>
  class TileMap : public HauntedGraveyard::graphics::Spatial2D  {
    friend class Render2D;
    public:
      TileMap(psyqo::Vec2 position, psyqo::Vertex size, const uint8_t * data, HauntedGraveyard::graphics::TexturePage texture_page) : Spatial2D(position), size(size), data(data), texture_page(texture_page) {}
    private:
      // eastl::array<HauntedGraveyard::graphics::Sprite, MAX_TILES> tiles;
      psyqo::Vertex size;
      const uint8_t * data;
      HauntedGraveyard::graphics::TexturePage texture_page;
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, MAX_TILES> fragment;
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, MAX_TILES> *get_fragment();
  };
}
