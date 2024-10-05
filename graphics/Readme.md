# Class Diagram

```mermaid
classDiagram
  class Spatial2D {
    +Vec2 position
  }
  Spatial2D <|-- Camera2D
  Spatial2D <|-- Visual2D
  class Camera2D {
    +Vertex size
  }
  class Visual2D {
    +TexturePage texture_page
    +int z_order
  }
  Visual2D *-- TexturePage
  Visual2D <|-- Sprite
  Visual2D <|-- TileMap
  class Sprite {
    +UVCoords uv
    -SimpleFragment~SpriteBlock~ fragment
    +modulate_color(color)
  }
  class TileMap {
    +Vertex size
    -TileMapFragment fragment
  }
  class TexturePage {
    +int col
    +int row
    +get_VRAM_position() Vertex
  }
  class Render2D {
    +init(gpu)
    +set_camera(camera)
    +draw_sprite(sprite)
    +draw_tilemap(tilemap)
  }
  Render2D ..> Camera2D
  Render2D ..> Sprite
  Render2D ..> TileMap
```
