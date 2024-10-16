#pragma once

#include "core/Area.hh"
#include "graphics/BigSprite.hh"

namespace HauntedGraveyard {
class Grave : public HauntedGraveyard::core::Area2D {
public:
  HauntedGraveyard::graphics::BigSprite sprite = {position, {.col = 8, .row = 0}, 6, {16, 48}};
  Grave(psyqo::Vec2 position) : Area2D(position, {16.0_fp, 48.0_fp}) {}
};
}  // namespace HauntedGraveyard
