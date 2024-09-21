#pragma once

#include "psyqo/primitives/common.hh"

namespace HauntedGraveyard::graphics {
  class TexturePage {
    public:
      uint8_t col;
      uint8_t row;
      psyqo::Vertex get_VRAM_position();
  };
}
