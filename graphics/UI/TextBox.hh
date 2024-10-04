#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "RenderUI.hh"
#include "Element.hh"

#define TEXT_BOX_SPRITE_COUNT 80

namespace HauntedGraveyard::graphics::UI {
  class TextBox : public Element {
    friend class HauntedGraveyard::graphics::UI::RenderUI;
    public:
      const char* line1;
      const char* line2;
      inline TextBox(psyqo::Vertex position, const char* line1, const char* line2) : Element(position), line1(line1), line2(line2) {
        fragment.count = TEXT_BOX_SPRITE_COUNT;
      }
    private:
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, TEXT_BOX_SPRITE_COUNT> fragment;
      psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, TEXT_BOX_SPRITE_COUNT> *get_fragment();
  };
}
