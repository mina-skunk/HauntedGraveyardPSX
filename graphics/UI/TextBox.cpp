#include "TextBox.hh"

#define TEXT_BOX_WIDTH 20
#define TEXT_BOX_HIGHT 4

psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, 80> *HauntedGraveyard::graphics::UI::TextBox::get_fragment() {
    uint8_t index = 0;
    for (uint8_t y = 0; y < TEXT_BOX_HIGHT; y++) {
      for (uint8_t x = 0; x < TEXT_BOX_WIDTH; x++) {
        fragment.primitives[index].setColor({.r=255, .g=255, .b=255});
        // positions
        int16_t base_x = position.x;
        int16_t base_y = position.y;
        fragment.primitives[index].position.x = base_x + (16 * x);
        fragment.primitives[index].position.y = base_y + (16 * y);
        // UVs
        if (x + y == 0) { // top left
            fragment.primitives[index].texInfo.u = 0;
            fragment.primitives[index].texInfo.v = 48;
        } else if(x == 0 && y == TEXT_BOX_HIGHT - 1) { // bottom left
            fragment.primitives[index].texInfo.u = 0;
            fragment.primitives[index].texInfo.v = 80;
        } else if(y == 0 && x == TEXT_BOX_WIDTH - 1) { // top right
            fragment.primitives[index].texInfo.u = 32;
            fragment.primitives[index].texInfo.v = 48;
        } else if(x == 0) { // left
            fragment.primitives[index].texInfo.u = 0;
            fragment.primitives[index].texInfo.v = 64;
        } else if(y == 0) { // top
            fragment.primitives[index].texInfo.u = 16;
            fragment.primitives[index].texInfo.v = 48;
        } else if(x + y == TEXT_BOX_WIDTH - 1 + TEXT_BOX_HIGHT - 1) { // bottom right
            fragment.primitives[index].texInfo.u = 32;
            fragment.primitives[index].texInfo.v = 80;
        } else if(x == TEXT_BOX_WIDTH - 1) { // right 
            fragment.primitives[index].texInfo.u = 32;
            fragment.primitives[index].texInfo.v = 64;
        } else if(y == TEXT_BOX_HIGHT - 1) { // bottom
            fragment.primitives[index].texInfo.u = 16;
            fragment.primitives[index].texInfo.v = 80;
        } else { // fill
            fragment.primitives[index].texInfo.u = 16;
            fragment.primitives[index].texInfo.v = 64;
        }
        index++;
      }
    }
    fragment.count = 80;
    return &fragment;
}
