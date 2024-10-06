#pragma once

#include "TitleScene.hh"
#include "graphics/UI/Image.hh"
#include "psyqo/font.hh"
#include "psyqo/fragments.hh"
#include "psyqo/primitives/misc.hh"
#include "psyqo/scene.hh"
#include "psyqo/simplepad.hh"
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
  HauntedGraveyard::graphics::UI::Image logo = {
      {.x = 32, .y = 56},
      {.w = splash_tex_WIDTH, .h = splash_tex_HEIGHT},
      {.col = 8, .row = 0}};
  unsigned char frame_counter = 0;
  TitleScene next_scene;
  psyqo::Fragments::SimpleFragment<psyqo::Prim::FastFill> background_fragments[2];
  psyqo::Color background_color = {.r = 0x23, .g = 0x26, .b = 0x34};
};
}  // namespace HauntedGraveyard
