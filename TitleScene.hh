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
      void start(Scene::StartReason reason) override;
      void frame() override;
      void teardown(Scene::TearDownReason reason) override;

    public:

    private:
      // HauntedGraveyard::Level1EntranceScene next_scene;
      uint8_t selected = 0;
      HauntedGraveyard::graphics::UI::Button start_button;
      HauntedGraveyard::graphics::UI::Button instructions_button;
  };
}
