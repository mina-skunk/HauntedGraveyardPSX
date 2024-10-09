#pragma once

#include "graphics/UI/MultiLine.hh"
#include "psyqo/scene.hh"

namespace HauntedGraveyard {
/**
 * Ending
 */
class EndingScene final : public psyqo::Scene {
  // void start(Scene::StartReason reason) override;
  // void frame() override;
  // void teardown(Scene::TearDownReason reason) override;

public:
  // TODO
private:
  HauntedGraveyard::graphics::UI::MultiLine<13> credits = {
    { 16, 16 },
    {
      "          Credits",
      "Assets          LimeZu, Zingot",
      "Music            Artur Aravidi",
      "Developer           mina_skunk",
      "Editor                  yvaine",
      "SDK    psyqo (pcsx-redux team)",
      "      (thanks to nicolasnoble)"
    }
  };
};
}  // namespace HauntedGraveyard
