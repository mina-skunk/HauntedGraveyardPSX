#pragma once

#include "Level1EntranceScene.hh"
#include "graphics/UI/Button.hh"
#include "graphics/UI/Image.hh"
#include "graphics/UI/RenderUI.hh"
#include "graphics/UI/TextBox.hh"
#include "psyqo/primitives/common.hh"
#include "psyqo/scene.hh"

#define TITLE_TRACK 2

namespace HauntedGraveyard {
/**
 * Shows main menu / title
 */
class TitleScene final : public psyqo::Scene {
  void start(Scene::StartReason reason) override;
  void frame() override;
  void teardown(Scene::TearDownReason reason) override;

public:
  // TODO
private:
  HauntedGraveyard::Level1EntranceScene next_scene;
  HauntedGraveyard::graphics::UI::Image title = {{.x = 32, .y = 16}, {.w = 256, .h = 128}, {.col = 8, .row = 0}};
  uint8_t selected = 0;
  HauntedGraveyard::graphics::UI::Button start_button = {{.x = 96, .y = 128}, "Start", true};
  HauntedGraveyard::graphics::UI::Button instructions_button = {{.x = 96, .y = 160}, "Instructions", false};
  bool show_instructions = false;
  HauntedGraveyard::graphics::UI::TextBox instructions = {{.x = 0, .y = 176}, "Use D-Pad to move,    to interact.", "Find keys and avoid ghosts!"};
  HauntedGraveyard::graphics::UI::Image cross_button = {{.x = 168, .y = 192}, {.w = 16, .h = 16}, HauntedGraveyard::graphics::UI::RenderUI::texture_page};
  uint8_t frame_counter = 0;
  psyqo::Fragments::SimpleFragment<psyqo::Prim::FastFill> background_fragments[2];
  psyqo::Color background_color = {.r = 0x40, .g = 0x3d, .b = 0x37};
};
}  // namespace HauntedGraveyard
