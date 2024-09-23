#include "graphics/Render2D.hh"
#include "Level1EntranceScene.hh"
#include "GameApp.hh"
#include "psyqo/simplepad.hh"
#include "psyqo/vector.hh"

void HauntedGraveyard::Level1EntranceScene::start(Scene::StartReason reason) {

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
  HauntedGraveyard::graphics::Render2D::draw_sprite(&player);
  // TODO
}

void HauntedGraveyard::Level1EntranceScene::teardown(Scene::TearDownReason reason) {
  // clear input
  HauntedGraveyard::GameApp::input.setOnEvent(nullptr);
}

void HauntedGraveyard::Level1EntranceScene::update() {
  psyqo::Vec2 direction;
  if (HauntedGraveyard::GameApp::input.isButtonPressed(psyqo::SimplePad::Pad1, psyqo::SimplePad::Up)) {
    direction.y = 1.0_fp;
  }
  if (HauntedGraveyard::GameApp::input.isButtonPressed(psyqo::SimplePad::Pad1, psyqo::SimplePad::Down)) {
    direction.y = -1.0_fp;
  }
  if (HauntedGraveyard::GameApp::input.isButtonPressed(psyqo::SimplePad::Pad1, psyqo::SimplePad::Left)) {
    direction.x = -1.0_fp;
  }
  if (HauntedGraveyard::GameApp::input.isButtonPressed(psyqo::SimplePad::Pad1, psyqo::SimplePad::Right)) {
    direction.x = 1.0_fp;
  }
  player.move(direction);
  player.update();
}
