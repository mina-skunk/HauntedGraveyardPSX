#pragma once

#include "Level1EntranceScene.hh"
#include "PointDemoScene.hh"
#include "SplashScene.hh"
#include "TitleScene.hh"
#include "psyqo/application.hh"
#include "psyqo/cdrom-device.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"

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
  PointDemoScene debug_scene;

private:
  bool initialized = false;
};
}  // namespace HauntedGraveyard
