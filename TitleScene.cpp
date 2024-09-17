#include "TitleScene.hh"

void HauntedGraveyard::TitleScene::start(Scene::StartReason reason) {
  // setup input
  input->setOnEvent([this](const psyqo::SimplePad::Event& event) {
    // TODO
  });
}

void HauntedGraveyard::TitleScene::frame() {
  // TODO
  gpu().clear({{ .r=0x23, .g=0x26, .b=0x34 }});
  font->print(gpu(), "TitleScene", {{.x = 128, .y = 64}}, {{.r=255, .g=255, .b=255}});
}

void HauntedGraveyard::TitleScene::teardown(Scene::TearDownReason reason) {
  // clear input
  input->setOnEvent(nullptr);
}
