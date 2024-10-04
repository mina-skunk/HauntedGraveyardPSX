#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "RenderUI.hh"
#include "Element.hh"

#define BUTON_SPRITE_COUNT 24

namespace HauntedGraveyard::graphics::UI {
  class Button : public Element {
    friend class HauntedGraveyard::graphics::UI::RenderUI;
    public:
      const char* text;
      bool selected;
      inline Button(psyqo::Vertex position, const char* text, bool selected) : Element(position), text(text), selected(selected) {
        fragment.count = BUTON_SPRITE_COUNT;
      }
    private:
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, BUTON_SPRITE_COUNT> fragment;
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, BUTON_SPRITE_COUNT> *get_fragment();
  };
}
