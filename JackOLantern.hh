#pragma once

#include "Area.hh"
#include "graphics/Sprite.hh"
#include "psyqo/fixed-point.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
class JackOLantern {
public:
  bool has_key = false;
  // psyqo::Vec2 position;
  HauntedGraveyard::Area area_trigger = {.position = { 0.0_fp, 0.0_fp }, .size = {.x = 16.0_fp, .y = 16.0_fp}};
  HauntedGraveyard::graphics::Sprite sprite = {{ 0.0_fp, 0.0_fp }, {.col = 8, .row = 0}, 4};
  JackOLantern(psyqo::Vec2 position) {
    area_trigger.position = position;
    sprite.position = position;
    sprite.uv.u = 0;
    sprite.uv.v = 128;
  }
  JackOLantern(psyqo::Vec2 position, bool has_key) : has_key(has_key) {
    area_trigger.position = position;
    sprite.position = position;
    sprite.uv.u = 0;
    sprite.uv.v = 128;
  }
  void update();

private:
  uint8_t frame_count = 0;
  uint8_t ani_offset = 0;
};
}  // namespace HauntedGraveyard
