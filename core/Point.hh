#pragma once

#include "GameObject.hh"
#include "psyqo/vector.hh"

namespace HauntedGraveyard {
template <unsigned N>
  requires((N >= 2) && (N <= 4))
class Point : public GameObject {
public:
  psyqo::Vector<N> position;
  Point(psyqo::Vector<N> position) : position(position) {}
};
typedef Point<2> Point2D;
}  // namespace HauntedGraveyard
