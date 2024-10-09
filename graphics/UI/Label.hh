#pragma once

#include <EASTL/string_view.h>

#include "Element.hh"
#include "RenderUI.hh"

namespace HauntedGraveyard::graphics::UI {
class Label : public Element {
  friend class HauntedGraveyard::graphics::UI::RenderUI;
public:
  eastl::string_view text;
  bool shadow = true;
  Label(psyqo::Vertex position, eastl::string_view text) : Element(position), text(text) {}
};
}  // namespace HauntedGraveyard::graphics::UI
