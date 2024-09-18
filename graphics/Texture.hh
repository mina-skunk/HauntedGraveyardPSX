#pragma once

#include "psyqo/primitives/common.hh"
#include "psyqo/primitives/control.hh"

namespace HauntedGraveyard {
  namespace graphics {
    class Texture {
      public:
        int16_t width, height;
        psyqo::Rect *get_region(uint8_t x, uint8_t y);
        psyqo::Prim::TPage *get_page();
      private:
        psyqo::Rect region;
    };
  }
}
