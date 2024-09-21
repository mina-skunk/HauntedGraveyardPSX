#include "Image.hh"

psyqo::Prim::Sprite* HauntedGraveyard::graphics::UI::Image::get_primitive() {
  primitive.position = position;
  primitive.size = size;
  return &primitive;
}
