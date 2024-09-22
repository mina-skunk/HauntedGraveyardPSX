#include "graphics/Render2D.hh"
#include "Level1EntranceScene.hh"
#include "GameApp.hh"

void HauntedGraveyard::Level1EntranceScene::start(Scene::StartReason reason) {

  // setup input
  HauntedGraveyard::GameApp::input.setOnEvent([this](const psyqo::SimplePad::Event& event) {
    if (event.type == psyqo::SimplePad::Event::ButtonPressed) {
      if (event.button == psyqo::SimplePad::Up) {
          // TODO
      }
      if (event.button == psyqo::SimplePad::Down) {
          // TODO
      }
      if (event.button == psyqo::SimplePad::Left) {
          // TODO
      }
      if (event.button == psyqo::SimplePad::Right) {
          // TODO
      }
    }
  });

  HauntedGraveyard::graphics::Render2D::set_camera(&camera);
}

void HauntedGraveyard::Level1EntranceScene::frame() {
  //
}

void HauntedGraveyard::Level1EntranceScene::teardown(Scene::TearDownReason reason) {
  // clear input
  HauntedGraveyard::GameApp::input.setOnEvent(nullptr);
}
