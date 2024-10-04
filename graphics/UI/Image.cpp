#include "Image.hh"

void HauntedGraveyard::graphics::UI::Image::modulate_color(psyqo::Color color) {
  for (auto & fragment : fragments) {
    fragment.primitive.sprite.setColor(color);
  }
}

HauntedGraveyard::graphics::UI::ImageFragment* HauntedGraveyard::graphics::UI::Image::get_fragment(uint8_t buffer_index) {
  fragments[buffer_index].primitive.sprite.position = position;
  fragments[buffer_index].primitive.sprite.size = size;
  fragments[buffer_index].primitive.sprite.texInfo.u = uv.u;
  fragments[buffer_index].primitive.sprite.texInfo.v = uv.v;
  return &fragments[buffer_index];
}
