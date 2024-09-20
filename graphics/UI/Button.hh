#pragma once

#include "psyqo/gpu.hh"
#include "psyqo/font.hh"
#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "Element.hh"

namespace HauntedGraveyard {
  namespace graphics {
    namespace UI {
      class Button : public Element {
        public:
          const char* text;
          bool selected;
          Button(psyqo::Vertex position, const char* text, bool selected) : Element(position), text(text), selected(selected) {}
          void draw_button(psyqo::GPU *gpu, psyqo::Font<> *font);
        private:
          psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, 12> fragment;
      };
    }
  }
}
