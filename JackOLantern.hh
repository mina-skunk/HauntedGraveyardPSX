#pragma once

#include "core/Area.hh"
#include "graphics/Sprite.hh"
#include "psyqo/fixed-point.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
class JackOLantern : public HauntedGraveyard::core::Area2D {
public:
  bool has_key = false;
  HauntedGraveyard::graphics::Sprite sprite = {{0.0_fp, 0.0_fp}, {.col = 8, .row = 0}, 4};
  JackOLantern(psyqo::Vec2 position) : HauntedGraveyard::core::Area2D(position, {16.0_fp, 16.0_fp}) {
    sprite.position = position;
    sprite.uv.u = 0;
    sprite.uv.v = 128;
  }
  JackOLantern(psyqo::Vec2 position, bool has_key) : HauntedGraveyard::core::Area2D(position, {16.0_fp, 16.0_fp}), has_key(has_key) {
    sprite.position = position;
    sprite.uv.u = 0;
    sprite.uv.v = 128;
  }
  void update() override;

private:
  uint8_t frame_count = 0;
  uint8_t ani_offset = 0;
};
}  // namespace HauntedGraveyard
