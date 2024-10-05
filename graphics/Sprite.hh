#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "Visual2D.hh"
#include "Render2D.hh"
#include "TexturePage.hh"
#include "psyqo/primitives/common.hh"

namespace HauntedGraveyard::graphics {
  struct SpriteBlock {
    psyqo::Prim::TPage t_page;
    psyqo::Prim::Sprite16x16 sprite;
  };
  typedef psyqo::Fragments::SimpleFragment<SpriteBlock> SpriteFragment;
  /**
    * Small sprite in 2d space 
    */
  class Sprite : public HauntedGraveyard::graphics::Visual2D  {
    friend class Render2D;
    public:
      psyqo::PrimPieces::UVCoords uv = { 0, 0 };
      Sprite(psyqo::Vec2 position, HauntedGraveyard::graphics::TexturePage texture_page, int32_t z_order) : Visual2D(position, texture_page, z_order) {
        for (auto & fragment : fragments) {
          texture_page.get_primative(&fragment.primitive.t_page);
          fragment.primitive.sprite.texInfo.u = uv.u;
          fragment.primitive.sprite.texInfo.v = uv.v;
        }
      }
      void modulate_color(psyqo::Color color);
    private:
      SpriteFragment fragments[2];
      SpriteFragment *get_fragment(uint8_t buffer_index);
  };
}
