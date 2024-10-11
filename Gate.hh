#pragma once

#include "Area.hh"
#include "graphics/BigSprite.hh"

namespace HauntedGraveyard {
struct Gate {
public:
  bool open = false;
  HauntedGraveyard::graphics::BigSprite sprite;
  HauntedGraveyard::Area solid_area;
  Gate(HauntedGraveyard::graphics::BigSprite sprite, HauntedGraveyard::Area solid_area) : sprite(sprite), solid_area(solid_area) {}
};
}  // namespace HauntedGraveyard
