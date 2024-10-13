#include "Pixel.hh"

HauntedGraveyard::graphics::PixelFragment* HauntedGraveyard::graphics::Pixel::get_fragment(uint8_t buffer_index) {
  return &fragments[buffer_index];
}
