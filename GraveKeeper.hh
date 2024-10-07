#pragma once

#include "Area.hh"
#include "psyqo/fixed-point.hh"
#include "Character.hh"
#include "graphics/Sprite.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
class GraveKeeper final : public HauntedGraveyard::Character {
public:
  const char* pre_message;
  const char* post_message;
  HauntedGraveyard::graphics::Sprite top_sprite = {{.x = 0.0_fp, .y = 0.0_fp}, {.col = 8, .row = 1}, 3};
  HauntedGraveyard::graphics::Sprite bottom_sprite = {{.x = 0.0_fp, .y = 0.0_fp}, {.col = 8, .row = 1}, 4};
  HauntedGraveyard::Area area_trigger = { .position = position, .size = { .x = 16.0_fp, .y = 16.0_fp } };
  GraveKeeper(psyqo::Vec2 position, const char* pre_message, const char* post_message) : Character(position), pre_message(pre_message), post_message(post_message) {
    top_sprite.position.x = position.x;
    top_sprite.position.y = position.y - 16;
    bottom_sprite.position = position;
  }
  // void update() override;
};
}  // namespace HauntedGraveyard
