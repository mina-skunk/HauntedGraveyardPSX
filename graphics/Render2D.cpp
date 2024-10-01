#include "Render2D.hh"
#include "Camera2D.hh"
#include "Sprite.hh"
#include "TileMap.hh"

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

  uint8_t map_index = 0;
  for (uint8_t y = 0; y < tilemap->size.h; y++) {
    for (uint8_t x = 0; x < tilemap->size.w; x++) {
      tilemap->fragment.primitives[map_index].setColor({ .r = 0x80, .g = 0x80, .b = 0x80 });
      // TODO
    }
  }
  
  gpu->sendFragment(tilemap->fragment);
}

psyqo::Vec2 HauntedGraveyard::graphics::Render2D::get_relative_position(psyqo::Vec2 world_space_position) {
  return world_space_position - active_camera->position;
}
