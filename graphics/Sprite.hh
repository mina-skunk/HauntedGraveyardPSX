#pragma once

#include "psyqo/primitives.hh"
#include "Spatial2D.hh"
#include "Render2D.hh"
#include "TexturePage.hh"

namespace HauntedGraveyard::graphics {
  /**
    * Small sprite in 2d space 
    */
  class Sprite : public HauntedGraveyard::graphics::Spatial2D  {
    friend class Render2D;
    public:
      HauntedGraveyard::graphics::TexturePage texture_page;
      psyqo::Color color = { .r = 0xFF, .g = 0xFF, .b = 0xFF };
      psyqo::Vertex uv = { 0, 0 };
      Sprite(psyqo::Vec2 position, HauntedGraveyard::graphics::TexturePage texture_page) : Spatial2D(position), texture_page(texture_page) {}
    private:
      psyqo::Prim::Sprite16x16 primitive;
      psyqo::Prim::Sprite16x16 *get_primitive();
  };
}
