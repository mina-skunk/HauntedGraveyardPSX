#include "Area.hh"

#include "psyqo/vector.hh"

bool HauntedGraveyard::core::Area2D::check_overlap(psyqo::Vec2 point) {
  return point.x > position.x &&
         point.x < position.x + size.x &&
         point.y > position.y &&
         point.y < position.y + size.y;
}

bool HauntedGraveyard::core::Area2D::check_overlap(Area2D area_b) {
  return area_b.position.x + area_b.size.x > position.x &&
         area_b.position.x < position.x + size.x &&
         area_b.position.y + area_b.size.y > position.y &&
         area_b.position.y < position.y + size.y;
}