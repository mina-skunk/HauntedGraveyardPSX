#include "LevelScene.hh"

void HauntedGraveyard::LevelScene::frame() {
  // update
  update();
  // draw
  // background
  HauntedGraveyard::graphics::Render2D::draw_background(background_color);
  draw();
}
