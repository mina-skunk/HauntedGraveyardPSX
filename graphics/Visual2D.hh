#pragma once

#include "Spatial2D.hh"
#include "TexturePage.hh"

namespace HauntedGraveyard::graphics {
  class Visual2D : public HauntedGraveyard::graphics::Spatial2D  {
    public:
      HauntedGraveyard::graphics::TexturePage texture_page;
      int32_t z_order = 0;
      Visual2D(psyqo::Vec2 position, HauntedGraveyard::graphics::TexturePage texture_page, int32_t z_order) : Spatial2D(position), texture_page(texture_page), z_order(z_order) {}
  };
}
