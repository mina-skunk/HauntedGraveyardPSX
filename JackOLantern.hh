#pragma once

#include "Area.hh"
#include "psyqo/fixed-point.hh"
#include "graphics/Sprite.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
class JackOLantern {
public:
  bool has_key = false;
  HauntedGraveyard::Area area_trigger = {.position = {.x = 0.0_fp, .y = 0.0_fp}, .size = {.x = 16.0_fp, .y = 16.0_fp}};
  HauntedGraveyard::graphics::Sprite sprite = {{.x = 0.0_fp, .y = 0.0_fp}, {.col = 8, .row = 1}, 3}; // TODO
  JackOLantern(psyqo::Vec2 position) {
    area_trigger.position = position;
    sprite.position = position;
  }
  JackOLantern(psyqo::Vec2 position, bool has_key) : has_key(has_key) {
    area_trigger.position = position;
    sprite.position = position;
  }
  // void update();
};
}  // namespace HauntedGraveyard
