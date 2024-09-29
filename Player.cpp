#include "Character.hh"
#include "psyqo/kernel.hh"
#include "psyqo/soft-math.hh"
#include "Player.hh"

void HauntedGraveyard::Player::update() {
  // physics
  position += velocity * speed;
  top_sprite.position.x = position.x;
  top_sprite.position.y = position.y - 16;
  bottom_sprite.position = position;
  // visual
  int16_t moving_offset = is_moving ? 64 : 0;
  if (frame_count > 4) {
    if (ani_offset > 64) {
      ani_offset = 0;
    } else {
      ani_offset += 16;
    }
    frame_count = 0;
  } else {
    frame_count++;
  }
  int16_t u;
  int16_t v;
  switch (orientation) {
    case Character::UP :
      u = ani_offset + 96;
      v = moving_offset;
      top_sprite.uv = { u, v };
      v += 16;
      bottom_sprite.uv = { u, v };
      break;
    case Character::DOWN :
      u = ani_offset + 96;
      v = moving_offset + 32;
      top_sprite.uv = { u, v };
      v += 16;
      bottom_sprite.uv = { u, v };
      break;
    case Character::LEFT :
      u = ani_offset;
      v = moving_offset + 32;
      top_sprite.uv = { u, v };
      v += 16;
      bottom_sprite.uv = { u, v };
      break;
    case Character::RIGHT :
      u = ani_offset;
      v = moving_offset;
      top_sprite.uv = { u, v };
      v += 16;
      bottom_sprite.uv = { u, v };
      break;
  }
}

void HauntedGraveyard::Player::move(psyqo::Vec2 direction) {
  // normalize
  psyqo::FixedPoint<> x = direction.x;
  psyqo::FixedPoint<> y = direction.y;
  psyqo::FixedPoint<> s = x * x + y * y;
  psyqo::FixedPoint<> r = psyqo::SoftMath::inverseSquareRoot(s);
  velocity.x = x * r.abs();
  velocity.y = y * r.abs();
  is_moving = (velocity.x != 0.0_fp || velocity.y != 0.0_fp);
}

void HauntedGraveyard::Player::interact() {}
