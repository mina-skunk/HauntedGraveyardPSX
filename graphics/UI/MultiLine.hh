#pragma once

#include <EASTL/array.h>
#include <EASTL/string_view.h>

#include "Element.hh"
#include "RenderUI.hh"

namespace HauntedGraveyard::graphics::UI {
template<size_t L>
class MultiLine : public Element {
  friend class HauntedGraveyard::graphics::UI::RenderUI;
public:
  eastl::array<eastl::string_view, L> lines;
  uint8_t line_spacing = 16;
  MultiLine(psyqo::Vertex position, eastl::array<eastl::string_view, L> lines) : Element(position), lines(lines) {}
};
}  // namespace HauntedGraveyard::graphics::UI
