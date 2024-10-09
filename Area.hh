#pragma once

#include "psyqo/fixed-point.hh"
#include "psyqo/vector.hh"

using namespace psyqo::fixed_point_literals;

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
private:
  // TODO is there a better way
  // static psyqo::FixedPoint<> wiggle_room;
};
}  // namespace HauntedGraveyard
