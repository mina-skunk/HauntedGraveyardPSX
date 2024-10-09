#include "Level1EntranceScene.hh"

#include <EASTL/fixed_string.h>

#include "Character.hh"
#include "GameApp.hh"
#include "Player.hh"
#include "graphics/Render2D.hh"
#include "graphics/UI/RenderUI.hh"
#include "psyqo/simplepad.hh"
#include "psyqo/vector.hh"
#include "psyqo/xprintf.h"
#include "steve.h"
#include "tileset.h"
#include "ui.h"

void HauntedGraveyard::Level1EntranceScene::start(Scene::StartReason reason) {
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

  // setup input
  HauntedGraveyard::GameApp::input.setOnEvent([this](const psyqo::SimplePad::Event &event) {
    if (event.type == psyqo::SimplePad::Event::ButtonPressed) {
      if (show_text_box) {
        show_text_box = false;
      } else {
        if (event.button == psyqo::SimplePad::Cross) {
          Area player_interact_area = player.get_interact_area();
          if (player_interact_area.check_overlap(grave_keeper.area_trigger)) {
            
            text_box.line1 = grave_keeper.pre_message[0];
            text_box.line2 = grave_keeper.pre_message[1];
            show_text_box = true;
          }
        }
      }
    }
  });

  // init level
  HauntedGraveyard::graphics::Render2D::set_camera(&camera);
  player.position = spawn_point;
}

void HauntedGraveyard::Level1EntranceScene::frame() {
  // update
  update();
  // draw
  // background
  HauntedGraveyard::graphics::Render2D::draw_background(background_color);
  draw();
}

void HauntedGraveyard::Level1EntranceScene::teardown(Scene::TearDownReason reason) {
  // clear input
  HauntedGraveyard::GameApp::input.setOnEvent(nullptr);
}

void HauntedGraveyard::Level1EntranceScene::update() {
  if (!show_text_box) {
    psyqo::Vec2 direction;
    if (HauntedGraveyard::GameApp::input.isButtonPressed(psyqo::SimplePad::Pad1, psyqo::SimplePad::Up)) {
      direction.y = -1.0_fp;
      player.orientation = Character::UP;
    }
    if (HauntedGraveyard::GameApp::input.isButtonPressed(psyqo::SimplePad::Pad1, psyqo::SimplePad::Down)) {
      direction.y = 1.0_fp;
      player.orientation = Character::DOWN;
    }
    if (HauntedGraveyard::GameApp::input.isButtonPressed(psyqo::SimplePad::Pad1, psyqo::SimplePad::Left)) {
      direction.x = -1.0_fp;
      player.orientation = Character::LEFT;
    }
    if (HauntedGraveyard::GameApp::input.isButtonPressed(psyqo::SimplePad::Pad1, psyqo::SimplePad::Right)) {
      direction.x = 1.0_fp;
      player.orientation = Character::RIGHT;
    }
    player.move(direction);
  }
  player.apply_bounds(&world_bounds);
  for (auto &fence : fences) {
    player.apply_solid(&fence);
  }
  for (auto &solid_block : solid_blocks) {
    player.apply_solid(&solid_block);
  }
  player.apply_solid(&grave_keeper.area_trigger);
  player.update();

  camera.follow(player.position);
}

void HauntedGraveyard::Level1EntranceScene::draw() {
  // Tilemap
  for (auto &tile_layer : tile_layers) {
    HauntedGraveyard::graphics::Render2D::draw_tilemap(&tile_layer);
  }
  // GraveKeeper
  HauntedGraveyard::graphics::Render2D::draw_sprite(&grave_keeper.bottom_sprite);
  HauntedGraveyard::graphics::Render2D::draw_sprite(&grave_keeper.top_sprite);
  // Player
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.bottom_sprite);
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.top_sprite);

  HauntedGraveyard::graphics::Render2D::finish_drawing();

  // HUD
  HauntedGraveyard::graphics::UI::RenderUI::draw_image(&hud.key_icon);
  eastl::fixed_string<char, 3> key_progress_string;
  fsprintf(key_progress_string, "%d/1", keys);
  HauntedGraveyard::graphics::UI::RenderUI::draw_label(&hud.key_progress);

  if (show_text_box) {
    HauntedGraveyard::graphics::UI::RenderUI::draw_text_box(&text_box);
  }
}
