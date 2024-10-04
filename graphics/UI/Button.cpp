#include "Button.hh"

#define BUTTON_WIDTH 8

HauntedGraveyard::graphics::UI::ButtonFragment *HauntedGraveyard::graphics::UI::Button::get_fragment(uint8_t buffer_index) {
    uint8_t index = 0;
    for (uint8_t y = 0; y < 3; y++) {
      for (uint8_t x = 0; x < BUTTON_WIDTH; x++) {
        if (selected) {
            fragments[buffer_index].primitives[index].setColor({ .r=0x80, .g=0x80, .b=0x80 });
        } else {
            fragments[buffer_index].primitives[index].setColor({ .r=0x60, .g=0x60, .b=0x60 });
        }
        // positions
        int16_t base_x = position.x;
        int16_t base_y = position.y;
        fragments[buffer_index].primitives[index].position.x = base_x + (16 * x);
        fragments[buffer_index].primitives[index].position.y = base_y + (16 * y);
        // UVs
        if (x + y == 0) { // top left
            fragments[buffer_index].primitives[index].texInfo.u = 0 + (selected * 48);
            fragments[buffer_index].primitives[index].texInfo.v = 0;
        } else if(x == 0 && y == 2) { // bottom left
            fragments[buffer_index].primitives[index].texInfo.u = 0 + (selected * 48);
            fragments[buffer_index].primitives[index].texInfo.v = 32;
        } else if(y == 0 && x == BUTTON_WIDTH - 1) { // top right
            fragments[buffer_index].primitives[index].texInfo.u = 32 + (selected * 48);
            fragments[buffer_index].primitives[index].texInfo.v = 0;
        } else if(x == 0) { // left
            fragments[buffer_index].primitives[index].texInfo.u = 0 + (selected * 48);
            fragments[buffer_index].primitives[index].texInfo.v = 16;
        } else if(y == 0) { // top
            fragments[buffer_index].primitives[index].texInfo.u = 16 + (selected * 48);
            fragments[buffer_index].primitives[index].texInfo.v = 0;
        } else if(x + y == BUTTON_WIDTH + 1) { // bottom right
            fragments[buffer_index].primitives[index].texInfo.u = 32 + (selected * 48);
            fragments[buffer_index].primitives[index].texInfo.v = 32;
        } else if(x == BUTTON_WIDTH - 1) { // right 
            fragments[buffer_index].primitives[index].texInfo.u = 32 + (selected * 48);
            fragments[buffer_index].primitives[index].texInfo.v = 16;
        } else if(y == 2) { // bottom
            fragments[buffer_index].primitives[index].texInfo.u = 16 + (selected * 48);
            fragments[buffer_index].primitives[index].texInfo.v = 32;
        } else { // fill
            fragments[buffer_index].primitives[index].texInfo.u = 16 + (selected * 48);
            fragments[buffer_index].primitives[index].texInfo.v = 16;
        }
        index++;
      }
    }
    return &fragments[buffer_index];
}
