#pragma once

#include "graphics/UI/Image.hh"
#include "psyqo/primitives/common.hh"
#include "psyqo/scene.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "graphics/UI/Button.hh"
// #include "Level1EntranceScene.hh"

namespace HauntedGraveyard {
  /**
   * Shows main menu / title
   */
  class TitleScene final : public psyqo::Scene {

      void start(Scene::StartReason reason) override;
      void frame() override;
      void teardown(Scene::TearDownReason reason) override;

    public:

    private:
      // HauntedGraveyard::Level1EntranceScene next_scene;
      HauntedGraveyard::graphics::UI::Image title = { { .x = 32, .y = 16 }, { .w = 256, .h = 128 }, { .col = 8, .row = 0 }};
      uint8_t selected = 0;
      HauntedGraveyard::graphics::UI::Button start_button = { { .x = 96, .y = 128 }, "Start", true};
      HauntedGraveyard::graphics::UI::Button instructions_button = { { .x = 96, .y = 160 }, "Instructions", false};
      bool show_instructions = false;
  };
}
