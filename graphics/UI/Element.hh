#pragma once

#include "psyqo/primitives/common.hh"

namespace HauntedGraveyard {
  namespace graphics {
    namespace UI {
      class Element {
        public:
          psyqo::Vertex position;
          Element(psyqo::Vertex position) : position(position) {}
      };
    }
  }
}
