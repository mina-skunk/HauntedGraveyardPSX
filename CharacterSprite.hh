#pragma once

#include "psyqo/vector.hh"
#include "graphics/Sprite.hh"

namespace HauntedGraveyard {
  class CharacterSprite : public HauntedGraveyard::graphics::Sprite  {
    public:
      enum Orientation {
        UP,
        DOWN,
        LEFT,
        RIGHT
      };
      Orientation orientation = Orientation::DOWN;
      CharacterSprite(psyqo::Vec2 position, HauntedGraveyard::graphics::TexturePage texture_page) : Sprite(position, texture_page) {}
      // virtual void update() {}
  };
}
