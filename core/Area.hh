#pragma once

#include "Shape.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
/**
 * Area in 2d space
 */
template <unsigned N>
  requires((N >= 2) && (N <= 4))
class Area : public Shape<N> {
public:
  Area(psyqo::Vector<N> position, psyqo::Vector<N> size) : Shape<N>(position, size) {}
  bool check_overlap(psyqo::Vec2 point);
  bool check_overlap(Area<N> area_b);
};
typedef Area<2> Area2D;
}  // namespace HauntedGraveyard
