#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "RenderUI.hh"
#include "Element.hh"
#include "psyqo/primitives/control.hh"

#define BUTON_SPRITE_COUNT 24

namespace HauntedGraveyard::graphics::UI {
  typedef psyqo::Fragments::FixedFragmentWithPrologue<psyqo::Prim::TPage, psyqo::Prim::Sprite16x16, BUTON_SPRITE_COUNT> ButtonFragment;
  class Button : public Element {
    friend class HauntedGraveyard::graphics::UI::RenderUI;
    public:
      const char* text;
      bool selected;
      inline Button(psyqo::Vertex position, const char* text, bool selected) : Element(position), text(text), selected(selected) {
        for (auto & fragment : fragments) {
          RenderUI::texture_page.get_primative(&fragment.prologue);
          fragment.count = BUTON_SPRITE_COUNT;
        }
      }
    private:
      ButtonFragment fragments[2];
      ButtonFragment *get_fragment(uint8_t buffer_index);
  };
}
