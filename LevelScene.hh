#pragma once

#include "HUD.hh"
#include "Player.hh"
#include "core/Area.hh"
#include "graphics/UI/Image.hh"
#include "graphics/UI/RenderUI.hh"
#include "graphics/UI/TextBox.hh"
#include "psyqo/scene.hh"
#include "psyqo/vector.hh"

using namespace psyqo::fixed_point_literals;

namespace HauntedGraveyard {
class LevelScene : public psyqo::Scene {
  void frame() override;

public:
  LevelScene(psyqo::Vec2 spawn_point, HauntedGraveyard::core::Area2D exit) : spawn_point(spawn_point), exit(exit) {
    player.position = spawn_point;
  }

protected:
  uint8_t keys = 0;
  psyqo::Vec2 spawn_point;
  HauntedGraveyard::Player player = {spawn_point};
  HauntedGraveyard::core::Area2D exit;
  psyqo::Color background_color = {.r = 0x40, .g = 0x3d, .b = 0x37};
  HauntedGraveyard::HUD hud;
  HauntedGraveyard::graphics::UI::TextBox text_box = {
      {.x = 0, .y = 176},
      "",
      ""};
  bool show_text_box = false;
  virtual void update() {};
  virtual void draw() {};
};
}  // namespace HauntedGraveyard
