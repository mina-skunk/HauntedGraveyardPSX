#include "TextBox.hh"

#define TEXT_BOX_WIDTH 20
#define TEXT_BOX_HIGHT 4

HauntedGraveyard::graphics::UI::TextBoxFragment *HauntedGraveyard::graphics::UI::TextBox::get_fragment(uint8_t buffer_index) {
  uint8_t index = 0;
  for (uint8_t y = 0; y < TEXT_BOX_HIGHT; y++) {
    for (uint8_t x = 0; x < TEXT_BOX_WIDTH; x++) {
      // positions
      int16_t base_x = position.x;
      int16_t base_y = position.y;
      fragments[buffer_index].primitives[index].position.x = base_x + (16 * x);
      fragments[buffer_index].primitives[index].position.y = base_y + (16 * y);
      // UVs
      if (x + y == 0) {  // top left
        fragments[buffer_index].primitives[index].texInfo.u = 0;
        fragments[buffer_index].primitives[index].texInfo.v = 48;
      } else if (x == 0 && y == TEXT_BOX_HIGHT - 1) {  // bottom left
        fragments[buffer_index].primitives[index].texInfo.u = 0;
        fragments[buffer_index].primitives[index].texInfo.v = 80;
      } else if (y == 0 && x == TEXT_BOX_WIDTH - 1) {  // top right
        fragments[buffer_index].primitives[index].texInfo.u = 32;
        fragments[buffer_index].primitives[index].texInfo.v = 48;
      } else if (x == 0) {  // left
        fragments[buffer_index].primitives[index].texInfo.u = 0;
        fragments[buffer_index].primitives[index].texInfo.v = 64;
      } else if (y == 0) {  // top
        fragments[buffer_index].primitives[index].texInfo.u = 16;
        fragments[buffer_index].primitives[index].texInfo.v = 48;
      } else if (x + y == TEXT_BOX_WIDTH - 1 + TEXT_BOX_HIGHT - 1) {  // bottom right
        fragments[buffer_index].primitives[index].texInfo.u = 32;
        fragments[buffer_index].primitives[index].texInfo.v = 80;
      } else if (x == TEXT_BOX_WIDTH - 1) {  // right
        fragments[buffer_index].primitives[index].texInfo.u = 32;
        fragments[buffer_index].primitives[index].texInfo.v = 64;
      } else if (y == TEXT_BOX_HIGHT - 1) {  // bottom
        fragments[buffer_index].primitives[index].texInfo.u = 16;
        fragments[buffer_index].primitives[index].texInfo.v = 80;
      } else {  // fill
        fragments[buffer_index].primitives[index].texInfo.u = 16;
        fragments[buffer_index].primitives[index].texInfo.v = 64;
      }
      index++;
    }
  }
  return &fragments[buffer_index];
}
