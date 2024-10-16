#include "Level1EntranceScene.hh"

#include <EASTL/fixed_string.h>

#include "Character.hh"
#include "GameApp.hh"
#include "Player.hh"
#include "core/Area.hh"
#include "graphics/Render2D.hh"
#include "graphics/UI/RenderUI.hh"
#include "psyqo/simplepad.hh"
#include "psyqo/vector.hh"
#include "psyqo/xprintf.h"
#include "steve.h"
#include "system/SimpleCDAudio.hh"
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
          HauntedGraveyard::core::Area2D player_interact_area = player.get_interact_area();
          if (player_interact_area.check_overlap(grave_keeper)) {
            if (keys < 1) {
              text_box.line1 = grave_keeper.pre_message[0];
              text_box.line2 = grave_keeper.pre_message[1];
            } else {
              text_box.line1 = grave_keeper.post_message[0];
              text_box.line2 = grave_keeper.post_message[1];
            }
            show_text_box = true;
            grave_keeper.face(player);
          }
          if (jack_o_lantern_with_key.has_key && player_interact_area.check_overlap(jack_o_lantern_with_key)) {
            jack_o_lantern_with_key.has_key = false;
            keys++;
            text_box.line1 = "You found a key!!";
            text_box.line2 = "";
            show_text_box = true;
          }
          if (keys == 1 && player_interact_area.check_overlap(gate)) {
            gate.open = true;
            gate.sprite.uv.u = 192;
            gate.sprite.uv.v = 48;
          }
        }
      }
    }
  });

  HauntedGraveyard::system::SimpleCDAudio::play(&HauntedGraveyard::GameApp::cdrom, TITLE_TRACK, true);

  // init level
  HauntedGraveyard::graphics::Render2D::set_camera(&camera);
  player.position = spawn_point;
}

void HauntedGraveyard::Level1EntranceScene::teardown(Scene::TearDownReason reason) {
  // clear input
  HauntedGraveyard::GameApp::input.setOnEvent(nullptr);

  HauntedGraveyard::system::SimpleCDAudio::stop(&HauntedGraveyard::GameApp::cdrom);
}

void HauntedGraveyard::Level1EntranceScene::update() {
  if (!show_text_box) {
    // player move
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
  // bounds and fences
  player.apply_bounds(&world_bounds);
  for (auto &fence : fences) {
    player.apply_solid(&fence);
  }
  // pumpkins
  for (auto &jack_o_lantern : jack_o_lanterns) {
    player.apply_solid(&jack_o_lantern);
    jack_o_lantern.update();
  }
  player.apply_solid(&jack_o_lantern_with_key);
  jack_o_lantern_with_key.update();
  // gate
  if (!gate.open) {
    player.apply_solid(&gate);
  }
  // npcs
  player.apply_solid(&grave_keeper);
  grave_keeper.update();
  // player
  player.update();
  // camera
  camera.follow(player.position);

  // check for end
  if (keys == 1 && gate.open && exit.check_overlap({player.position, {16.0_fp, 16.0_fp}})) {
    pushScene(&next_scene);
  }

  // update UI
  eastl::fixed_string<char, 3> key_progress_string;
  fsprintf(key_progress_string, "%d/1", keys);
  hud.key_progress.text = key_progress_string;

}

void HauntedGraveyard::Level1EntranceScene::draw() {
  // Tilemap
  for (auto &tile_layer : tile_layers) {
    HauntedGraveyard::graphics::Render2D::draw_tilemap(&tile_layer);
  }
  // pumpkins
  for (auto &jack_o_lantern : jack_o_lanterns) {
    HauntedGraveyard::graphics::Render2D::draw_sprite(&jack_o_lantern.sprite);
  }
  HauntedGraveyard::graphics::Render2D::draw_sprite(&jack_o_lantern_with_key.sprite);
  // GraveKeeper
  HauntedGraveyard::graphics::Render2D::draw_sprite(&grave_keeper.bottom_sprite);
  HauntedGraveyard::graphics::Render2D::draw_sprite(&grave_keeper.top_sprite);
  // Player
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.bottom_sprite);
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.top_sprite);
  // gate
  HauntedGraveyard::graphics::Render2D::draw_bigsprite(&gate.sprite);

  HauntedGraveyard::graphics::Render2D::finish_drawing();

  // HUD
  HauntedGraveyard::graphics::UI::RenderUI::draw_image(&hud.key_icon);
  HauntedGraveyard::graphics::UI::RenderUI::draw_label(&hud.key_progress);

  if (show_text_box) {
    HauntedGraveyard::graphics::UI::RenderUI::draw_text_box(&text_box);
  }
}
