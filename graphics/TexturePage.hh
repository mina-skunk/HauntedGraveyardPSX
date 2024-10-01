#pragma once

#include "psyqo/primitives.hh"

namespace HauntedGraveyard::graphics {
  struct TexturePage {
    public:
      uint8_t col;
      uint8_t row;
      psyqo::Vertex get_VRAM_position();
      void get_primative(psyqo::Prim::TPage *out);
  };
}
