#pragma once

#include "Point.hh"
#include "psyqo/vector.hh"

namespace HauntedGraveyard::core {

template <unsigned N>
  requires((N == 2) || (N == 3))
class Shape : public Point<N> {
public:
  psyqo::Vector<N> size;
  Shape(psyqo::Vector<N> position, psyqo::Vector<N> size) : Point<N>(position), size(size) {}
};

typedef Shape<2> Rectangle;

}  // namespace HauntedGraveyard::core
