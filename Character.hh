#pragma once

#include "psyqo/vector.hh"

namespace HauntedGraveyard {
class Character {
public:
  enum Orientation {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };
  psyqo::Vec2 position;
  Orientation orientation = Orientation::DOWN;
  bool is_moving = false;
  Character(psyqo::Vec2 position) : position(position) {}
  virtual void update() {}
};
}  // namespace HauntedGraveyard
