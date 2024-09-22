#include "graphics/UI/RenderUI.hh"
#include "GameApp.hh"

psyqo::Font<> HauntedGraveyard::GameApp::font;

psyqo::SimplePad HauntedGraveyard::GameApp::input;

void HauntedGraveyard::GameApp::prepare() {
    psyqo::GPU::Configuration config;
    config.set(psyqo::GPU::Resolution::W320)
        .set(psyqo::GPU::VideoMode::AUTO)
        .set(psyqo::GPU::ColorMode::C15BITS)
        .set(psyqo::GPU::Interlace::PROGRESSIVE);
    gpu().initialize(config);
}

void HauntedGraveyard::GameApp::createScene() {
    if (!initialized) {
        HauntedGraveyard::GameApp::font.uploadSystemFont(gpu());
        HauntedGraveyard::GameApp::input.initialize();
        HauntedGraveyard::graphics::UI::RenderUI::init(&gpu(), &HauntedGraveyard::GameApp::font);
        initialized = true;
    }

#if(BUILD == Debug)
    pushScene(&debug_scene);
#else
    pushScene(&first_scene);
#endif
}
