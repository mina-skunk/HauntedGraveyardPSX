#include "Sprite.hh"

psyqo::Prim::Sprite16x16* HauntedGraveyard::graphics::Sprite::get_primitive() {
  primitive.setColor(color);
  primitive.texInfo.u = uv.u;
  primitive.texInfo.v = uv.v;
  return &primitive;
}
