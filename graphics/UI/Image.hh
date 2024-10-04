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
      psyqo::Vertex uv = { 0, 0 };
      inline Image(psyqo::Vertex position, psyqo::Vertex size, HauntedGraveyard::graphics::TexturePage texture_page) : Element(position), size(size), texture_page(texture_page) {
        primitive.position = position;
        primitive.size = size;
        primitive.texInfo.u = uv.u;
        primitive.texInfo.v = uv.v;
      }
      void modulate_color(psyqo::Color color);
    private:
      psyqo::Prim::Sprite primitive;
      psyqo::Prim::Sprite *get_primitive();
  };
}
