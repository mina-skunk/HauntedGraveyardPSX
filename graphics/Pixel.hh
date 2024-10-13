#pragma once

#include "Render2D.hh"
#include "Spatial2D.hh"
#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "psyqo/primitives/common.hh"

namespace HauntedGraveyard::graphics {
typedef psyqo::Fragments::SimpleFragment<psyqo::Prim::Pixel> PixelFragment;
class Pixel : public Spatial2D {
  friend class Render2D;

public:
  Pixel(psyqo::Vec2 position) : Spatial2D(position) {};
  Pixel(psyqo::Vec2 position, psyqo::Color color) : Spatial2D(position) {
    for (auto &fragment : fragments) {
      fragment.primitive.setColor(color);
    }
  }

private:
  PixelFragment fragments[2];
  PixelFragment *get_fragment(uint8_t buffer_index);
};
}  // namespace HauntedGraveyard::graphics
