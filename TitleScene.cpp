#include "graphics/UI/RenderUI.hh"
#include "TitleScene.hh"
#include "GameApp.hh"
#include "psyqo/primitives/common.hh"
#include "title.h"
#include "ui.h"

void HauntedGraveyard::TitleScene::start(Scene::StartReason reason) {
  // send title tex to vram
  psyqo::Rect title_tex_region = {.pos = {{.x = 512, .y = 0}}, .size = {{.w = 256, .h = 128}}};
  gpu().uploadToVRAM(title_tex, title_tex_region);
  // send UI tex to vram
  psyqo::Vertex ui_tex_region_pos = HauntedGraveyard::graphics::UI::RenderUI::texture_page.get_VRAM_position();
  psyqo::Rect ui_tex_region = {.pos = ui_tex_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(ui_tex, ui_tex_region);
  // setup input
  HauntedGraveyard::GameApp::input.setOnEvent([this](const psyqo::SimplePad::Event& event) {
    if (event.type == psyqo::SimplePad::Event::ButtonPressed) {
      if (show_instructions) {
        show_instructions = false;
        return;
      }
      if (event.button == psyqo::SimplePad::Up && selected > 0) {
          selected--;
      }
      if (event.button == psyqo::SimplePad::Down && selected < 1) {
          selected++;
      }
      if (event.button == psyqo::SimplePad::Cross || event.button == psyqo::SimplePad::Start) {
        switch(selected) {
          case 0:
            // pushScene(next_scene);
            break;
          case 1:
            show_instructions = true;
            break;
        }
      }
    }

  });
}

void HauntedGraveyard::TitleScene::frame() {
  // update
  switch(selected) {
    case 0:
      start_button.selected = true;
      instructions_button.selected = false;
      break;
    case 1:
      start_button.selected = false;
      instructions_button.selected = true;
      break;
  }
  // background
  gpu().clear({{ .r=0x8a, .g=0x84, .b=0x78 }});
  // title
  HauntedGraveyard::graphics::UI::RenderUI::draw_image(&title);
  // buttons
  HauntedGraveyard::graphics::UI::RenderUI::draw_button(&start_button);
  HauntedGraveyard::graphics::UI::RenderUI::draw_button(&instructions_button);
  // instructions
  if (show_instructions) {
    // TODO
  }
}

void HauntedGraveyard::TitleScene::teardown(Scene::TearDownReason reason) {
  // clear input
  HauntedGraveyard::GameApp::input.setOnEvent(nullptr);
}
