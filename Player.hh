#pragma once

#include "Area.hh"
#include "Character.hh"
#include "graphics/Sprite.hh"
#include "psyqo/fixed-point.hh"
#include "psyqo/vector.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
/**
 * Controlled Player Character
 */
class Player final : public HauntedGraveyard::Character {
public:
  psyqo::Vec2 size = {.x = 16.0_fp, .y = 16.0_fp};
  HauntedGraveyard::graphics::Sprite top_sprite = {{.x = 0.0_fp, .y = 0.0_fp}, {.col = 8, .row = 1}, 3};
  HauntedGraveyard::graphics::Sprite bottom_sprite = {position, {.col = 8, .row = 1}, 4};
  void update() override;
  Player(psyqo::Vec2 position) : Character(position) {
    top_sprite.position.x = position.x;
    top_sprite.position.y = position.y - 16;
    bottom_sprite.position = position;
  }
  /**
   * Apply input direction
   */
  void move(psyqo::Vec2 direction);
  Area get_interact_area();
  /**
   * Keep player in Area
   */
  void apply_bounds(Area *bounds);
  /**
   * Keep player out of Area
   */
  void apply_solid(Area *solid);

private:
  psyqo::Vec2 velocity = {.x = 0.0_fp, .y = 0.0_fp};
  const psyqo::FixedPoint<> speed = 0.8_fp;
  uint8_t frame_count = 0;
  int16_t ani_offset = 0;
};
}  // namespace HauntedGraveyard
