#include "Image.hh"

void HauntedGraveyard::graphics::UI::Image::modulate_color(psyqo::Color color) {
  primitive.setColor(color);
}

psyqo::Prim::Sprite* HauntedGraveyard::graphics::UI::Image::get_primitive() {
  primitive.position = position;
  primitive.size = size;
  primitive.texInfo.u = uv.u;
  primitive.texInfo.v = uv.v;
  return &primitive;
}
