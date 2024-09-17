#pragma once

#include "psyqo/vector.hh"
#include "graphics/Sprite.hh"

namespace HauntedGraveyard {
  class Player final : public HauntedGraveyard::graphics::Sprite  {
    public:
      void move(psyqo::Vec2 direction);
      void interact();
  };
}
