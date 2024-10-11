#pragma once

#include "Point.hh"
#include "psyqo/vector.hh"

namespace HauntedGraveyard {

template <unsigned N>
  requires((N >= 2) && (N <= 4))
class Shape : public Point<N> {
public:
  psyqo::Vector<N> size;
  Shape(psyqo::Vector<N> position, psyqo::Vector<N> size) : Point<N>(position) {}
};

typedef Shape<2> Rectangle;

}  // namespace HauntedGraveyard
