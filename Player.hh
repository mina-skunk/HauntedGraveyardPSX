#pragma once

#include "psyqo/vector.hh"
#include "Character.hh"

namespace HauntedGraveyard {
  class Player final : public HauntedGraveyard::Character  {
    
    public:
      void update() override;
      Player(psyqo::Vec2 position, HauntedGraveyard::graphics::TexturePage texture_page) : Character(position, texture_page) {}
      void move(psyqo::Vec2 direction);
      void interact();
  };
}
