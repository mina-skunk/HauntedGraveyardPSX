#pragma once

#include "psyqo/application.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "psyqo/cdrom-device.hh"
#include "SplashScene.hh"
#include "Level1EntranceScene.hh"
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
      static psyqo::CDRomDevice cdrom;
      SplashScene first_scene;
      Level1EntranceScene debug_scene;

    private:
      bool initialized = false;
  };
}
