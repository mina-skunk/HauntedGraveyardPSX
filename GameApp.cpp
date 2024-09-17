#include "GameApp.hh"

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
        font.uploadSystemFont(gpu());
        input.initialize();
        initialized = true;
    }

    first_scene.font = &font;
    first_scene.input = &input;
    pushScene(&first_scene);
}
