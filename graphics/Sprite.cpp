#include "Sprite.hh"

void HauntedGraveyard::graphics::Sprite::modulate_color(psyqo::Color color) {
  for (auto& fragment : fragments) {
    fragment.primitive.sprite.setColor(color);
  }
}

HauntedGraveyard::graphics::SpriteFragment* HauntedGraveyard::graphics::Sprite::get_fragment(uint8_t buffer_index) {
  fragments[buffer_index].primitive.sprite.texInfo.u = uv.u;
  fragments[buffer_index].primitive.sprite.texInfo.v = uv.v;
  return &fragments[buffer_index];
}
