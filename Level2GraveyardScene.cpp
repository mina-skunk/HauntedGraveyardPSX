#include "Level2GraveyardScene.hh"

#include <EASTL/fixed_string.h>

#include "GameApp.hh"
#include "psyqo/simplepad.hh"
#include "psyqo/xprintf.h"
#include "steve.h"
#include "tileset.h"
#include "ui.h"

void HauntedGraveyard::Level2GraveyardScene::start(Scene::StartReason reason) {
  // send steve tex to vram
  psyqo::Vertex player_tex_region_pos = player.bottom_sprite.texture_page.get_VRAM_position();
  psyqo::Rect player_tex_region = {.pos = player_tex_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(steve_tex, player_tex_region);

  // send tileset to vram
  psyqo::Vertex tilemap_region_pos = tile_layers[0].texture_page.get_VRAM_position();
  psyqo::Rect tilemap_region = {.pos = tilemap_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(graveyard_tileset_tex, tilemap_region);

  // send UI tex to vram
  psyqo::Vertex ui_tex_region_pos = HauntedGraveyard::graphics::UI::RenderUI::texture_page.get_VRAM_position();
  psyqo::Rect ui_tex_region = {.pos = ui_tex_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(ui_tex, ui_tex_region);

  // input
  HauntedGraveyard::GameApp::input.setOnEvent([this](const psyqo::SimplePad::Event &event) {
    if (event.type == psyqo::SimplePad::Event::ButtonPressed) {
      if (show_text_box) {
        show_text_box = false;
      } else {
        if (event.button == psyqo::SimplePad::Cross) {
          // TODO
        }
      }
    }
  });

  // init level
  HauntedGraveyard::graphics::Render2D::set_camera(&camera);
  player.position = spawn_point;
}

void HauntedGraveyard::Level2GraveyardScene::teardown(Scene::TearDownReason reason) {
  // clear input
  HauntedGraveyard::GameApp::input.setOnEvent(nullptr);
}

void HauntedGraveyard::Level2GraveyardScene::update() {
  // player
  player.update();
  // camera
  camera.follow(player.position);
  // update UI
  eastl::fixed_string<char, 3> key_progress_string;
  fsprintf(key_progress_string, "%d/3", keys);
  hud.key_progress.text = key_progress_string;
}

void HauntedGraveyard::Level2GraveyardScene::draw() {
  // Tilemap
  for (auto &tile_layer : tile_layers) {
    HauntedGraveyard::graphics::Render2D::draw_tilemap(&tile_layer);
  }

  // Player
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.bottom_sprite);
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.top_sprite);

  HauntedGraveyard::graphics::Render2D::finish_drawing();

  // HUD
  HauntedGraveyard::graphics::UI::RenderUI::draw_image(&hud.key_icon);
  HauntedGraveyard::graphics::UI::RenderUI::draw_label(&hud.key_progress);

}
