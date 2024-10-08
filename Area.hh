#pragma once

#include "psyqo/vector.hh"

namespace HauntedGraveyard {
/**
 * Area in 2d space
 */
struct Area {
public:
  psyqo::Vec2 position;
  psyqo::Vec2 size;
  bool check_overlap(psyqo::Vec2 point);
  bool check_overlap(Area area_b);
};
}  // namespace HauntedGraveyard
