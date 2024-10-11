#include "JackOLantern.hh"

void HauntedGraveyard::JackOLantern::update() {
  if (!has_key) {
    if (frame_count > 4) {
      if (ani_offset > 96) {
        ani_offset = 0;
      } else {
        ani_offset += 16;
      }
      frame_count = 0;
    } else {
      frame_count++;
    }
    sprite.uv.u = ani_offset;
  }
}
