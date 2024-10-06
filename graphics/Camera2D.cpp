#include "Camera2D.hh"

#include "Render2D.hh"

void HauntedGraveyard::graphics::Camera2D::set_active() {
  HauntedGraveyard::graphics::Render2D::set_camera(this);
}

void HauntedGraveyard::graphics::Camera2D::follow(psyqo::Vec2 target) {
  if (target.x < position.x + 96.0_fp) {
    position.x = target.x - 96.0_fp;
  } else if (target.x > position.x + 224.0_fp) {
    position.x = target.x - 224.0_fp;
  }

  if (target.y < position.y + 80.0_fp) {
    position.y = target.y - 80.0_fp;
  } else if (target.y > position.y + 160.0_fp) {
    position.y = target.y - 160.0_fp;
  }
}
