#pragma once

#include "psyqo/gpu.hh"
#include "psyqo/font.hh"
#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "RenderUI.hh"
#include "Element.hh"

namespace HauntedGraveyard::graphics::UI {
  class Button : public Element {
    friend class HauntedGraveyard::graphics::UI::RenderUI;
    public:
      const char* text;
      bool selected;
      Button(psyqo::Vertex position, const char* text, bool selected) : Element(position), text(text), selected(selected) {}
    private:
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, 24> fragment;
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, 24> *get_fragment();
  };
}
