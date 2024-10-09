#pragma once

#include "graphics/UI/Image.hh"
#include "graphics/UI/Label.hh"
#include "graphics/UI/RenderUI.hh"

namespace HauntedGraveyard {
struct HUD {
  HauntedGraveyard::graphics::UI::Image key_icon = {
      {.x = 0, .y = 4},
      {.w = 32, .h = 32},
      HauntedGraveyard::graphics::UI::RenderUI::texture_page};
  HauntedGraveyard::graphics::UI::Label key_progress = {
      {.x = 32, .y = 12},
      "0/1"};
  HUD() {
    key_icon.uv = {.u = 0, .v = 96};
  }
};
}  // namespace HauntedGraveyard
