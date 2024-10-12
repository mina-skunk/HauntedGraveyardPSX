#pragma once

#include "psyqo/vector.hh"
#include "core/Area.hh"

namespace HauntedGraveyard {
class Character : public HauntedGraveyard::core::Area2D {
public:
  enum Orientation {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };
  Orientation orientation = Orientation::DOWN;
  bool is_moving = false;
  Character(psyqo::Vec2 position, psyqo::Vec2 size) : HauntedGraveyard::core::Area2D(position, size) {

  }
};
}  // namespace HauntedGraveyard
