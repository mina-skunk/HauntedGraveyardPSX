#pragma once

#include "Render2D.hh"
#include "TexturePage.hh"
#include "Visual2D.hh"
#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "psyqo/primitives/sprites.hh"

namespace HauntedGraveyard::graphics {
struct BigSpriteBlock {
  psyqo::Prim::TPage t_page;
  psyqo::Prim::Sprite sprite;
};
typedef psyqo::Fragments::SimpleFragment<BigSpriteBlock> BigSpriteFragment;
/**
 * Big sprite in 2d space
 */
class BigSprite : public HauntedGraveyard::graphics::Visual2D {
  friend class Render2D;

public:
  psyqo::Vertex size;
  psyqo::PrimPieces::UVCoords uv = {0, 0};
  BigSprite(psyqo::Vec2 position, HauntedGraveyard::graphics::TexturePage texture_page, int32_t z_order, psyqo::Vertex size) : Visual2D(position, texture_page, z_order), size(size) {
    for (auto &fragment : fragments) {
      texture_page.get_primative(&fragment.primitive.t_page);
      fragment.primitive.sprite.texInfo.u = uv.u;
      fragment.primitive.sprite.texInfo.v = uv.v;
    }
  }

private:
  BigSpriteFragment fragments[2];
  BigSpriteFragment *get_fragment(uint8_t buffer_index);
};
}  // namespace HauntedGraveyard::graphics
