#pragma once

#include "psyqo/primitives.hh"
#include "Spatial2D.hh"

namespace HauntedGraveyard {
  namespace graphics {
    /**
     * Small sprite in 2d space 
     */
    class Sprite : public HauntedGraveyard::graphics::Spatial2D  {
      private:
        psyqo::Prim::Sprite16x16 primitive;
    };
  }
}
