#pragma once

#include "psyqo/vector.hh"

namespace HauntedGraveyard::graphics {
/*
 * Base Object in 2d space
 */
class Spatial2D {
public:
  psyqo::Vec2 position;
  Spatial2D(psyqo::Vec2 position) : position(position) {}
};
}  // namespace HauntedGraveyard::graphics
