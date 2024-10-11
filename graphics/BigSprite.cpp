#include "BigSprite.hh"

HauntedGraveyard::graphics::BigSpriteFragment* HauntedGraveyard::graphics::BigSprite::get_fragment(uint8_t buffer_index) {
  fragments[buffer_index].primitive.sprite.texInfo.u = uv.u;
  fragments[buffer_index].primitive.sprite.texInfo.v = uv.v;
  fragments[buffer_index].primitive.sprite.size.x = size.x;
  fragments[buffer_index].primitive.sprite.size.y = size.y;
  return &fragments[buffer_index];
}
