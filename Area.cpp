#include "Area.hh"

// psyqo::FixedPoint<> HauntedGraveyard::Area::wiggle_room = 0.1_fp;

bool HauntedGraveyard::Area::check_overlap(psyqo::Vec2 point) {
  return point.x > position.x &&
         point.x < position.x + size.x &&
         point.y > position.y &&
         point.y < position.y + size.y;
}

bool HauntedGraveyard::Area::check_overlap(Area area_b) {
  return area_b.position.x + area_b.size.x > position.x &&
         area_b.position.x < position.x + size.x &&
         area_b.position.y + area_b.size.y > position.y &&
         area_b.position.y < position.y + size.y;
}