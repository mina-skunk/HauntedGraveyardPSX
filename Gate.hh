#pragma once

#include "core/Area.hh"
#include "graphics/BigSprite.hh"
#include "psyqo/fixed-point.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
class Gate : public HauntedGraveyard::core::Area2D {
public:
  bool open = false;
  HauntedGraveyard::graphics::BigSprite sprite;
  Gate(psyqo::Vec2 position, HauntedGraveyard::graphics::BigSprite sprite) : HauntedGraveyard::core::Area2D(position, {16.0_fp, 16.0_fp}), sprite(sprite) {}
};
}  // namespace HauntedGraveyard
