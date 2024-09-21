#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "Spatial2D.hh"

#define MAX_TILES 255

namespace HauntedGraveyard::graphics {
  struct TileSet {
    uint8_t width, height;
    uint8_t * flags;
  };

  /**
    * Parent of tile sprites. Loads map data.
    */
  class TileMap : public HauntedGraveyard::graphics::Spatial2D  {
    public:

    private:
      uint8_t width, height;
      uint8_t * data;
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, MAX_TILES> fragment;
  };
}
