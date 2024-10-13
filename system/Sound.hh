#pragma once

#include "psyqo/primitives.hh"

#define MAX_VOLUME 0x3FFF
#define FIXED_VOLUME_MASK 0x7FFF

#define SPU_ENABLE 0b1000000000000000
#define SPU_UNMUTE 0b0100000000000000
#define SPU_ENABLE_CD 0b0000000000000001

namespace HauntedGraveyard::system {

typedef uint32_t VoiceFlags;
// typedef char NosieFrequencyShift; ?? 4 bits

struct SoundControl {
  unsigned int enable : 1 = 1;
  unsigned int unmute : 1 = 1;
  unsigned int nosie_frequency_shift : 4 = 0;
  unsigned int noise_frequency_step : 2 = 0;
  unsigned int reverb_enable : 1 = 0;
  unsigned int IRQ9_enable : 1 = 0;
  unsigned int memory_transfer_mode : 2 = 0;
  unsigned int ext_reverb : 1 = 0;
  unsigned int cd_reverb : 1 = 0;
  unsigned int ext_enable : 1 = 0;
  unsigned int enable_cd : 1 = 1;
};

class Sound {

public:
  enum NoiseFrequencyStep {
    FOUR,
    FIVE,
    SIX,
    SEVEN
  };
  static void set_control(uint16_t cmd);
  static void update_control(uint16_t cmd);
  /**
   * Sets SPU main volume
   * @param volume to set
   */
  static void set_volume(int16_t volume);
  static void set_volume(psyqo::Vertex volume);
  /**
   * Sets SPU CD audio volume
   * @param volume to set
   */
  static void set_cd_volume(int16_t volume);
  static void set_cd_volume(psyqo::Vertex volume);
  static void set_voice_volume(unsigned voice_index, int16_t volume);
  static void set_voice_volume(unsigned voice_index, psyqo::Vertex volume);
  static void noise_enable(VoiceFlags noise);
  static void key_on(VoiceFlags key);
  static void key_off(VoiceFlags key);
};
}  // namespace HauntedGraveyard::system
