#include "TileMap.hh"

psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, MAX_TILES> *HauntedGraveyard::graphics::TileMap::get_fragment() {
  fragment.count = size.w * size.h;
  return &fragment;
}
