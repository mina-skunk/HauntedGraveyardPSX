#pragma once

#include <EASTL/array.h>
#include <EASTL/string_view.h>

#include "Area.hh"
#include "Character.hh"
#include "graphics/Sprite.hh"
#include "psyqo/fixed-point.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
class GraveKeeper final : public HauntedGraveyard::Character {
public:
  eastl::array<eastl::string_view, 2> pre_message;
  eastl::array<eastl::string_view, 2> post_message;
  HauntedGraveyard::graphics::Sprite top_sprite = {{.x = 0.0_fp, .y = 0.0_fp}, {.col = 8, .row = 0}, 3};
  HauntedGraveyard::graphics::Sprite bottom_sprite = {position, {.col = 8, .row = 0}, 4};
  HauntedGraveyard::Area area_trigger = {.position = position, .size = {.x = 16.0_fp, .y = 16.0_fp}};
  GraveKeeper(psyqo::Vec2 position, eastl::array<eastl::string_view, 2> pre_message_, eastl::array<eastl::string_view, 2> post_message_) : Character(position, { 16.0_fp, 16.0_fp }), pre_message(pre_message_), post_message(post_message_) {
    top_sprite.position.x = position.x;
    top_sprite.position.y = position.y - 16;
    top_sprite.uv = {112, 48};
    bottom_sprite.position = position;
    bottom_sprite.uv = {112, 64};
  }
  void update() override;
  void face(HauntedGraveyard::Character target);
};
}  // namespace HauntedGraveyard
