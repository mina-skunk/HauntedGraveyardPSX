#include "Render2D.hh"
#include "Camera2D.hh"

HauntedGraveyard::graphics::Camera2D* HauntedGraveyard::graphics::Render2D::active_camera;

void HauntedGraveyard::graphics::Render2D::set_camera(HauntedGraveyard::graphics::Camera2D *camera) {
  active_camera = camera;
}
