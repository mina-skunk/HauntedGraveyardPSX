#include "Camera2D.hh"
#include "Render2D.hh"

void HauntedGraveyard::graphics::Camera2D::set_active() {
  HauntedGraveyard::graphics::Render2D::set_camera(this);
}
