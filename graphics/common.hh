#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"

namespace HauntedGraveyard::graphics {
  struct SpriteBlock {
    psyqo::Prim::TPage t_page;
    psyqo::Prim::Sprite16x16 sprite;
  };
  typedef psyqo::Fragments::SimpleFragment<SpriteBlock> SpriteFragment;
}
