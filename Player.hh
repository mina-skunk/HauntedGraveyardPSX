#pragma once

#include "psyqo/fixed-point.hh"
#include "psyqo/vector.hh"
#include "CharacterSprite.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
  class Player final {
    
    public:
      psyqo::Vec2 position;
      psyqo::Vec2 size = { .x = 16.0_fp, .y = 16.9_fp };
      HauntedGraveyard::CharacterSprite sprite = { { .x = 0.0_fp, .y = 0.0_fp }, { .col = 8, .row = 1 } };
      Player(psyqo::Vec2 position) : position(position) {
        sprite.position = position;
      }
      void move(psyqo::Vec2 direction);
      void interact();
      void update();
    private:
      psyqo::Vec2 velocity;
      psyqo::FixedPoint<> speed;
  };
}
