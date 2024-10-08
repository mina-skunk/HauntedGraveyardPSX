#include "GraveKeeper.hh"

void HauntedGraveyard::GraveKeeper::update() {

  uint8_t u;
  uint8_t v;
  switch (orientation) {
    case Character::UP:
      // TODO
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
    case Character::DOWN:
      // TODO
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
