#pragma once

#include "psyqo/vector.hh"
#include "core/Area.hh"

namespace HauntedGraveyard {
class Character : public Area<2> {
public:
  enum Orientation {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };
  Orientation orientation = Orientation::DOWN;
  bool is_moving = false;
  Character(psyqo::Vec2 position, psyqo::Vec2 size) : Area<2>(position, size) {

  }
};
}  // namespace HauntedGraveyard
