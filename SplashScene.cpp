#include "psyqo/primitives/common.hh"
#include "SplashScene.hh"
#include "splash.h"

void HauntedGraveyard::SplashScene::start(Scene::StartReason reason) {
    psyqo::Rect region = {.pos = {{.x = 512, .y = 0}}, .size = {{.w = splash_tex_WIDTH, .h = splash_tex_HEIGHT}}};
    gpu().uploadToVRAM(splash_tex, region);

    logo_tex_page.attr.setPageX(8).setPageY(0).set(psyqo::Prim::TPageAttr::Tex16Bits);

    // logo_sprite.setColor(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});
    logo_sprite.position = {{.x = 32, .y = 56}};
    logo_sprite.size = {{.w = splash_tex_WIDTH, .h = splash_tex_HEIGHT}};
    logo_sprite.texInfo = { .u = 0, .v = 0 };

    // setup input
    input->setOnEvent([this](const psyqo::SimplePad::Event& event) {
        // skip
        if (event.type == psyqo::SimplePad::Event::ButtonPressed && event.button == psyqo::SimplePad::Triangle) {
            to_next_scene();
        }
    });
}

void HauntedGraveyard::SplashScene::frame() {
    // It is time to render the texture. We are going to clear the screen first.
    gpu().clear({{ .r=0x23, .g=0x26, .b=0x34 }});

    if (frame_counter < 0x80) {
        logo_sprite.setColor(psyqo::Color{{.r = frame_counter, .g = frame_counter, .b = frame_counter}});
    } else {
        logo_sprite.setColor(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});
    }
    frame_counter ++;
    if (frame_counter >= 0xFF) {
        to_next_scene();
    }
    

    // font->print(gpu(), "hello", {{.x = 16, .y = 32}}, {{.r=255, .g=255, .b=255}});
    gpu().sendPrimitive(logo_tex_page);
    // Finally, we can send the sprite to the GPU.
    gpu().sendPrimitive(logo_sprite);
}

void HauntedGraveyard::SplashScene::teardown(Scene::TearDownReason reason) {
    // clear input
    input->setOnEvent(nullptr);
}

void HauntedGraveyard::SplashScene::to_next_scene() {
    next_scene.font = font;
    next_scene.input = input;
    pushScene(&next_scene);
}
