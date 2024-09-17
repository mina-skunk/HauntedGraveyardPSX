#pragma once

#include "psyqo/scene.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "TitleScene.hh"

namespace HauntedGraveyard {
  /*
   * Shows developer logo
   */
  class SplashScene final : public psyqo::Scene {
      void start(Scene::StartReason reason) override;
      void frame() override;
      void teardown(Scene::TearDownReason reason) override;

    public:
      psyqo::Font<> *font;
      psyqo::SimplePad *input;
    private:
      psyqo::Prim::TPage logo_tex_page;
      psyqo::Prim::Sprite logo_sprite;
      unsigned char frame_counter = 0;
      TitleScene next_scene;
      void to_next_scene();
  };
}
