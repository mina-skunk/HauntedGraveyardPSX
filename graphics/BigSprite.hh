#pragma once

#include "psyqo/primitives.hh"
#include "Spatial2D.hh"

namespace HauntedGraveyard {
  namespace graphics {
    /**
     * Big sprite in 2d space 
     */
    class BigSprite : public HauntedGraveyard::graphics::Spatial2D  {
      private:
        psyqo::Prim::Sprite primitive;
    };
  }
}
