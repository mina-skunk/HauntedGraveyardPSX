#include "GameApp.hh"

#include "graphics/Render2D.hh"
#include "graphics/UI/RenderUI.hh"

psyqo::Font<> HauntedGraveyard::GameApp::font;

psyqo::SimplePad HauntedGraveyard::GameApp::input;

psyqo::CDRomDevice HauntedGraveyard::GameApp::cdrom;

void HauntedGraveyard::GameApp::prepare() {
  psyqo::GPU::Configuration config;
  config.set(psyqo::GPU::Resolution::W320)
      .set(psyqo::GPU::VideoMode::AUTO)
      .set(psyqo::GPU::ColorMode::C15BITS)
      .set(psyqo::GPU::Interlace::PROGRESSIVE);
  gpu().initialize(config);
  cdrom.prepare();
}

void HauntedGraveyard::GameApp::createScene() {
  if (!initialized) {
    HauntedGraveyard::GameApp::font.uploadSystemFont(gpu());
    HauntedGraveyard::GameApp::input.initialize();
    HauntedGraveyard::graphics::UI::RenderUI::init(&gpu(), &HauntedGraveyard::GameApp::font);
    HauntedGraveyard::graphics::Render2D::init(&gpu());
    initialized = true;
  }

#if (BUILD == Debug)
  pushScene(&debug_scene);
#else
  pushScene(&first_scene);
#endif
}
