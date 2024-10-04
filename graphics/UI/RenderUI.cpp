#include "RenderUI.hh"
#include "Button.hh"
#include "Image.hh"
#include "TextBox.hh"

HauntedGraveyard::graphics::TexturePage HauntedGraveyard::graphics::UI::RenderUI::texture_page = { 12, 0 };
psyqo::GPU* HauntedGraveyard::graphics::UI::RenderUI::gpu;
psyqo::Font<>* HauntedGraveyard::graphics::UI::RenderUI::font;

void HauntedGraveyard::graphics::UI::RenderUI::init(psyqo::GPU *gpu_, psyqo::Font<> *font_) {
  HauntedGraveyard::graphics::UI::RenderUI::gpu = gpu_;
  HauntedGraveyard::graphics::UI::RenderUI::font = font_;
}

void HauntedGraveyard::graphics::UI::RenderUI::draw_button(HauntedGraveyard::graphics::UI::Button *button) {
    auto fragment = button->get_fragment(gpu->getParity());
    gpu->chain(*fragment);

    // text
    int16_t text_x = button->position.x + 16;
    int16_t text_y = button->position.y + 16 + button->selected;
    font->chainprint(*gpu, button->text, {{.x = text_x, .y = text_y}}, {{.r=0x10, .g=0x10, .b=0x10}});
}

void HauntedGraveyard::graphics::UI::RenderUI::draw_image(HauntedGraveyard::graphics::UI::Image *image) {
  auto fragment = image->get_fragment(gpu->getParity());
  gpu->chain(*fragment);
}

void HauntedGraveyard::graphics::UI::RenderUI::draw_text_box(HauntedGraveyard::graphics::UI::TextBox *text_box) {
    auto fragment = text_box->get_fragment(gpu->getParity());
    gpu->chain(*fragment);

    // text
    // line 1
    int16_t text_x = text_box->position.x + 16;
    int16_t text_y = text_box->position.y + 16;
    font->chainprint(*gpu, text_box->line1, {{.x = text_x, .y = text_y}}, {{.r=0x10, .g=0x10, .b=0x10}});
    // lines 2
    text_y += 16;
    font->chainprint(*gpu, text_box->line2, {{.x = text_x, .y = text_y}}, {{.r=0x10, .g=0x10, .b=0x10}});
}

void HauntedGraveyard::graphics::UI::RenderUI::send_ui_texture_page() {
  // set tex page
  psyqo::Prim::TPage ui_tex_page;
  ui_tex_page.attr.setPageX(texture_page.col).setPageY(texture_page.row).set(psyqo::Prim::TPageAttr::Tex16Bits);
  gpu->sendPrimitive(ui_tex_page);
}
