#pragma once

#include "psyqo/primitives.hh"

#define MAX_VOLUME 0xFFFF

namespace HauntedGraveyard {
  namespace system {
    class Sound {
      public:
        /**
        * Sets SPU main volume
        * @param volume x and y for l and r
        */
        static void set_volume(psyqo::Vertex volume);
        /**
        * Sets SPU main volume
        * @param volume to set
        */
        static void set_volume(uint16_t volume);
        /**
        * Sets SPU CD audio volume
        * @param volume x and y for l and r
        */
        static void set_cd_volume(psyqo::Vertex volume);
        /**
        * Sets SPU CD audio volume
        * @param volume to set
        */
        static void set_cd_volume(uint16_t volume);
    };
  }
}