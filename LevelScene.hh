#pragma once

#include "Area.hh"
#include "HUD.hh"
#include "graphics/UI/Image.hh"
#include "graphics/UI/RenderUI.hh"
#include "psyqo/scene.hh"
#include "psyqo/vector.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
class LevelScene : public psyqo::Scene {
protected:
  uint8_t keys = 0;
  psyqo::Vec2 spawn_point = {0.0_fp, 0.0_fp};
  HauntedGraveyard::Area exit = {{0.0_fp, 0.0_fp}, {16.0_fp, 16.0_fp}};
  psyqo::Color background_color = {.r = 0x40, .g = 0x3d, .b = 0x37};
  HauntedGraveyard::HUD hud;
  virtual void update() {};
  virtual void draw() {};
};
}  // namespace HauntedGraveyard
