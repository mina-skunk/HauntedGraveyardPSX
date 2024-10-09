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
      // TODO
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
    case Character::RIGHT:
      // TODO
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
  }
}
