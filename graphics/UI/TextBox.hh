#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "RenderUI.hh"
#include "Element.hh"

namespace HauntedGraveyard::graphics::UI {
  class TextBox : public Element {
    friend class HauntedGraveyard::graphics::UI::RenderUI;
    public:
      const char* line1;
      const char* line2;
      TextBox(psyqo::Vertex position, const char* line1, const char* line2) : Element(position), line1(line1), line2(line2) {}
    private:
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, 80> fragment;
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, 80> *get_fragment();
  };
}
