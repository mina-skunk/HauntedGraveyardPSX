#pragma once

#include "psyqo/scene.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "TitleScene.hh"
#include "splash.h"

namespace HauntedGraveyard {
  /*
   * Shows developer logo
   */
  class SplashScene final : public psyqo::Scene {
      void start(Scene::StartReason reason) override;
      void frame() override;
      void teardown(Scene::TearDownReason reason) override;

    public:

    private:
      psyqo::Prim::TPage logo_tex_page;
      psyqo::Prim::Sprite logo_sprite;
      unsigned char frame_counter = 0;
      TitleScene next_scene;
      psyqo::Color background_color = { .r = 0x23, .g = 0x26, .b = 0x34 };
  };
}
