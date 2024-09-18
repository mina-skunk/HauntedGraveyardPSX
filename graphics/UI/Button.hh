#pragma once

#include "psyqo/primitives.hh"
#include "Element.hh"

namespace HauntedGraveyard {
  namespace graphics {
    namespace UI {
      class Button : public Element {
        public:
          const char* text;
          bool selected;
        private:
          psyqo::Prim::Sprite16x16 primitive;
      };
    }
  }
}
