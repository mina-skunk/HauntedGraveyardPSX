#pragma once

#include "psyqo/gpu.hh"
#include "psyqo/font.hh"
#include "../TexturePage.hh"

namespace HauntedGraveyard::graphics::UI {
  class Button;
  class Image;
  class TextBox;
  class RenderUI {
    public:
      static HauntedGraveyard::graphics::TexturePage texture_page;
      static void init(psyqo::GPU *gpu_, psyqo::Font<> *font_);
      static void draw_button(HauntedGraveyard::graphics::UI::Button *button);
      static void draw_image(HauntedGraveyard::graphics::UI::Image *image);
      static void draw_text_box(HauntedGraveyard::graphics::UI::TextBox *text_box);
    private:
      static psyqo::GPU *gpu;
      static psyqo::Font<> *font;
      static void send_ui_texture_page();
  };
}
