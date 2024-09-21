#include "RenderUI.hh"
#include "Button.hh"
#include "Image.hh"

HauntedGraveyard::graphics::TexturePage HauntedGraveyard::graphics::UI::RenderUI::texture_page = { 12, 0};
psyqo::GPU* HauntedGraveyard::graphics::UI::RenderUI::gpu;
psyqo::Font<>* HauntedGraveyard::graphics::UI::RenderUI::font;

void HauntedGraveyard::graphics::UI::RenderUI::init(psyqo::GPU *gpu_, psyqo::Font<> *font_) {
  HauntedGraveyard::graphics::UI::RenderUI::gpu = gpu_;
  HauntedGraveyard::graphics::UI::RenderUI::font = font_;
}

void HauntedGraveyard::graphics::UI::RenderUI::draw_button(HauntedGraveyard::graphics::UI::Button *button) {
    // set tex page
    psyqo::Prim::TPage ui_tex_page;
    ui_tex_page.attr.setPageX(texture_page.col).setPageY(texture_page.row).set(psyqo::Prim::TPageAttr::Tex16Bits);
    gpu->sendPrimitive(ui_tex_page);

    // tex
    button->get_fragment();
    gpu->sendFragment(button->fragment);

    // // text
    int16_t text_x = button->position.x + 16;
    int16_t text_y = button->position.y + 16 + button->selected;
    font->print(*gpu, button->text, {{.x = text_x, .y = text_y}}, {{.r=0x80, .g=0x80, .b=0x80}});
}

void HauntedGraveyard::graphics::UI::RenderUI::draw_image(HauntedGraveyard::graphics::UI::Image *image) {
  // set tex page
  psyqo::Prim::TPage image_tex_page;
  image_tex_page.attr.setPageX(image->texture_page.col).setPageY(image->texture_page.row).set(psyqo::Prim::TPageAttr::Tex16Bits);
  gpu->sendPrimitive(image_tex_page);
  // tex
  image->get_primitive();
  image->primitive.setColor({{ .r = 0xff, .g = 0xff, .b = 0xff }});
  image->primitive.texInfo.u = 0;
  image->primitive.texInfo.v = 0;
  gpu->sendPrimitive(image->primitive);
}
