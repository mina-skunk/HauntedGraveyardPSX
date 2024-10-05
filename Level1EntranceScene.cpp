#include "Character.hh"
#include "Player.hh"
#include "graphics/Render2D.hh"
#include "Level1EntranceScene.hh"
#include "GameApp.hh"
#include "graphics/UI/RenderUI.hh"
#include "psyqo/simplepad.hh"
#include "psyqo/vector.hh"
#include "steve.h"
#include "tileset.h"
#include "ui.h"

void HauntedGraveyard::Level1EntranceScene::start(Scene::StartReason reason) {
  // send steve tex to vram
  psyqo::Vertex player_tex_region_pos = player.bottom_sprite.texture_page.get_VRAM_position();
  psyqo::Rect player_tex_region = {.pos = player_tex_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(steve_tex, player_tex_region);

  // send tileset to vram
  psyqo::Vertex tilemap_region_pos = tile_layer_ground.texture_page.get_VRAM_position();
  psyqo::Rect tilemap_region = {.pos = tilemap_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(graveyard_tileset_tex, tilemap_region);

  // send UI tex to vram
  psyqo::Vertex ui_tex_region_pos = HauntedGraveyard::graphics::UI::RenderUI::texture_page.get_VRAM_position();
  psyqo::Rect ui_tex_region = {.pos = ui_tex_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(ui_tex, ui_tex_region);

  // setup input
  HauntedGraveyard::GameApp::input.setOnEvent([this](const psyqo::SimplePad::Event& event) {
    if (event.type == psyqo::SimplePad::Event::ButtonPressed) {
      if (event.button == psyqo::SimplePad::Cross) {
          player.interact();
      }
    }
  });

  // init level
  HauntedGraveyard::graphics::Render2D::set_camera(&camera);
  player.position = spawn_point;
  hud_key_icon.uv = { .u = 0, .v = 96 };
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
  player.update();

  camera.follow(player.position);
}

void HauntedGraveyard::Level1EntranceScene::draw() {
  // HauntedGraveyard::graphics::Render2D::draw_tilemap(&tile_layer_ground);
  // HauntedGraveyard::graphics::Render2D::draw_tilemap(&tile_layer_ground_detail);
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.bottom_sprite);
  // HauntedGraveyard::graphics::Render2D::draw_tilemap(&tile_layer_surface);
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.top_sprite);
  HauntedGraveyard::graphics::UI::RenderUI::draw_image(&hud_key_icon);
  GameApp::font.chainprint(gpu(), "0/3", { .x = 33, .y = 13 }, { 0x10, 0x10, 0x10 }); // text shadow
  GameApp::font.chainprint(gpu(), "0/3", { .x = 32, .y = 12 }, { 0xff, 0xff, 0xff });

  // HauntedGraveyard::graphics::Render2D::finish_drawing();
}
