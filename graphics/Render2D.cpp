#include "Render2D.hh"

#include "Camera2D.hh"
#include "Sprite.hh"
#include "TileMap.hh"
#include "psyqo/primitives/common.hh"

psyqo::GPU *HauntedGraveyard::graphics::Render2D::gpu;
HauntedGraveyard::graphics::Camera2D *HauntedGraveyard::graphics::Render2D::active_camera;
psyqo::OrderingTable<8> HauntedGraveyard::graphics::Render2D::ordering_tables[2];
psyqo::Fragments::SimpleFragment<psyqo::Prim::FastFill> HauntedGraveyard::graphics::Render2D::background_fragments[2];

void HauntedGraveyard::graphics::Render2D::init(psyqo::GPU *gpu_) {
  HauntedGraveyard::graphics::Render2D::gpu = gpu_;
}

void HauntedGraveyard::graphics::Render2D::set_camera(HauntedGraveyard::graphics::Camera2D *camera) {
  active_camera = camera;
}

void HauntedGraveyard::graphics::Render2D::draw_sprite(HauntedGraveyard::graphics::Sprite *sprite) {
  psyqo::Vec2 camera_space_position = get_relative_position(sprite->position);
  auto fragment = sprite->get_fragment(gpu->getParity());
  fragment->primitive.sprite.position.x = camera_space_position.x.integer();
  fragment->primitive.sprite.position.y = camera_space_position.y.integer();
  ordering_tables[gpu->getParity()].insert(*fragment, sprite->z_order);
  // gpu->chain(*fragment);
}

void HauntedGraveyard::graphics::Render2D::draw_tilemap(HauntedGraveyard::graphics::TileMap *tilemap) {
  psyqo::Vec2 camera_space_position = get_relative_position(tilemap->position);
  psyqo::Vertex map_pixel_position;
  map_pixel_position.x = camera_space_position.x.integer();
  map_pixel_position.y = camera_space_position.y.integer();

  auto sprite_fragment_buffer = tilemap->sprite_fragments[gpu->getParity()];

  uint16_t map_index = 0;
  uint16_t primitive_index = 0;
  for (uint8_t y = 0; y < tilemap->size.h; y++) {
    for (uint8_t x = 0; x < tilemap->size.w; x++) {
      // calc position
      psyqo::Vertex tile_position;
      tile_position.x = map_pixel_position.x + (x * 16);
      tile_position.y = map_pixel_position.y + (y * 16);
      // cull
      bool in_bounds = true;
      if (tile_position.x < -16 || tile_position.x > 320 || tile_position.y < -16 || tile_position.y > 240) {
        in_bounds = false;
      }

      uint16_t tile_set_index = tilemap->data[map_index];

      if (tile_set_index > 0 && in_bounds) {
        tile_set_index--;

        // set position
        sprite_fragment_buffer[primitive_index].primitive.sprite.position.x = tile_position.x;
        sprite_fragment_buffer[primitive_index].primitive.sprite.position.y = tile_position.y;

        // UV
        if (tile_set_index < TILE_SET_WIDTH) {
          sprite_fragment_buffer[primitive_index].primitive.sprite.texInfo.u = tile_set_index * 16;
          sprite_fragment_buffer[primitive_index].primitive.sprite.texInfo.v = 0;
        } else {
          sprite_fragment_buffer[primitive_index].primitive.sprite.texInfo.u = (tile_set_index % TILE_SET_WIDTH) * 16;
          sprite_fragment_buffer[primitive_index].primitive.sprite.texInfo.v = (tile_set_index / TILE_SET_WIDTH) * 16;
        }

        ordering_tables[gpu->getParity()].insert(sprite_fragment_buffer[primitive_index], tilemap->z_order);
        // gpu->chain(sprite_fragment_buffer[primitive_index]);

        primitive_index++;
      }

      map_index++;
    }
  }
}

void HauntedGraveyard::graphics::Render2D::draw_background(psyqo::Color color) {
  gpu->getNextClear(background_fragments[gpu->getParity()].primitive, color);
  ordering_tables[gpu->getParity()].insert(background_fragments[gpu->getParity()], MAX_Z);
  // gpu->chain(background_fragments[gpu->getParity()]);
}

psyqo::Vec2 HauntedGraveyard::graphics::Render2D::get_relative_position(psyqo::Vec2 world_space_position) {
  return world_space_position - active_camera->position;
}

void HauntedGraveyard::graphics::Render2D::finish_drawing() {
  gpu->chain(ordering_tables[gpu->getParity()]);
}
