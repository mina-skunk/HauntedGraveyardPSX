#include "Image.hh"

psyqo::Prim::Sprite* HauntedGraveyard::graphics::UI::Image::get_primitive() {
  primitive.position = position;
  primitive.size = size;
  primitive.setColor(color);
  primitive.texInfo.u = uv.u;
  primitive.texInfo.v = uv.v;
  return &primitive;
}
