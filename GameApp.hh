#pragma once

#include "psyqo/application.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "SplashScene.hh"

namespace HauntedGraveyard {
  /**
   * Main game app
   */
  class GameApp final : public psyqo::Application {

      void prepare() override;
      void createScene() override;

    public:
      psyqo::Font<> font;
      psyqo::SimplePad input;
      SplashScene first_scene;

    private:
      bool initialized = false;
  };
}
