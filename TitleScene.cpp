#include "TitleScene.hh"

#include "GameApp.hh"
#include "graphics/UI/RenderUI.hh"
#include "psyqo/primitives/common.hh"
#include "system/SimpleCDAudio.hh"
#include "title.h"
#include "ui.h"

void HauntedGraveyard::TitleScene::start(Scene::StartReason reason) {
  // send title tex to vram
  psyqo::Vertex title_tex_region_pos = title.texture_page.get_VRAM_position();
  psyqo::Rect title_tex_region = {.pos = title_tex_region_pos, .size = {{.w = 256, .h = 128}}};
  gpu().uploadToVRAM(title_tex, title_tex_region);
  // send UI tex to vram
  psyqo::Vertex ui_tex_region_pos = HauntedGraveyard::graphics::UI::RenderUI::texture_page.get_VRAM_position();
  psyqo::Rect ui_tex_region = {.pos = ui_tex_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(ui_tex, ui_tex_region);

  cross_button.uv = {.u = 48, .v = 48};

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
        switch (selected) {
          case 0:
            pushScene(&next_scene);
            break;
          case 1:
            show_instructions = true;
            break;
        }
      }
    }
  });

  HauntedGraveyard::system::SimpleCDAudio::play(&HauntedGraveyard::GameApp::cdrom, TITLE_TRACK, true);
}

void HauntedGraveyard::TitleScene::frame() {
  // update
  switch (selected) {
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
  // There is only UI on the scene so we chain the background directly in the scene
  gpu().getNextClear(background_fragments[gpu().getParity()].primitive, background_color);
  gpu().chain(background_fragments[gpu().getParity()]);
  // title
  HauntedGraveyard::graphics::UI::RenderUI::draw_image(&title);
  // buttons
  HauntedGraveyard::graphics::UI::RenderUI::draw_button(&start_button);
  HauntedGraveyard::graphics::UI::RenderUI::draw_button(&instructions_button);
  // instructions
  if (show_instructions) {  // animate cross button
    if (frame_counter < 10) {
      cross_button.uv = {.u = 48, .v = 48};
    } else if (frame_counter < 20) {
      cross_button.uv = {.u = 64, .v = 48};
    } else if (frame_counter < 30) {
      cross_button.uv = {.u = 80, .v = 48};
    } else if (frame_counter < 40) {
      cross_button.uv = {.u = 64, .v = 48};
    } else {
      frame_counter = 0;
    }
    frame_counter++;

    HauntedGraveyard::graphics::UI::RenderUI::draw_text_box(&instructions);
    HauntedGraveyard::graphics::UI::RenderUI::draw_image(&cross_button);
  }
}

void HauntedGraveyard::TitleScene::teardown(Scene::TearDownReason reason) {
  // clear input
  HauntedGraveyard::GameApp::input.setOnEvent(nullptr);

  HauntedGraveyard::system::SimpleCDAudio::stop(&HauntedGraveyard::GameApp::cdrom);
}
