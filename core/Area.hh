#pragma once

#include "Shape.hh"
#include "psyqo/vector.hh"

namespace HauntedGraveyard::core {
/**
 * Area in 2d space
 */
class Area2D : public Rectangle {
public:
  Area2D(psyqo::Vec2 position, psyqo::Vec2 size) : Rectangle(position, size) {}
  bool check_overlap(psyqo::Vec2 point);
  bool check_overlap(Area2D area_b);
};
}  // namespace HauntedGraveyard::core
