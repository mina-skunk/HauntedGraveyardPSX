#pragma once

#include "../TexturePage.hh"
#include "Element.hh"
#include "RenderUI.hh"
#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "psyqo/primitives/common.hh"

namespace HauntedGraveyard::graphics::UI {
struct ImageBlock {
  psyqo::Prim::TPage t_page;
  psyqo::Prim::Sprite sprite;
};
typedef psyqo::Fragments::SimpleFragment<ImageBlock> ImageFragment;
class Image : public Element {
  friend class HauntedGraveyard::graphics::UI::RenderUI;

public:
  psyqo::Vertex size;
  HauntedGraveyard::graphics::TexturePage texture_page;
  psyqo::PrimPieces::UVCoords uv = {0, 0};
  Image(psyqo::Vertex position, psyqo::Vertex size, HauntedGraveyard::graphics::TexturePage texture_page) : Element(position), size(size), texture_page(texture_page) {
    for (auto &fragment : fragments) {
      texture_page.get_primative(&fragment.primitive.t_page);
      fragment.primitive.sprite.position = position;
      fragment.primitive.sprite.size = size;
      fragment.primitive.sprite.texInfo.u = uv.u;
      fragment.primitive.sprite.texInfo.v = uv.v;
    }
  }
  void modulate_color(psyqo::Color color);

private:
  ImageFragment fragments[2];
  ImageFragment *get_fragment(uint8_t buffer_index);
};
}  // namespace HauntedGraveyard::graphics::UI
