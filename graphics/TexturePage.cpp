#include "TexturePage.hh"

psyqo::Vertex HauntedGraveyard::graphics::TexturePage::get_VRAM_position() {
    int16_t x = col * 64;
    int16_t y = row * 256;
    return  {x , y };
}

void HauntedGraveyard::graphics::TexturePage::get_primative(psyqo::Prim::TPage *out) {
    out->attr.setPageX(col).setPageY(row).set(psyqo::Prim::TPageAttr::Tex16Bits);
}
