#include "psyqo/soft-math.hh"
#include "Player.hh"

void HauntedGraveyard::Player::update() {
  position += velocity;
  sprite.position = position;
}

void HauntedGraveyard::Player::move(psyqo::Vec2 direction) {
  velocity = direction;
}

void HauntedGraveyard::Player::interact() {}
