#pragma once

#include "psyqo/primitives/common.hh"

namespace HauntedGraveyard::graphics::UI {
class Element {
public:
  psyqo::Vertex position;
  Element(psyqo::Vertex position) : position(position) {}
};
}  // namespace HauntedGraveyard::graphics::UI
