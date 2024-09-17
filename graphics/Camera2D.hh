#pragma once

#include "psyqo/primitives/common.hh"
#include "Spatial2D.hh"

namespace HauntedGraveyard {
  namespace graphics {
    /**
     * Represents Camera position
     */
    class Camera2D : public HauntedGraveyard::graphics::Spatial2D  {
      public:
        psyqo::Vertex size = { .x = 320, .y = 240 };
        /**
         * Set this camera as active for the Render2D
         */
        void set_active();
    };
  }
}
