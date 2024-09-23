#pragma once

#include "psyqo/gpu.hh"
#include "psyqo/vector.hh"

namespace HauntedGraveyard::graphics {
  class Camera2D;
  class Sprite;
  /**
    * Handles generating primatives / framgments for objects in 2d space 
    */
  class Render2D {
    public:
      static void init(psyqo::GPU *gpu_);
      /**
        * Sets current active Camera2D
        */
      static void set_camera(HauntedGraveyard::graphics::Camera2D *camera);
      static void draw_sprite(HauntedGraveyard::graphics::Sprite *sprite);
    private:
      static psyqo::GPU *gpu;
      static HauntedGraveyard::graphics::Camera2D *active_camera;
      static psyqo::Vec2 get_relative_position(psyqo::Vec2 world_position);
  };
}
