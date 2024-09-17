#pragma once

#include "psyqo/vector.hh"

namespace HauntedGraveyard {
  namespace graphics {
    /*
     * Base Object in 2d space 
     */
    class Spatial2D  {
      public:
        psyqo::Vec2 position;
    };
  }
}
