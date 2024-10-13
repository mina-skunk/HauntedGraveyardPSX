#include "common/hardware/spu.h"
#include "psyqo/primitives.hh"
#include "Sound.hh"

void HauntedGraveyard::system::Sound::set_control(uint16_t cmd) {
  SPU_CTRL = cmd;
}

void HauntedGraveyard::system::Sound::update_control(uint16_t cmd) {
  SPU_CTRL = SPU_CTRL | cmd;
}

void HauntedGraveyard::system::Sound::set_volume(int16_t volume) {
  SPU_VOL_MAIN_LEFT = volume >> 1;
  SPU_VOL_MAIN_RIGHT = volume >> 1;
}

void set_volume(psyqo::Vertex volume){
  SPU_VOL_MAIN_LEFT = volume.x >> 1;
  SPU_VOL_MAIN_RIGHT = volume.y >> 1;
}

void HauntedGraveyard::system::Sound::set_cd_volume(int16_t volume) {
  SPU_VOL_CD_LEFT = volume >> 1;
  SPU_VOL_CD_RIGHT = volume >> 1;
}

void HauntedGraveyard::system::Sound::set_cd_volume(psyqo::Vertex volume) {
  SPU_VOL_CD_LEFT = volume.x >> 1;
  SPU_VOL_CD_RIGHT = volume.y >> 1;
}

void HauntedGraveyard::system::Sound::set_voice_volume(unsigned voice_index, int16_t volume) {
  SPU_VOICES[voice_index].volumeLeft = volume >> 1;
  SPU_VOICES[voice_index].volumeRight = volume >> 1;
}

void HauntedGraveyard::system::Sound::set_voice_volume(unsigned voice_index, psyqo::Vertex volume) {
  SPU_VOICES[voice_index].volumeLeft = volume.x >> 1;
  SPU_VOICES[voice_index].volumeRight = volume.y >> 1;
}

void HauntedGraveyard::system::Sound::noise_enable(HauntedGraveyard::system::VoiceFlags noise) {
  SPU_NOISE_EN_LOW = noise & 0xFFFF;
  SPU_NOISE_EN_HIGH = noise >> 8;
}

void HauntedGraveyard::system::Sound::key_on(HauntedGraveyard::system::VoiceFlags key) {
  SPU_KEY_ON_LOW = key & 0xFFFF;
  SPU_KEY_ON_HIGH  = key >> 8;
}

void HauntedGraveyard::system::Sound::key_off(HauntedGraveyard::system::VoiceFlags key) {
  SPU_KEY_OFF_LOW = key & 0xFFFF;
  SPU_KEY_OFF_HIGH = key >> 8;
}

// TODO 

    // SPU_VOL_MAIN_LEFT = 0x3FFF;
    // SPU_VOICES[0].volumeLeft = 0x3FFF;
    // SPU_VOICES[0].volumeRight = 0x3FFF;
    // SPU_NOISE_EN_LOW = 1;
    // SPU_KEY_ON_LOW = 1;
