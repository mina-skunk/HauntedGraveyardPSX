#include "psyqo/hardware/cdrom.hh"
#include "SimpleCDAudio.hh"
#include "Sound.hh"

void SimpleCDAudio::init() {
  Sound::set_volume(MAX_VOLUME);
  Sound::set_cd_volume(MAX_VOLUME);
  psyqo::Hardware::CDRom::Command.send(psyqo::Hardware::CDRom::CDL::INIT); // needed ??
  psyqo::Hardware::CDRom::Command.send(psyqo::Hardware::CDRom::CDL::SETMODE, CD_MODE_SECTOR_SIZE_WHOLE | CD_MODE_ENABLE_CDDA); // needed ??
  psyqo::Hardware::CDRom::Command.send(psyqo::Hardware::CDRom::CDL::DEMUTE); // needed ??
}

void SimpleCDAudio::play(uint8_t track) {
  psyqo::Hardware::CDRom::Command.send(psyqo::Hardware::CDRom::CDL::PLAY, track);
}
