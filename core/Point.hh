#pragma once

#include "GameObject.hh"
#include "psyqo/vector.hh"

namespace HauntedGraveyard::core {
template <unsigned N>
  requires((N == 2) || (N == 3))
class Point : public GameObject {
public:
  psyqo::Vector<N> position;
  Point(psyqo::Vector<N> position) : position(position) {}
};
typedef Point<2> Point2D;
}  // namespace HauntedGraveyard::core
