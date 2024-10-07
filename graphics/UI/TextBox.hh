#pragma once

#include "Element.hh"
#include "RenderUI.hh"
#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"

#define TEXT_BOX_SPRITE_COUNT 80

namespace HauntedGraveyard::graphics::UI {
typedef psyqo::Fragments::FixedFragmentWithPrologue<psyqo::Prim::TPage, psyqo::Prim::Sprite16x16, TEXT_BOX_SPRITE_COUNT> TextBoxFragment;
// TODO turn into 9 Segment and lable and or multiline
class TextBox : public Element {
  friend class HauntedGraveyard::graphics::UI::RenderUI;

public:
  const char* line1;
  const char* line2;
  TextBox(psyqo::Vertex position, const char* line1, const char* line2) : Element(position), line1(line1), line2(line2) {
    for (auto& fragment : fragments) {
      RenderUI::texture_page.get_primative(&fragment.prologue);
      fragment.count = TEXT_BOX_SPRITE_COUNT;
    }
  }

private:
  TextBoxFragment fragments[2];
  TextBoxFragment* get_fragment(uint8_t buffer_index);
};
}  // namespace HauntedGraveyard::graphics::UI
