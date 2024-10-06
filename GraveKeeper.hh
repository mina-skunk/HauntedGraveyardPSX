#pragma once

#include "Character.hh"

namespace HauntedGraveyard {
class GraveKeeper final : public HauntedGraveyard::Character {
public:
  psyqo::Vec2 position;
  psyqo::Vec2 size;
};
}  // namespace HauntedGraveyard
