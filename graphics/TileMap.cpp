#include "TileMap.hh"

psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, MAX_TILES> *HauntedGraveyard::graphics::TileMap::get_fragment() {
  fragment.count = size.w * size.h;

  uint8_t map_index = 0;
  for (uint8_t y = 0; y < size.h; y++) {
    for (uint8_t x = 0; x < size.w; x++) {
      fragment.primitives[map_index].setColor({ .r = 0x80, .g = 0x80, .b = 0x80 });
      // TODO
    }
  }
  return &fragment;
}
