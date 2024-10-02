#include "common/hardware/spu.h"
#include "psyqo/primitives.hh"
#include "Sound.hh"

void HauntedGraveyard::system::Sound::control(uint16_t cmd) {
  SPU_CTRL = cmd;
}

void HauntedGraveyard::system::Sound::set_volume(int16_t volume) {
  SPU_VOL_MAIN_LEFT = volume >> 2;
  SPU_VOL_MAIN_RIGHT = volume >> 2;
}

void HauntedGraveyard::system::Sound::set_cd_volume(int16_t volume) {
  SPU_VOL_CD_LEFT = volume >> 2;
  SPU_VOL_CD_RIGHT = volume >> 2;
}

void HauntedGraveyard::system::Sound::set_voice_volume(unsigned voice, int16_t volume) {
  SPU_VOICES[voice].volumeLeft = volume >> 2;
  SPU_VOICES[voice].volumeRight = volume >> 2;
}

// TODO 

    // SPU_VOL_MAIN_LEFT = 0x3FFF;
    // SPU_VOICES[0].volumeLeft = 0x3FFF;
    // SPU_VOICES[0].volumeRight = 0x3FFF;
    // SPU_NOISE_EN_LOW = 1;
    // SPU_KEY_ON_LOW = 1;
