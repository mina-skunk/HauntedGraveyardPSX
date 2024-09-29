#pragma once

#include "psyqo/fixed-point.hh"
#include "psyqo/vector.hh"
#include "graphics/Sprite.hh"
#include "Character.hh"
#include <cstdint>

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
  class Player final : public HauntedGraveyard::Character {
    
    public:
      psyqo::Vec2 size = { .x = 16.0_fp, .y = 16.0_fp };
      HauntedGraveyard::graphics::Sprite top_sprite = { { .x = 0.0_fp, .y =  0.0_fp }, { .col = 8, .row = 1 } };
      HauntedGraveyard::graphics::Sprite bottom_sprite = { { .x = 0.0_fp, .y =  0.0_fp }, { .col = 8, .row = 1 } };
      void update() override;
      Player(psyqo::Vec2 position) : Character(position) {
        top_sprite.position.x = position.x;
        top_sprite.position.y = position.y - 16;
        bottom_sprite.position = position;
      }
      void move(psyqo::Vec2 direction);
      void interact();
    private:
      psyqo::Vec2 velocity = { .x = 0.0_fp, .y = 0.0_fp };
      const psyqo::FixedPoint<> speed = 0.8_fp;
      uint8_t frame_count = 0;
      int16_t ani_offset = 0;
  };
}
