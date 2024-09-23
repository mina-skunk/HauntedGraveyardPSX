#pragma once

#include "psyqo/cdrom.hh"

#define CD_MODE_SECTOR_SIZE_WHOLE 0b00100000
#define CD_MODE_REPORT_INT 0b00000100
#define CD_MODE_AUTO_PAUSE 0b00000010
#define CD_MODE_ENABLE_CDDA 0b00000001

namespace HauntedGraveyard::system {
  class SimpleCDAudio {
    public:
      /**
      * Perpare for playing CD audio
      */
      static void init();
      /**
      * Play CD track
      * @param track numbere to play
      */
      static void play(uint8_t track);
  };
}
