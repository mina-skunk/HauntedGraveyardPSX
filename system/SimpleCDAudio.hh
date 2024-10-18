#pragma once

#include "psyqo/cdrom-device.hh"

namespace HauntedGraveyard::system {
  class SimpleCDAudio {
    public:
      static bool is_playing;
      static bool is_stopping;
      /**
      * Play CD track
      * @param track numbere to play
      */
      static void play(psyqo::CDRomDevice *cdrom, unsigned track, bool repeat);
      static void stop(psyqo::CDRomDevice *cdrom);
  };
}
