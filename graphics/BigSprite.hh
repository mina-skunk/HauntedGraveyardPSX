#pragma once

#include "Render2D.hh"
#include "Spatial2D.hh"
#include "psyqo/primitives.hh"

namespace HauntedGraveyard::graphics {
/**
 * Big sprite in 2d space
 */
class BigSprite : public HauntedGraveyard::graphics::Spatial2D {
  friend class Render2D;

private:
  psyqo::Prim::Sprite primitive;
};
}  // namespace HauntedGraveyard::graphics
