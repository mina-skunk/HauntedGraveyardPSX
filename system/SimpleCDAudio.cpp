#include "psyqo/hardware/cdrom.hh"
#include "SimpleCDAudio.hh"
#include "Sound.hh"
#include <cstdint>

void HauntedGraveyard::system::SimpleCDAudio::init() {
  Sound::set_volume(MAX_VOLUME);
  Sound::set_cd_volume(MAX_VOLUME);
  Sound::control(SPU_ENABLE | SPU_UNMUTE | SPU_ENABLE_CD);
  psyqo::Hardware::CDRom::Command.send(psyqo::Hardware::CDRom::CDL::SETMODE, CD_MODE_SECTOR_SIZE_WHOLE | CD_MODE_AUTO_PAUSE | CD_MODE_ENABLE_CDDA);
  psyqo::Hardware::CDRom::Command.send(psyqo::Hardware::CDRom::CDL::DEMUTE);
}

void HauntedGraveyard::system::SimpleCDAudio::play(uint8_t track) {
  psyqo::Hardware::CDRom::Command.send(psyqo::Hardware::CDRom::CDL::PLAY, track);
}
