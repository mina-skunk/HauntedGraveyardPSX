#include "common/hardware/spu.h"
#include "psyqo/primitives.hh"
#include "Sound.hh"

void Sound::set_volume(psyqo::Vertex volume) {
  SPU_VOL_MAIN_LEFT = volume.x;
  SPU_VOL_MAIN_RIGHT = volume.y;
}

void Sound::set_volume(uint16_t volume) {
  SPU_VOL_MAIN_LEFT = volume;
  SPU_VOL_MAIN_RIGHT = volume;
}

void Sound::set_cd_volume(psyqo::Vertex volume) {
  SPU_VOL_CD_LEFT = volume.x;
  SPU_VOL_CD_RIGHT = volume.y;
}

void Sound::set_cd_volume(uint16_t volume) {
  SPU_VOL_CD_LEFT = volume;
  SPU_VOL_CD_RIGHT = volume;
}
