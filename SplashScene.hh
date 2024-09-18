#pragma once

#include "psyqo/scene.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "TitleScene.hh"
#include "graphics/Texture.hh"
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
      HauntedGraveyard::graphics::Texture texture;
      psyqo::Prim::TPage logo_tex_page;
      psyqo::Prim::Sprite logo_sprite;
      unsigned char frame_counter = 0;
      TitleScene next_scene;
  };
}
