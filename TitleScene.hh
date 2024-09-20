#pragma once

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

    class StartButton final : public HauntedGraveyard::graphics::UI::Button {
      psyqo::Vertex position { .x = 32, .y = 128 };
      const char* text = "Start";
      bool selected = true;
    };

    class InstructionsButton final : public HauntedGraveyard::graphics::UI::Button {
      psyqo::Vertex position { .x = 32, .y = 256 };
      const char* text = "Instructions";
      bool selected = false;
    };

      void start(Scene::StartReason reason) override;
      void frame() override;
      void teardown(Scene::TearDownReason reason) override;

    public:

    private:
      // HauntedGraveyard::Level1EntranceScene next_scene;
      uint8_t selected = 0;
      StartButton start_button;
      InstructionsButton instructions_button;
  };
}
