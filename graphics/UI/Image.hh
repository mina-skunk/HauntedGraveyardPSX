#pragma once

#include "psyqo/primitives.hh"
#include "RenderUI.hh"
#include "Element.hh"
#include "../TexturePage.hh"

namespace HauntedGraveyard::graphics::UI {
  class Image : public Element {
    friend class HauntedGraveyard::graphics::UI::RenderUI;
    public:
      psyqo::Vertex size;
      HauntedGraveyard::graphics::TexturePage texture_page;
      psyqo::Color color = { .r = 0x80, .g = 0x80, .b = 0x80 };
      psyqo::Vertex uv = { 0, 0 };
      Image(psyqo::Vertex position, psyqo::Vertex size, HauntedGraveyard::graphics::TexturePage texture_page) : Element(position), size(size), texture_page(texture_page) {}
    private:
      psyqo::Prim::Sprite primitive;
      psyqo::Prim::Sprite *get_primitive();
  };
}
