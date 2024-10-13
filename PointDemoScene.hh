#pragma once

#include <EASTL/vector.h>

#include "core/Point.hh"
#include "graphics/Camera2D.hh"
#include "graphics/Pixel.hh"
#include "graphics/UI/Label.hh"
#include "psyqo/fixed-point.hh"
#include "psyqo/primitives.hh"
#include "psyqo/scene.hh"
#include "psyqo/vector.hh"
#include "system/Sound.hh"

using namespace psyqo::fixed_point_literals;

class Particle : public HauntedGraveyard::core::Point2D {
public:
  psyqo::Vector<2> velocity;
  psyqo::Color color;
  Particle(psyqo::Vector<2> position, psyqo::Vector<2> velocity, psyqo::Color color) : HauntedGraveyard::core::Point2D(position), velocity(velocity), color(color) {
    pixel.position = position;
  }
  void update() override;
  void draw();

private:
  HauntedGraveyard::graphics::Pixel pixel = {position, color};
};

class PointDemoScene final : public psyqo::Scene {
  void start(Scene::StartReason reason) override;
  void frame() override;
  void teardown(Scene::TearDownReason reason) override;

private:
  HauntedGraveyard::graphics::Camera2D camera = {{.x = 0.0_fp, .y = 0.0_fp}};
  psyqo::Color background_color = {0x00, 0x00, 0x00};
  eastl::vector<Particle> particles;
  HauntedGraveyard::graphics::UI::Label info_text1 = {{8, 8}, "Press X to add particle"};
  HauntedGraveyard::graphics::UI::Label info_text2 = {{8, 24}, "Press O to remove particle"};
  HauntedGraveyard::graphics::UI::Label info_text3 = {{8, 40}, "Particles: 0"};
  HauntedGraveyard::system::VoiceFlags voice1 = 1;
  void add_particle();
  void remove_particle();
};
