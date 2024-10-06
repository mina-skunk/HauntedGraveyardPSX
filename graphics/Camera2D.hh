#pragma once

#include "Render2D.hh"
#include "Spatial2D.hh"
#include "psyqo/fixed-point.hh"
#include "psyqo/primitives/common.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard::graphics {
/**
 * Represents Camera position
 */
class Camera2D : public HauntedGraveyard::graphics::Spatial2D {
  friend class Render2D;

public:
  psyqo::Vertex size = {.x = 320, .y = 240};
  Camera2D(psyqo::Vec2 position) : Spatial2D(position) {}
  /**
   * Set this camera as active for the Render2D
   */
  void set_active();
  void follow(psyqo::Vec2 target);
};
}  // namespace HauntedGraveyard::graphics
