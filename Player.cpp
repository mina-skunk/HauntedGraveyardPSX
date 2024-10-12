#include "Player.hh"

#include "Character.hh"
#include "psyqo/kernel.hh"
#include "psyqo/soft-math.hh"
#include "psyqo/vector.hh"

void HauntedGraveyard::Player::update() {
  // physics
  position += velocity * speed;
  top_sprite.position.x = position.x;
  top_sprite.position.y = position.y - 16;
  bottom_sprite.position = position;
  // visual
  uint8_t moving_offset = is_moving ? 64 : 0;
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
  uint8_t u;
  uint8_t v;
  switch (orientation) {
    case Character::UP:
      u = ani_offset + 96;
      v = moving_offset;
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
    case Character::DOWN:
      u = ani_offset + 96;
      v = moving_offset + 32;
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
    case Character::LEFT:
      u = ani_offset;
      v = moving_offset + 32;
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
      break;
    case Character::RIGHT:
      u = ani_offset;
      v = moving_offset;
      top_sprite.uv = {u, v};
      v += 16;
      bottom_sprite.uv = {u, v};
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

HauntedGraveyard::core::Area2D HauntedGraveyard::Player::get_interact_area() {
  HauntedGraveyard::core::Area2D interact_area = {position, {16.0_fp, 16.0_fp}};
  switch (orientation) {
    case Character::UP:
      interact_area.position.y = position.y - 16.0_fp;
      break;
    case Character::DOWN:
      interact_area.position.y = position.y + 16.0_fp;
      break;
    case Character::LEFT:
      interact_area.position.x = position.x - 16.0_fp;
      break;
    case Character::RIGHT:
      interact_area.position.x = position.x + 16.0_fp;
      break;
  }
  return interact_area;
}

void HauntedGraveyard::Player::apply_bounds(HauntedGraveyard::core::Area2D *bounds) {
  psyqo::Vec2 prediction;
  prediction.x = position.x + (velocity.x * speed);
  prediction.y = position.y + (velocity.y * speed);

  if (prediction.x < bounds->position.x || prediction.x > bounds->position.x + bounds->size.x - 16.0_fp) {
    velocity.x = 0.0_fp;
  }

  if (prediction.y < bounds->position.y || prediction.y > bounds->position.y + bounds->size.y - 16.0_fp) {
    velocity.y = 0.0_fp;
  }
}

void HauntedGraveyard::Player::apply_solid(HauntedGraveyard::core::Area2D *solid) {
  psyqo::Vec2 prediction;
  prediction.x = position.x + (velocity.x * speed);
  prediction.y = position.y + (velocity.y * speed);

  bool collided = solid->check_overlap({prediction, {16.0_fp, 16.0_fp}});

  if (collided) {
    velocity = {0.0_fp, 0.0_fp};
  }
}
