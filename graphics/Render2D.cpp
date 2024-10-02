#include "Render2D.hh"
#include "Camera2D.hh"
#include "Sprite.hh"
#include "TileMap.hh"
#include "psyqo/primitives/common.hh"
#include <cstdint>

psyqo::GPU* HauntedGraveyard::graphics::Render2D::gpu;
HauntedGraveyard::graphics::Camera2D* HauntedGraveyard::graphics::Render2D::active_camera;

void HauntedGraveyard::graphics::Render2D::init(psyqo::GPU *gpu_) {
  HauntedGraveyard::graphics::Render2D::gpu = gpu_;
}

void HauntedGraveyard::graphics::Render2D::set_camera(HauntedGraveyard::graphics::Camera2D *camera) {
  active_camera = camera;
}

void HauntedGraveyard::graphics::Render2D::draw_sprite(HauntedGraveyard::graphics::Sprite *sprite) {
  // set tex page
  psyqo::Prim::TPage sprite_tex_page;
  // sprite_tex_page.attr.setPageX(sprite->texture_page.col).setPageY(sprite->texture_page.row).set(psyqo::Prim::TPageAttr::Tex16Bits);
  sprite->texture_page.get_primative(&sprite_tex_page);
  gpu->sendPrimitive(sprite_tex_page);

  // tex
  sprite->get_primitive();
  psyqo::Vec2 camera_space_position = get_relative_position(sprite->position);
  sprite->primitive.position.x = camera_space_position.x.integer();
  sprite->primitive.position.y = camera_space_position.y.integer();
  gpu->sendPrimitive(sprite->primitive);
}

void HauntedGraveyard::graphics::Render2D::draw_tilemap(HauntedGraveyard::graphics::TileMap *tilemap) {
  // set tex page
  psyqo::Prim::TPage tilemap_tex_page;
  // tilemap_tex_page.attr.setPageX(tilemap->texture_page.col).setPageY(tilemap->texture_page.row).set(psyqo::Prim::TPageAttr::Tex16Bits);
  tilemap->texture_page.get_primative(&tilemap_tex_page);
  gpu->sendPrimitive(tilemap_tex_page);

  tilemap->get_fragment();

  psyqo::Vec2 camera_space_position = get_relative_position(tilemap->position);
  psyqo::Vertex map_pixel_position;
  map_pixel_position.x = camera_space_position.x.integer();
  map_pixel_position.y = camera_space_position.y.integer();

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
      if (tile_position.x < -16 || tile_position.x > 320  || tile_position.y < -16  || tile_position.y > 240 ) {
        in_bounds = false;
      }

      uint16_t tile_set_index = tilemap->data[map_index];

      if (tile_set_index > 0 && in_bounds) {
        tile_set_index--;

        // set position
        tilemap->fragment.primitives[primitive_index].position.x = tile_position.x;
        tilemap->fragment.primitives[primitive_index].position.y = tile_position.y;
        
        tilemap->fragment.primitives[primitive_index].setColor({ .r = 0x80, .g = 0x80, .b = 0x80 });

        // UV
        if (tile_set_index < TILE_SET_WIDTH) {
          tilemap->fragment.primitives[primitive_index].texInfo.u = tile_set_index * 16;
          tilemap->fragment.primitives[primitive_index].texInfo.v = 0;
        } else {
          tilemap->fragment.primitives[primitive_index].texInfo.u = (tile_set_index % TILE_SET_WIDTH) * 16;
          tilemap->fragment.primitives[primitive_index].texInfo.v = (tile_set_index / TILE_SET_WIDTH) * 16;
        }

        primitive_index++;
      }

      map_index++;
    }
  }
  tilemap->fragment.count = primitive_index + 1;
  
  gpu->sendFragment(tilemap->fragment);
}

psyqo::Vec2 HauntedGraveyard::graphics::Render2D::get_relative_position(psyqo::Vec2 world_space_position) {
  return world_space_position - active_camera->position;
}
