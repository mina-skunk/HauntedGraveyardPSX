#pragma once

#include "psyqo/primitives.hh"
#include "Spatial2D.hh"
#include "Render2D.hh"

namespace HauntedGraveyard::graphics {
  /**
    * Big sprite in 2d space 
    */
  class BigSprite : public HauntedGraveyard::graphics::Spatial2D  {
    friend class Render2D;
    private:
      psyqo::Prim::Sprite primitive;
  };
}
