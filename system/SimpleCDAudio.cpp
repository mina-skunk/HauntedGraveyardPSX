#include "SimpleCDAudio.hh"

bool HauntedGraveyard::system::SimpleCDAudio::is_playing = false;

void HauntedGraveyard::system::SimpleCDAudio::play(psyqo::CDRomDevice *cdrom, unsigned track, bool repeat) {
  cdrom->playCDDATrack(track, [cdrom, track, repeat](bool success) {
        if (!success) {
            HauntedGraveyard::system::SimpleCDAudio::is_playing = false;
            // TODO throw error
            return;
        }
        HauntedGraveyard::system::SimpleCDAudio::is_playing = !HauntedGraveyard::system::SimpleCDAudio::is_playing;
        if (!HauntedGraveyard::system::SimpleCDAudio::is_playing && repeat) { // loop
            HauntedGraveyard::system::SimpleCDAudio::play(cdrom, track, true);
        }
    });
}

void HauntedGraveyard::system::SimpleCDAudio::stop(psyqo::CDRomDevice *cdrom) {
  cdrom->stopCDDA();
  HauntedGraveyard::system::SimpleCDAudio::is_playing = false;
}
