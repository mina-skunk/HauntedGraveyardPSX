#pragma once

#include "../TexturePage.hh"
#include "psyqo/font.hh"
#include "psyqo/gpu.hh"

namespace HauntedGraveyard::graphics::UI {
class Button;
class Image;
class TextBox;
class Label;
template<size_t L>
class MultiLine;
class RenderUI {
public:
  static HauntedGraveyard::graphics::TexturePage texture_page;
  static void init(psyqo::GPU *gpu_, psyqo::Font<> *font_);
  static void draw_button(HauntedGraveyard::graphics::UI::Button *button);
  static void draw_image(HauntedGraveyard::graphics::UI::Image *image);
  static void draw_text_box(HauntedGraveyard::graphics::UI::TextBox *text_box);
  static void draw_label(HauntedGraveyard::graphics::UI::Label *label);
  template<size_t L>
  static void draw_multiline(HauntedGraveyard::graphics::UI::MultiLine<L> *multiline);

private:
  static psyqo::GPU *gpu;
  static psyqo::Font<> *font;
  static void send_ui_texture_page();
};
}  // namespace HauntedGraveyard::graphics::UI
