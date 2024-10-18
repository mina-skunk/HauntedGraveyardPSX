#include "common/syscalls/syscalls.h"
#include "SimpleCDAudio.hh"

bool HauntedGraveyard::system::SimpleCDAudio::is_playing = false;
bool HauntedGraveyard::system::SimpleCDAudio::is_stopping = false;

void HauntedGraveyard::system::SimpleCDAudio::play(psyqo::CDRomDevice *cdrom, unsigned track, bool repeat) {
  if (!is_playing) {
    cdrom->playCDDATrack(track, [cdrom, track, repeat](bool success) {
      if (!success) {
        is_playing = false;
        syscall_puts("CD play failed\n");
        return;
      }
      if (is_stopping) {
        is_stopping = false;
        is_playing = false;
      } else {
        is_playing = !is_playing;
        if (!is_playing && repeat) {  // loop
          play(cdrom, track, true);
        }
      }
    });
  } else {
    syscall_puts("CD already playing\n");
  }
}

void HauntedGraveyard::system::SimpleCDAudio::stop(psyqo::CDRomDevice *cdrom) {
  if (is_playing && !is_stopping) {
    cdrom->stopCDDA();
    is_stopping = true;
  } else {
    syscall_puts("CD already stoped or being stopped\n");
  }
}
