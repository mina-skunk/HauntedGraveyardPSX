#pragma once

#include "psyqo/scene.hh"

namespace HauntedGraveyard {
  class LevelScene final : public psyqo::Scene {
    protected:
      virtual void update();
      virtual void draw();
  };
}
