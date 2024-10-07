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
};
}  // namespace HauntedGraveyard
