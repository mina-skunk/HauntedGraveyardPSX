#include "Sprite.hh"

void HauntedGraveyard::graphics::Sprite::modulate_color(psyqo::Color color) {
  fragment.primitive.sprite.setColor(color);
}

psyqo::Fragments::SimpleFragment<HauntedGraveyard::graphics::SpriteBlock>* HauntedGraveyard::graphics::Sprite::get_fragment() {
  fragment.primitive.sprite.texInfo.u = uv.u;
  fragment.primitive.sprite.texInfo.v = uv.v;
  return &fragment;
}
