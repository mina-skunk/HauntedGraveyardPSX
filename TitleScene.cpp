#include "TitleScene.hh"
#include "GameApp.hh"
#include "ui.h"

void HauntedGraveyard::TitleScene::start(Scene::StartReason reason) {
  // send UI tex to vram
  psyqo::Rect ui_tex_region = {.pos = {{.x = 768, .y = 0}}, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(ui_tex, ui_tex_region);
  // setup input
  HauntedGraveyard::GameApp::input.setOnEvent([this](const psyqo::SimplePad::Event& event) {
    // TODO

    if (event.type == psyqo::SimplePad::Event::ButtonPressed) {
      if (event.button == psyqo::SimplePad::Up && selected > 0) {
          selected--;
      }
      if (event.button == psyqo::SimplePad::Down && selected < 1) {
          selected++;
      }
      if (event.button == psyqo::SimplePad::Cross || event.button == psyqo::SimplePad::Start) {
        switch(selected) {
          case 0:
            // code block
            break;
          case 1:
            // code block
            break;
        }
      }
    }

  });
}

void HauntedGraveyard::TitleScene::frame() {
  // background
  gpu().clear({{ .r=0x8a, .g=0x84, .b=0x78 }});
  // title
  HauntedGraveyard::GameApp::font.print(gpu(), "TitleScene", {{.x = 128, .y = 64}}, {{.r=255, .g=255, .b=255}});
  // buttons
  start_button.draw_button(&gpu(), &HauntedGraveyard::GameApp::font);
  instructions_button.draw_button(&gpu(), &HauntedGraveyard::GameApp::font);
  // TODO
}

void HauntedGraveyard::TitleScene::teardown(Scene::TearDownReason reason) {
  // clear input
  HauntedGraveyard::GameApp::input.setOnEvent(nullptr);
}
