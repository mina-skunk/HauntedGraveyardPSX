#pragma once

#include "psyqo/scene.hh"
#include "psyqo/vector.hh"

namespace HauntedGraveyard {
  class LevelScene : public psyqo::Scene {
    protected:
      uint8_t keys = 0;
      psyqo::Vec2 spawn_point = { 0.0_fp, 0.0_fp };
      psyqo::Vec2 exit = { 0.0_fp, 0.0_fp };
      psyqo::Color background_color = { .r = 0x40, .g = 0x3d, .b = 0x37 };
      virtual void update() {};
      virtual void draw() {};
  };
}
