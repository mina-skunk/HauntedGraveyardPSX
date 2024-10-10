#include "GraveKeeper.hh"

void HauntedGraveyard::GraveKeeper::update() {

  uint8_t u;
  uint8_t v;
  switch (orientation) {
    case Character::UP:
      u = 80;
      v = 48;
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
    case Character::DOWN:
      u = 112;
      v = 48;
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
    case Character::LEFT:
      u = 96;
      v = 48;
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
    case Character::RIGHT:
      u = 64;
      v = 48;
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
  }
}

void HauntedGraveyard::GraveKeeper::face(HauntedGraveyard::Character target) {
  switch (target.orientation) {
    case HauntedGraveyard::Character::UP:
      orientation = HauntedGraveyard::Character::DOWN;
      break;
    case HauntedGraveyard::Character::DOWN:
      orientation = HauntedGraveyard::Character::UP;
      break;
    case HauntedGraveyard::Character::LEFT:
      orientation = HauntedGraveyard::Character::RIGHT;
      break;
    case HauntedGraveyard::Character::RIGHT:
      orientation = HauntedGraveyard::Character::LEFT;
      break;
  }
}
