#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "RenderUI.hh"
#include "Element.hh"

#define TEXT_BOX_SPRITE_COUNT 80

namespace HauntedGraveyard::graphics::UI {
  typedef psyqo::Fragments::FixedFragmentWithPrologue<psyqo::Prim::TPage, psyqo::Prim::Sprite16x16, TEXT_BOX_SPRITE_COUNT> TextBoxFragment;
  class TextBox : public Element {
    friend class HauntedGraveyard::graphics::UI::RenderUI;
    public:
      const char* line1;
      const char* line2;
      inline TextBox(psyqo::Vertex position, const char* line1, const char* line2) : Element(position), line1(line1), line2(line2) {
        for (auto & fragment : fragments) {
          RenderUI::texture_page.get_primative(&fragment.prologue);
          fragment.count = TEXT_BOX_SPRITE_COUNT;
        }
      }
    private:
      TextBoxFragment fragments[2];
      TextBoxFragment *get_fragment(uint8_t buffer_index);
  };
}
