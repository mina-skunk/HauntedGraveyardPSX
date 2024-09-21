#include "TexturePage.hh"

psyqo::Vertex HauntedGraveyard::graphics::TexturePage::get_VRAM_position() {
    int16_t x = col * 64;
    int16_t y = row * 512;
    return  {x , y };
}
