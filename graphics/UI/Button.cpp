
#include "Button.hh"
#include "psyqo/primitives/control.hh"

void HauntedGraveyard::graphics::UI::Button::draw_button(psyqo::GPU gpu, psyqo::Font<> *font) {
    // set tex page
    psyqo::Prim::TPage ui_text_page;
    ui_text_page.attr.setPageX(12).setPageY(0).set(psyqo::Prim::TPageAttr::Tex16Bits);
    gpu.sendPrimitive(ui_text_page);

    // tex
    uint8_t index = 0;
    for (uint8_t y = 0; y < 3; y++) {
      for (uint8_t x = 0; x < 4; x++) {
        // positions
        fragment.primitives[index].position.x = position.x + (16 * x);
        fragment.primitives[index].position.y = position.y + (16 * y);
        // UVs
        if (x + y == 0) {
            fragment.primitives[index].texInfo.u = 0 + (selected * 48);
            fragment.primitives[index].texInfo.v = 0;
        } else if(x == 0) {
            fragment.primitives[index].texInfo.u = 16 + (selected * 48);
            fragment.primitives[index].texInfo.v = 0;
        } else if(y == 0) {
            fragment.primitives[index].texInfo.u = 0 + (selected * 48);
            fragment.primitives[index].texInfo.v = 16;
        } else if(x + y == 5) {
            fragment.primitives[index].texInfo.u = 32 + (selected * 48);
            fragment.primitives[index].texInfo.v = 32;
        } else if(x == 3) {
            fragment.primitives[index].texInfo.u = 32 + (selected * 48);
            fragment.primitives[index].texInfo.v = 16;
        } else if(y == 2) {
            fragment.primitives[index].texInfo.u = 16 + (selected * 48);
            fragment.primitives[index].texInfo.v = 32;
        } else {
            fragment.primitives[index].texInfo.u = 16 + (selected * 48);
            fragment.primitives[index].texInfo.v = 16;
        }
        index++;
      }
    }
    fragment.count = 12;
    // gpu.sendFragment(fragment);

    // // text
    int16_t text_x = position.x + 4;
    int16_t text_y = position.y + 4;
    // font->print(gpu, text, {{.x = text_x, .y = text_y}}, {{.r=255, .g=255, .b=255}});
}
