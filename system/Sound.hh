#pragma once

#include "psyqo/primitives.hh"

#define MAX_VOLUME 0x3FFF
#define FIXED_VOLUME_MASK 0x7FFF

#define SPU_ENABLE 0b1000000000000000
#define SPU_UNMUTE 0b0100000000000000
#define SPU_ENABLE_CD 0b0000000000000001

namespace HauntedGraveyard::system {
  class Sound {
    public:
      static void control(uint16_t cmd);
      /**
      * Sets SPU main volume
      * @param volume to set
      */
      static void set_volume(uint16_t volume);
      /**
      * Sets SPU CD audio volume
      * @param volume to set
      */
      static void set_cd_volume(uint16_t volume);
  };
}
