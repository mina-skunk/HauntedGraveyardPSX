#pragma once

#include "psyqo/application.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "SplashScene.hh"
#include "TitleScene.hh"

namespace HauntedGraveyard {
  /**
   * Main game app
   */
  class GameApp final : public psyqo::Application {

      void prepare() override;
      void createScene() override;

    public:
      static psyqo::Font<> font;
      static psyqo::SimplePad input;
      SplashScene first_scene;
      TitleScene debug_scene;

    private:
      bool initialized = false;
  };
}
