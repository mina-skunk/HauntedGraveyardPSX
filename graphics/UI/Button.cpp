
#include "Button.hh"
#include "psyqo/primitives/control.hh"

#define BUTTON_WIDTH 8

psyqo::Fragments::FixedFragment<psyqo::Prim::Sprite16x16, 24> *HauntedGraveyard::graphics::UI::Button::get_fragment() {
    uint8_t index = 0;
    for (uint8_t y = 0; y < 3; y++) {
      for (uint8_t x = 0; x < BUTTON_WIDTH; x++) {
        fragment.primitives[index].setColor({.r=255, .g=255, .b=255});
        // positions
        int16_t base_x = position.x;
        int16_t base_y = position.y;
        fragment.primitives[index].position.x = base_x + (16 * x);
        fragment.primitives[index].position.y = base_y + (16 * y);
        // UVs
        if (x + y == 0) { // top left
            fragment.primitives[index].texInfo.u = 0 + (selected * 48);
            fragment.primitives[index].texInfo.v = 0;
        } else if(x == 0 && y == 2) { // bottom left
            fragment.primitives[index].texInfo.u = 0 + (selected * 48);
            fragment.primitives[index].texInfo.v = 32;
        } else if(y == 0 && x == BUTTON_WIDTH - 1) { // top right
            fragment.primitives[index].texInfo.u = 32 + (selected * 48);
            fragment.primitives[index].texInfo.v = 0;
        } else if(x == 0) { // left
            fragment.primitives[index].texInfo.u = 0 + (selected * 48);
            fragment.primitives[index].texInfo.v = 16;
        } else if(y == 0) { // top
            fragment.primitives[index].texInfo.u = 16 + (selected * 48);
            fragment.primitives[index].texInfo.v = 0;
        } else if(x + y == BUTTON_WIDTH + 1) { // bottom right
            fragment.primitives[index].texInfo.u = 32 + (selected * 48);
            fragment.primitives[index].texInfo.v = 32;
        } else if(x == BUTTON_WIDTH - 1) { // right 
            fragment.primitives[index].texInfo.u = 32 + (selected * 48);
            fragment.primitives[index].texInfo.v = 16;
        } else if(y == 2) { // bottom
            fragment.primitives[index].texInfo.u = 16 + (selected * 48);
            fragment.primitives[index].texInfo.v = 32;
        } else { // fill
            fragment.primitives[index].texInfo.u = 16 + (selected * 48);
            fragment.primitives[index].texInfo.v = 16;
        }
        index++;
      }
    }
    fragment.count = 24;
    return &fragment;
}
