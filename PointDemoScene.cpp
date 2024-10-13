#include "PointDemoScene.hh"

#include <EASTL/fixed_string.h>

#include "GameApp.hh"
#include "graphics/Render2D.hh"
#include "graphics/UI/RenderUI.hh"
#include "psyqo/xprintf.h"
#include "system/Sound.hh"

void Particle::update() {
  pixel.position = position;
}

void Particle::draw() {
  HauntedGraveyard::graphics::Render2D::draw_pixel(&pixel);
}

void PointDemoScene::start(Scene::StartReason reason) {
  // setup input
  HauntedGraveyard::GameApp::input.setOnEvent([this](const psyqo::SimplePad::Event &event) {
    // skip
    if (event.type == psyqo::SimplePad::Event::ButtonPressed) {
      if (event.button == psyqo::SimplePad::Cross) {
        add_particle();HauntedGraveyard::system::Sound::set_control(SPU_ENABLE | SPU_UNMUTE | SPU_ENABLE_CD | HauntedGraveyard::system::Sound::NoiseFrequencyStep::SIX << 8);
        HauntedGraveyard::system::Sound::update_control(0xa << 10);
      } else if (event.button == psyqo::SimplePad::Circle) {
        remove_particle();HauntedGraveyard::system::Sound::set_control(SPU_ENABLE | SPU_UNMUTE | SPU_ENABLE_CD | HauntedGraveyard::system::Sound::NoiseFrequencyStep::SIX << 8);
        HauntedGraveyard::system::Sound::update_control(0x8 << 10);
      } else if (event.button == psyqo::SimplePad::Triangle) {
        HauntedGraveyard::system::Sound::key_on(voice1);
      }
    } else if (event.type == psyqo::SimplePad::Event::ButtonReleased) {
      if (event.button == psyqo::SimplePad::Triangle) {
        HauntedGraveyard::system::Sound::key_off(voice1);
      }
    }
  });

  HauntedGraveyard::graphics::Render2D::set_camera(&camera);

  // init Sound
  HauntedGraveyard::system::Sound::set_control(SPU_ENABLE | SPU_UNMUTE | SPU_ENABLE_CD | HauntedGraveyard::system::Sound::NoiseFrequencyStep::SIX << 8);
  HauntedGraveyard::system::Sound::set_volume(MAX_VOLUME);
  HauntedGraveyard::system::Sound::set_cd_volume(MAX_VOLUME);
  HauntedGraveyard::system::Sound::set_voice_volume(0, MAX_VOLUME);
  HauntedGraveyard::system::Sound::noise_enable(voice1);
}

void PointDemoScene::frame() {
  // update
  for (auto &particle : particles) {
    particle.update();
  }
  // count string
  eastl::fixed_string<char, 20> info_text3_string;
  fsprintf(info_text3_string, "Particles: %d", particles.size());
  info_text3.text = info_text3_string;
  // draw
  HauntedGraveyard::graphics::Render2D::draw_background(background_color);
  for (auto &particle : particles) {
    particle.draw();
  }
  HauntedGraveyard::graphics::UI::RenderUI::draw_label(&info_text1);
  HauntedGraveyard::graphics::UI::RenderUI::draw_label(&info_text2);
  HauntedGraveyard::graphics::UI::RenderUI::draw_label(&info_text3);
}

void PointDemoScene::teardown(Scene::TearDownReason reason) {
  // clear input
  HauntedGraveyard::GameApp::input.setOnEvent(nullptr);
}

void PointDemoScene::add_particle() {
  particles.push_back({{.x = 64.0_fp, .y = 64.0_fp}, {.x = 0.0_fp, .y = 0.0_fp}, {0xff, 0x00, 0x00}});
}

void PointDemoScene::remove_particle() {
  if (particles.size() > 0) {
    particles.pop_back();
  }
}
