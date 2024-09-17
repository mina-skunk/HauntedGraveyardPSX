#pragma once

#include "Camera2D.hh"

namespace HauntedGraveyard {
  namespace graphics {
    /**
     * Handles generating primatives / framgments for objects in 2d space 
     */
    class Render2D {
      public:
        /**
         * Sets current active Camera2D
         */
        static void set_camera(HauntedGraveyard::graphics::Camera2D *camera);
      private:
        static HauntedGraveyard::graphics::Camera2D *active_camera;
    };
  }
}
