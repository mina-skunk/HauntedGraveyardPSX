#pragma once

#include "psyqo/primitives.hh"

#define MAX_VOLUME 0xFFFF

namespace HauntedGraveyard::system {
  class Sound {
    public:
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
