#include "Character.hh"
#include "Player.hh"
#include "graphics/Render2D.hh"
#include "Level1EntranceScene.hh"
#include "GameApp.hh"
#include "psyqo/simplepad.hh"
#include "psyqo/vector.hh"
#include "steve.h"
#include "tileset.h"

void HauntedGraveyard::Level1EntranceScene::start(Scene::StartReason reason) {
  // send steve tex to vram
  psyqo::Vertex player_tex_region_pos = player.bottom_sprite.texture_page.get_VRAM_position();
  psyqo::Rect player_tex_region = {.pos = player_tex_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(steve_tex, player_tex_region);

  // send tileset to vram
  psyqo::Vertex tilemap_region_pos = tile_layer_0.texture_page.get_VRAM_position();
  psyqo::Rect tilemap_region = {.pos = tilemap_region_pos, .size = {{.w = 256, .h = 256}}};
  gpu().uploadToVRAM(graveyard_tileset_tex, tilemap_region);

  // setup input
  HauntedGraveyard::GameApp::input.setOnEvent([this](const psyqo::SimplePad::Event& event) {
    if (event.type == psyqo::SimplePad::Event::ButtonPressed) {
      if (event.button == psyqo::SimplePad::Cross) {
          player.interact();
      }
    }
  });

  HauntedGraveyard::graphics::Render2D::set_camera(&camera);
}

void HauntedGraveyard::Level1EntranceScene::frame() {
  // update
  update();
  // draw
  // background
  gpu().clear(background_color);
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
  HauntedGraveyard::graphics::Render2D::draw_tilemap(&tile_layer_0);
  HauntedGraveyard::graphics::Render2D::draw_tilemap(&tile_layer_1);
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.bottom_sprite);
  HauntedGraveyard::graphics::Render2D::draw_tilemap(&tile_layer_2);
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player.top_sprite);
  // TODO
}
