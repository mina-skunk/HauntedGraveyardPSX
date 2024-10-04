#include "graphics/UI/RenderUI.hh"
#include "psyqo/primitives/common.hh"
#include "SplashScene.hh"
#include "GameApp.hh"

void HauntedGraveyard::SplashScene::start(Scene::StartReason reason) {

    // send logo tex to vram
    psyqo::Vertex logo_tex_region_pos = logo.texture_page.get_VRAM_position();
    psyqo::Rect logo_tex_region = {.pos = logo_tex_region_pos, .size = {{.w = splash_tex_WIDTH, .h = splash_tex_HEIGHT}}};
    gpu().uploadToVRAM(splash_tex, logo_tex_region);

    // setup input
    HauntedGraveyard::GameApp::input.setOnEvent([this](const psyqo::SimplePad::Event& event) {
        // skip
        if (event.type == psyqo::SimplePad::Event::ButtonPressed && event.button == psyqo::SimplePad::Triangle) {
            pushScene(&next_scene);
        }
    });
}

void HauntedGraveyard::SplashScene::frame() {
    // There is only UI on the scene so we chain the background directly in the scene
    gpu().getNextClear(background_fragments[gpu().getParity()].primitive, background_color);
    gpu().chain(background_fragments[gpu().getParity()]);

    if (frame_counter < 0x80) {
        logo.modulate_color(psyqo::Color{{.r = frame_counter, .g = frame_counter, .b = frame_counter}});
    } else {
        logo.modulate_color(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});
    }
    frame_counter ++;
    if (frame_counter >= 0xFF) {
        pushScene(&next_scene);
    }
    
    // draw logo
    HauntedGraveyard::graphics::UI::RenderUI::draw_image(&logo);
}

void HauntedGraveyard::SplashScene::teardown(Scene::TearDownReason reason) {
    // clear input
    HauntedGraveyard::GameApp::input.setOnEvent(nullptr);
}
